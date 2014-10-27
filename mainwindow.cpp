#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Setup of all variables
    MainWindow::polarizerSettings.resize(3);
    SCThread = new QThread;
    MainWindow::currentScanNumber = 0;
    MainWindow::setContextMenuPolicy(Qt::CustomContextMenu);
    MainWindow::setWindowTitle("");
    MainWindow::newDPC = new DPC;
    MainWindow::newSpectrometer = new Spectrometer;
    MainWindow::loadConfig();
    MainWindow::newSpecControl = new Spec_Control(newSpectrometer->getMonoPos());
    MainWindow::newScanner = new scanner;

    //Create Menus
    createActions();
    createMenus();

    //Setting ui settings
    ui->loadGenericButton->setToolTip(tr("Load scan from a file"));
    //ui->saveButton->setToolTip(tr("Save scan to a file"));
    ui->scanButton->setToolTip("Start scan");
    ui->horizontalLayout_2->setStretchFactor(ui->qwtPlot, 19);
    ui->horizontalLayout_2->setStretchFactor(ui->formLayout_2, 1);

    ui->activateCounter->hide();
    ui->countNumber->setReadOnly(true);
    ui->LastScan->hide();
    ui->NextScan->hide();
    ui->ChooseScanLabel->hide();
    ui->selectScanBox->hide();
    ui->selectScanLabel->hide();
    ui->progressBar->hide();
    ui->progressBar->setValue(0);
    ui->scanButton->hide();
    ui->newScan->show();
    ui->stopScan->hide();
    ui->gridTabWidget->setCurrentIndex(0);

    ui->currentPosition->setReadOnly(true);
    ui->currentSpeed->setReadOnly(true);
    ui->currentWaveNumber->setReadOnly(true);
    ui->photoCounter->setReadOnly(true);
    ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    ui->currentSpeed->setText(QString::number(newSpectrometer->getMonoSpeed()));

    //Some fancy stuff for style
    QString myStyleSheet = QString("QProgressBar{ border: 2px solid black; border-radius: 5px; text-align: center} QProgressBar::chunk { background: green; width: 10px; margin: 0.5px}");
    QString s = ui->progressBar->styleSheet().append(myStyleSheet);
    ui->progressBar->setStyleSheet(s);

    //Creating connections
    //connect(SCThread, SIGNAL(finished()), newSpecControl, SLOT(deleteLater()));
    //connect(SCThread, SIGNAL(terminated()), newSpecControl, SLOT(deleteLater()));
    connect(this, SIGNAL(xPolarizerMoved(Polarizer, bool)), newSpecControl, SLOT(movePolarizer(Polarizer, bool)));
    connect(this, SIGNAL(yPolarizerMoved(Polarizer, bool)), newSpecControl, SLOT(movePolarizer(Polarizer,bool)));
    connect(this, SIGNAL(zPolarizerMoved(Polarizer,bool)), newSpecControl, SLOT(movePolarizer(Polarizer,bool)));
    connect(this, SIGNAL(MoveStepUp(qreal, qreal, bool)), newSpecControl, SLOT(moveStepMotor(qreal, qreal, bool)));
    connect(this, SIGNAL(MoveStepDown(qreal, qreal, bool)), newSpecControl, SLOT(moveStepMotor(qreal, qreal, bool)));
    connect(this, SIGNAL(stopControlling(void)), newSpecControl, SLOT(stopControl(void)));
    connect(this, SIGNAL(stopCounting(void)), newDPC, SLOT(cancelThread(void)));
    connect(this, SIGNAL(stopScan()), newScanner, SLOT(cancelScan()));
    connect(this, SIGNAL(startScan()), newScanner, SLOT(runScan()));
    connect(this, SIGNAL(killScanner()), newScanner, SLOT(stopScanner()));
    connect(this, SIGNAL(initScanner(qreal,qreal,qreal,qreal,bool)), newScanner, SLOT(init(qreal,qreal,qreal,qreal,bool)));
    connect(newDPC, SIGNAL(currentCount(int)), SLOT(oncurrentCount(int)));
    connect(newDPC, SIGNAL(finished()), newDPC, SLOT(deleteLater()));
    connect(newSpecControl, SIGNAL(movedStepper(qreal)), newSpectrometer, SLOT(setMonoPosSlot(qreal)));
    connect(newSpecControl, SIGNAL(movedPolarizer(Polarizer,bool)), newSpectrometer, SLOT(setPolarizersSlot(Polarizer,bool)));
    connect(newSpecControl, SIGNAL(movedStepper(qreal)), newSpectrometer, SLOT(setMonoPosSlot(qreal)));
    connect(newSpecControl, SIGNAL(finished()), newSpecControl, SLOT(deleteLater()));
    connect(newScanner, SIGNAL(currentStatus(qreal)), SLOT(CurrentScanStatus(qreal)));
    connect(newScanner, SIGNAL(finished()), newScanner, SLOT(deleteLater()));
    //connect(newScanner, SIGNAL(finished()), this, SLOT(closeProgressBar()));
    connect(newScanner, SIGNAL(scanFinished()), this, SLOT(scanIsFinished()));
    connect(newScanner, SIGNAL(currentValue(qreal,qreal)), this, SLOT(addNewValue(qreal,qreal)));
    connect(newScanner, SIGNAL(moveStepUp(void)), MainWindow::newSpecControl, SLOT(moveUp()));
    connect(newScanner, SIGNAL(moveStepDown(void)), MainWindow::newSpecControl, SLOT(moveDown()));
    connect(newScanner, SIGNAL(moveToPosition(qreal,qreal,bool)), newSpecControl, SLOT(moveStepMotor(qreal,qreal,bool)));
    connect(newScanner, SIGNAL(scanInterrupted()), this, SLOT(scanIsInterrupted()));


    //Thread work
//    newSpecControl->moveToThread(SCThread);
    //set current state:
    changeState(EditState);
    //Running subthreads
//    SCThread->start();
    newSpecControl->start();
    newDPC->start();
    newScanner->start();
}

MainWindow::~MainWindow()
{
    MainWindow::writeConfig();
    emit stopCounting();
    emit stopControlling();
    emit killScanner();
    newSpecControl->wait(5000);
    newDPC->wait(500);
    newScanner->wait(500);
    //MainWindow::SCThread->wait(500);
    //qDebug() << "Is DPC still counting: " << newDPC->isRunning();
    //qDebug() << "Is ControlThread still running?" << newSpecControl->isRunning();
    //qDebug() << "Is scanner still running?" << newScanner->isRunning();
    delete MainWindow::SCThread;
    delete MainWindow::newDPC;
    delete MainWindow::newSpecControl;
    delete MainWindow::newSpectrometer;
    delete MainWindow::newScanner;
    delete ui;
}

void MainWindow::on_loadGenericButton_clicked()
{
    MainWindow::openGeneric();
}

void MainWindow::replot()
{
    MainWindow::Grid.attach(ui->qwtPlot);
    MainWindow::Curve.attach(NULL);
    MainWindow::Curve.setTitle("Raman spectra");
    MainWindow::Curve.setRenderHint(QwtPlotItem::RenderAntialiased, true);

    MainWindow::pen.setStyle(Qt::SolidLine);
    MainWindow::pen.setWidth(3);
    MainWindow::pen.setBrush(Qt::red);
    MainWindow::pen.setCapStyle(Qt::RoundCap);
    MainWindow::pen.setJoinStyle(Qt::RoundJoin);

    MainWindow::Curve.setPen(MainWindow::pen);

    QVector<double> x, y;
    MainWindow::Scandata.clear();
    vectorToMap(newScanList.getCurrentScan().values.Data/*currentScan.values.Data*/, MainWindow::Scandata);
    x = QVector<double>::fromList(Scandata.keys());
    y = QVector<double>::fromList(Scandata.values());

    MainWindow::Curve.setSamples(x, y);
    MainWindow::Curve.attach(ui->qwtPlot);
    ui->qwtPlot->updateAxes();
    ui->qwtPlot->show();
    ui->qwtPlot->replot();
    MainWindow::reload_data();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scan file"), "", tr("Scan file (*.sca);;All Files(*)")); //Eventuell auf mehrere Files erweitern, damit man mehrere Scans gleichzeitig laden kann
    if(fileName.isEmpty())
        return;
    else
    {
        struct Scan newScan;
        QFile file(fileName);
        int monoSetting;
        qreal startScan, finScan, scanSpeed;
        QString scanName;
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }
        QDataStream in(&file);
        quint32 magic;
        in >> magic;
        if(magic != 0x8008135 || magic != 0x80081E5)
        {
            QMessageBox::information(this, tr("Wrong file format!"),"Sorry, wrong file format! Please try to open it with \"Load old Data\"!");
            return;
        }
        qint32 version;
        in >> version;
        if(version < 100)
        {
            QMessageBox::information(this, tr("Wrong file format!"),"Sorry, file is too old! Please try to open it with \"Load old Data\"!");
            return;
        }
        if(version <= 110)
            in.setVersion(QDataStream::Qt_3_3);
        else
            in.setVersion(QDataStream::Qt_4_5);
        newScan.values.Data.empty();
        in >> scanName;
        in >> monoSetting;
        in >> startScan;
        in >> finScan;
        in >> scanSpeed;
        in >> newScan.values.Data;
        if(magic == 0x80081E5)
        {
            in >> newScan.log.countNumber;
            in >> newScan.log.laserIntensity;
            in >> newScan.log.name;
            in >> newScan.log.sensitivity;
            in >> newScan.log.slitWidth;
        }
        newScan.scanName = scanName;
        newScan.Params.finPos = finScan;
        newScan.Params.startPos = startScan;
        newScan.Params.scanSpeed = scanSpeed;
        newScan.Params.polSettings.push_back((bool)(monoSetting%2 == 1));
        newScan.Params.polSettings.push_back((bool)(monoSetting%2 == 0 && monoSetting != 4));
        newScan.Params.polSettings.push_back((bool)(monoSetting >= 4));
        newScan.readonly = true;
        if(newScan.values.Data.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
            return;
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            MainWindow::newScanList.addScan(newScan);
            MainWindow::newScanList.addFileName(fileName);
            if(MainWindow::newScanList.getScanNumbers() > 1)
            {
                ui->LastScan->show();
                ui->NextScan->show();
                ui->ChooseScanLabel->show();
                ui->selectScanLabel->show();
                ui->selectScanBox->show();
            }
            ui->selectScanBox->addItem(newScanList.getCurrentScan().scanName);
            //QMessageBox::information(this, tr("Info"),QString::number(currentScanNumber) + " " + QString::number(newScanList.Scans.size()));
            MainWindow::replot();
        }
    }
}

void MainWindow::openGeneric()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scan file"), "", tr("All Files(*)")); //Eventuell auf mehrere Files erweitern, damit man mehrere Scans gleichzeitig laden kann
    if(fileName.isEmpty())
        return;
    else
    {
        struct Scan newScan;
        MainWindow::Scandata.clear();
        newScan.readonly = true;
        newScan.Params.polSettings[0] = false;
        newScan.Params.polSettings[1] = false;
        newScan.Params.polSettings[2] = false;
        newScan.av = NoAverage;
        newScan.Params.finPos = -1;
        newScan.scanName = fileName;
        newScan.Params.scanSpeed = -1;
        newScan.Params.startPos = -1;
        read_unformatted_file(newScan, fileName);
        //Generische Daten werden eingegeben, müssen später mit richtigen Werten ersetzt werden

        if(newScan.values.Data.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            MainWindow::newScanList.addScan(newScan);
            MainWindow::newScanList.addFileName(fileName);
            if(MainWindow::newScanList.getScanNumbers() > 1)
            {
                ui->LastScan->show();
                ui->NextScan->show();
                ui->ChooseScanLabel->show();
                ui->selectScanLabel->show();
                ui->selectScanBox->show();
            }
            ui->selectScanBox->addItem(newScanList.getCurrentScan().scanName);
            MainWindow::setWindowTitle(fileName);
            if(newScan.Params.finPos != -1 && newScan.Params.scanSpeed != -1 && newScan.Params.startPos != -1)
            {
                ui->setStartPosition->setText(QString::number(newScan.Params.startPos));
                ui->setTargetPosition->setText(QString::number(newScan.Params.finPos));
                ui->setScanSpeed->setText(QString::number(newScan.Params.scanSpeed));
                ui->dispXValue->setChecked(newScan.Params.polSettings[0]);
                ui->dispYValue->setChecked(newScan.Params.polSettings[1]);
                ui->dispZValue->setChecked(newScan.Params.polSettings[2]);
            }
            MainWindow::replot();
        }
    }
}

void MainWindow::save()
{
    if(newScanList.getScanNumbers() == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Sorry, no data loaded!"));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan file (*.sca);;All Files(*)"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QDataStream out(&file);
        out << (quint32)0x80081E5;
        out << (qint32)123;
        out.setVersion(QDataStream::Qt_4_5);//Hier muss noch Portabilität eingebaut werden, siehe auch http://qt-project.org/doc/qt-4.8/qdatastream.html
        if(MainWindow::newScanList.getScanNumbers()!=0)
        {
            out << MainWindow::newScanList.getCurrentScan().scanName;
            qint32 monoSetting = (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[0]) + (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[1])*2 + (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[2])*4;
            out << monoSetting;
            out << MainWindow::newScanList.getCurrentScan().Params.startPos;
            out << MainWindow::newScanList.getCurrentScan().Params.finPos;
            out << MainWindow::newScanList.getCurrentScan().Params.scanSpeed;
            out << MainWindow::newScanList.getCurrentScan().values.Data;
            out << MainWindow::newScanList.getCurrentScan().log.countNumber;
            out << MainWindow::newScanList.getCurrentScan().log.laserIntensity;
            out << MainWindow::newScanList.getCurrentScan().log.name;
            out << MainWindow::newScanList.getCurrentScan().log.sensitivity;
            out << MainWindow::newScanList.getCurrentScan().log.slitWidth;
        }
        else
            QMessageBox::information(this, tr("No scan data"),tr("No scan opened!"));
    }
}

void MainWindow::saveGeneric()
{

    if(newScanList.getScanNumbers() == 0)
    {
        QMessageBox::information(this,tr("Error!"), tr("No data loaded!"));
        return;
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan file (old)(*.txt);;All Files(*)"));
        if(fileName.isEmpty())
        {
            return;
        }
        else
        {
            bool saveLogFile = false;
            QMessageBox msgBox;
            msgBox.setText("Save Logfile?");
            msgBox.setInformativeText("Do you want to save an additional logfile, too? All log data will be saved in the spectrum file, too.");
            QPushButton *save = msgBox.addButton(tr("Save additional logfile"), QMessageBox::ActionRole);
            QPushButton *notsave = msgBox.addButton(tr("Don't save additional file"), QMessageBox::ActionRole);
            msgBox.exec();
            if(msgBox.clickedButton() == save)
                saveLogFile = true;
            else
                if(msgBox.clickedButton() == notsave)
                    saveLogFile = false;
            if(ui->scanName->text() == "")
                newScanList.getCurrentScan().scanName = fileName;
            else
                newScanList.getCurrentScan().scanName = ui->scanName->text();
            if(ui->setScanSpeed->text() != "")
                newScanList.getCurrentScan().Params.scanSpeed = ui->setScanSpeed->text().toDouble();
            if(ui->setStartPosition->text() != "")
                newScanList.getCurrentScan().Params.startPos = ui->setStartPosition->text().toDouble();
            if(ui->setTargetPosition->text() != "")
                newScanList.getCurrentScan().Params.finPos = ui->setTargetPosition->text().toDouble();
            write_unformatted_file(newScanList.getCurrentScan()/*MainWindow::Scandata*/, fileName);
            if(saveLogFile)
                write_log_file(newScanList.getCurrentScan(), fileName);
        }
    }
}

void MainWindow::saveGenericAllPlots()
{
    if(newScanList.getScanNumbers() == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Sorry, no data loaded!"));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan file (old)(*.txt);;All Files(*)"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
        for(int i = 0; i < newScanList.getScanNumbers(); i++)
        {
            write_unformatted_file(newScanList.getScan(i), fileName + QString::number(i+1));
        }
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load a file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    openGenericAct = new QAction(tr("&Open old file"), this);
    openGenericAct->setStatusTip(tr("Load an old file"));
    connect(openGenericAct, SIGNAL(triggered()), this, SLOT(openGeneric()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save a file"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveGenericAct = new QAction(tr("&Save old file"), this);
    saveGenericAct->setStatusTip(tr("Save a file in old style"));
    connect(saveGenericAct, SIGNAL(triggered()), this, SLOT(saveGeneric()));

    saveGenericAll = new QAction(tr("&Save all open plots in old style"), this);
    saveGenericAll->setStatusTip(tr("Save all open plots in old style"));
    connect(saveGenericAll, SIGNAL(triggered()), this, SLOT(saveGenericAllPlots()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(openGenericAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveGenericAct);
    fileMenu->addAction(saveGenericAll);
}

void MainWindow::on_dispXValue_toggled(bool checked)
{
    newSpectrometer->setPolarizers(xPol, checked);
    emit xPolarizerMoved(xPol, checked);
}

void MainWindow::on_dispYValue_toggled(bool checked)
{
    newSpectrometer->setPolarizers(yPol, checked);
    emit yPolarizerMoved(yPol, checked);
}

void MainWindow::on_dispZValue_toggled(bool checked)
{
    newSpectrometer->setPolarizers(zPol, checked);
    emit zPolarizerMoved(zPol, checked);
}

void MainWindow::changeState(State newState)
{
    switch(newState)
    {
        case ScanState:
        {
            ui->gridTabWidget->setTabEnabled(1, false);
            ui->gridTabWidget->setTabEnabled(0, true);
            ui->gridTabWidget->setTabEnabled(2, false);
            ui->loadGenericButton->hide();
            ui->loadSettingsButton->hide();
            ui->dispXValue->setEnabled(0);
            ui->dispYValue->setEnabled(0);
            ui->dispZValue->setEnabled(0);
            ui->setScanSpeed->setReadOnly(false);
            ui->setStartPosition->setReadOnly(false);
            ui->setTargetPosition->setReadOnly(false);
            ui->saveScan->hide();
            ui->scanName->setReadOnly(false);
            ui->scanButton->show();
            ui->stopScan->show();
            ui->newScan->hide();
            break;
        }
        case EditState:
        {
            ui->loadGenericButton->show();
            ui->setScanSpeed->setReadOnly(true);
            ui->setStartPosition->setReadOnly(true);
            ui->setTargetPosition->setReadOnly(true);
            ui->scanName->setReadOnly(true);
            ui->loadSettingsButton->show();
            ui->dispXValue->setEnabled(1);
            ui->dispYValue->setEnabled(1);
            ui->dispZValue->setEnabled(1);
            ui->gridTabWidget->setTabEnabled(1, true);
            ui->gridTabWidget->setTabEnabled(2, true);
            ui->scanButton->hide();
            ui->stopScan->hide();
            ui->saveScan->show();
            ui->newScan->show();
            break;
        }
        case MoveState:
        {
            break;
        }
    }
}

void MainWindow::on_scanButton_clicked()
{
    //qDebug() << "Is Scanner running when I pressed the scan button?" << newScanner->isRunning();
    if(ui->setScanSpeed->text().isEmpty() || ui->setStartPosition->text().isEmpty() || ui->setTargetPosition->text().isEmpty() || ui->scanName->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error!"), tr("Not all neccessary information entered, please check your entered data!"));
        return;
    }
    QMessageBox msgBox;
    //msgBox.setText("Information.");
    msgBox.setInformativeText("Do you want add a config file?");
    QPushButton *yes = msgBox.addButton(tr("&Yes"), QMessageBox::ActionRole);
    QPushButton *no = msgBox.addButton(tr("&No"), QMessageBox::ActionRole);
    msgBox.exec();
    if(msgBox.clickedButton() == yes)
    {
        QDialog logData;
        QFormLayout logDataLayout(&logData);
        QLabel *labelName = new QLabel;
        QLabel *labelPower = new QLabel;
        QLabel *labelSlit = new QLabel;
        QLabel *labelSens = new QLabel;
        QLabel *labelCount = new QLabel;
        QLineEdit *lineName = new QLineEdit;
        QLineEdit *linePower = new QLineEdit;
        QLineEdit *lineSlit = new QLineEdit;
        QLineEdit *lineSens = new QLineEdit;
        QLineEdit *lineCount = new QLineEdit;
        labelName->setText("Logfile Name:");
        labelPower->setText("Power [mW]");
        labelSlit->setText("Slitwidth [mm]:");
        labelSens->setText("Sensitivity [counts/sec]:");
        labelCount->setText("Counts:");
        logDataLayout.addRow(labelName, lineName);
        logDataLayout.addRow(labelPower, linePower);
        logDataLayout.addRow(labelSlit, lineSlit);
        logDataLayout.addRow(labelSens, lineSens);
        logDataLayout.addRow(labelCount, lineCount);
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &logData);
        logDataLayout.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &logData, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &logData, SLOT(reject()));
        if(logData.exec() == QDialog::Accepted)
        {
            tmpScan.log.name = lineName->text();
            tmpScan.log.laserIntensity = linePower->text().toDouble();
            tmpScan.log.sensitivity = lineSens->text().toDouble();
            tmpScan.log.countNumber = lineCount->text().toDouble();
            tmpScan.log.slitWidth = lineSlit->text().toDouble();
            tmpScan.log.logfileSet = true;
        }
        else
        {
            tmpScan.log.logfileSet = false;
        }
    }
    ui->progressBar->show();
    ui->progressBar->setValue(1);
    tmpScan.Params.finPos = ui->setTargetPosition->text().toDouble();
    tmpScan.Params.startPos = ui->setStartPosition->text().toDouble();
    tmpScan.Params.scanSpeed = ui->setScanSpeed->text().toDouble();
    tmpScan.scanName = ui->scanName->text();
    //qDebug() << "Scanner is initialized";
    emit initScanner(tmpScan.Params.startPos, tmpScan.Params.finPos, tmpScan.Params.scanSpeed, newSpectrometer->getMonoPos(), (tmpScan.Params.finPos-tmpScan.Params.startPos)>0?true:false);
    //qDebug() << "Scanner is going to be started!";
    emit startScan();
    //Analyze(MainWindow::newScanList);
}

void MainWindow::closeProgressBar()
{
    ui->progressBar->hide();
}

void MainWindow::scanIsFinished(void)
{
    newScanList.addScan(MainWindow::tmpScan);
    closeProgressBar();
    //qDebug() << "Check if Scanner is still running: " << newScanner->isRunning();
    //qDebug() << "Another check: " << newScanner->isFinished();
//    //newScanner->terminate();
    tmpScan.clear();
    changeState(EditState);

}

void MainWindow::CurrentScanStatus(qreal status)
{
    ui->progressBar->setValue((int)(status));
}

void MainWindow::addNewValue(qreal wNumber, qreal counts)
{
    tmpScan.values.Data.push_back(qMakePair(wNumber, counts));
}

void MainWindow::on_LastScan_clicked()
{
    newScanList.getLastScan();
    MainWindow::setWindowTitle(newScanList.getCurrentScan().scanName);
    ui->selectScanBox->setCurrentIndex(newScanList.getCurrentScanNumber());

    MainWindow::replot();
}

void MainWindow::on_NextScan_clicked()
{
    newScanList.getNextScan();
    MainWindow::setWindowTitle(newScanList.getCurrentScan().scanName);
    ui->selectScanBox->setCurrentIndex(newScanList.getCurrentScanNumber());
    MainWindow::replot();
}

void MainWindow::on_selectScanBox_currentIndexChanged(int index)
{
    newScanList.setCurrentScan(index);
    MainWindow::replot();
}

void MainWindow::on_saveScan_clicked()
{
    saveGeneric();
}

void MainWindow::reload_data()
{
    if(!(newScanList.getScanNumbers() == 0))
    {
        ui->setScanSpeed->setText(QString::number(newScanList.getCurrentScan().Params.scanSpeed));
        ui->setStartPosition->setText(QString::number(newScanList.getCurrentScan().Params.startPos));
        ui->setTargetPosition->setText(QString::number(newScanList.getCurrentScan().Params.finPos));
        ui->dispXValue->setChecked(newScanList.getCurrentScan().Params.polSettings[0]);
        ui->dispYValue->setChecked(newScanList.getCurrentScan().Params.polSettings[1]);
        ui->dispZValue->setChecked(newScanList.getCurrentScan().Params.polSettings[2]);
        ui->scanName->setText(newScanList.getCurrentScan().scanName);
        ui->logfileName->setText(newScanList.getCurrentScan().log.name);
        ui->laserPower->setText(QString::number(newScanList.getCurrentScan().log.laserIntensity));
        ui->slitWidth->setText(QString::number(newScanList.getCurrentScan().log.slitWidth));
        ui->countNumber->setText(QString::number(newScanList.getCurrentScan().log.countNumber));
        ui->sensitivity->setText(QString::number(newScanList.getCurrentScan().log.sensitivity));
        ui->setScanSpeed->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->setStartPosition->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->setTargetPosition->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->dispXValue->setEnabled(!newScanList.getCurrentScan().readonly);
        ui->dispYValue->setEnabled(!newScanList.getCurrentScan().readonly);
        ui->dispZValue->setEnabled(!newScanList.getCurrentScan().readonly);
        ui->scanName->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->logfileName->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->laserPower->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->slitWidth->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->countNumber->setReadOnly(!newScanList.getCurrentScan().readonly);
        ui->sensitivity->setReadOnly(!newScanList.getCurrentScan().readonly);
    }
    ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    ui->currentSpeed->setText(QString::number(newSpectrometer->getMonoSpeed()));
    ui->newPosition->clear();
    ui->newSpeed->clear();
    ui->currentWaveNumber->setText("Muss berechnet werden");
}

void MainWindow::on_stepBackMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    emit MoveStepDown(newSpectrometer->getMonoPos(), 1, false);
    //Muss ausgebaut werden
    //MonoNed(1, newSpectrometer.getMonoPos());
}

void MainWindow::on_stepForwardMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    emit MoveStepUp(newSpectrometer->getMonoPos(), 1, true);
}

void MainWindow::on_mvButton_2_clicked()
{
    if(ui->moveData->text().toDouble() < 0)
    {   //Hier müssen Signale und Slots rein!
        MonoNed(ui->moveData->text().toDouble(), newSpectrometer->getMonoPos());
    }
    else
    {
        MonoOpp(ui->moveData->text().toDouble(), newSpectrometer->getMonoPos());
    }
}

void MainWindow::on_logButton_clicked()
{
    if(newScanList.getScanNumbers() == 0)
    {
        QMessageBox::information(this, "Error", "No scan is currently loaded!");
        return;
    }
    if(newScanList.getCurrentScan().log.logfileSet)
    {
        QMessageBox msgBox;
        msgBox.setText("Error");
        msgBox.setInformativeText("There exists already a logfile for this scan. Do you want to replace this with a new one?");
        QPushButton *replace = msgBox.addButton(tr("&Replace"), QMessageBox::ActionRole);
        QPushButton *cancel = msgBox.addButton(tr("&Cancel"), QMessageBox::ActionRole);
        //msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        //msgBox.setDefaultButton(QMessageBox::Discard);
        msgBox.exec();
        if(msgBox.clickedButton() == cancel)
            return;
    }
    else
    {
        newScanList.getCurrentScan().log.countNumber = ui->countNumber->text().toDouble();
        newScanList.getCurrentScan().log.laserIntensity = ui->laserPower->text().toDouble();
        newScanList.getCurrentScan().log.sensitivity = ui->sensitivity->text().toDouble();
        newScanList.getCurrentScan().log.slitWidth = ui->slitWidth->text().toDouble();
        newScanList.getCurrentScan().log.name = ui->logfileName->text();
        newScanList.getCurrentScan().log.logfileSet = true;
    }
    ui->gridTabWidget->setCurrentIndex(0);
}

void MainWindow::createLogData()//Deprecated, kann raus
{
    ui->gridTabWidget->setCurrentIndex(2);
//    if(ui->gridTabWidget->currentIndex() == 0)
//        return;
}

void MainWindow::loadConfig()
{
    QString filename = "Config.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);
    QString monoPos, monoSpeed;
    int PolarizerConfig;
    in >> monoPos;
    in >> monoSpeed;
    in >> PolarizerConfig;
    newSpectrometer->setMonoPos(monoPos.toDouble());
    newSpectrometer->setMonoSpeed(monoSpeed.toDouble());
    newSpectrometer->setPolarizers(xPol, (PolarizerConfig % 2 == 1)?true:false );
    newSpectrometer->setPolarizers(yPol, (PolarizerConfig == 2 || PolarizerConfig == 3 || PolarizerConfig == 6)?true:false);
    newSpectrometer->setPolarizers(zPol, (PolarizerConfig >= 4)?true:false);
    ui->dispXValue->setChecked(newSpectrometer->getPolarizers(xPol));
    ui->dispYValue->setChecked(newSpectrometer->getPolarizers(yPol));
    ui->dispZValue->setChecked(newSpectrometer->getPolarizers(zPol));
}

void MainWindow::oncurrentCount(int counts)
{
    ui->photoCounter->setText(QString::number(counts));
}

void MainWindow::writeConfig()
{
    QString filename = "Config.txt";
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(0, "Error", file.errorString());
        return;
    }
    QTextStream out(&file);
    out << newSpectrometer->getMonoPos() << '\n';
    out << newSpectrometer->getMonoSpeed() << '\n';
    out << (int)(newSpectrometer->getPolarizers()[0])*1 + (int)(newSpectrometer->getPolarizers()[1])*2 + (int)(newSpectrometer->getPolarizers()[2])*4;
    file.close();
}

//void MainWindow::on_activateCounter_clicked()
//{
//    newDPC->start();
//}

void MainWindow::on_execButton_2_clicked()
{
    if((ui->newPosition->text().toDouble() != newSpectrometer->getMonoPos()) && !ui->newPosition->text().isEmpty())
    {
        if(ui->newPosition->text().toDouble() > newSpectrometer->getMonoPos())
        {
            qDebug() << "Emitting MoveStepUp";
            emit MoveStepUp(newSpectrometer->getMonoPos(), ui->newPosition->text().toDouble(), true);
        }
        else
        {
            qDebug() << "Emitting MoveStepDown";
            emit MoveStepDown(newSpectrometer->getMonoPos(), ui->newPosition->text().toDouble(), false);
        }
    }
        //moveToTarget(ui->newPosition->text().toDouble(), newSpectrometer->getMonoPos());
    else if(ui->newSpeed->text().toDouble() != newSpectrometer->getMonoSpeed() && !ui->newSpeed->text().isEmpty())
        newSpectrometer->setMonoSpeed(ui->newSpeed->text().toDouble());
    reload_data();
}

void MainWindow::on_gridTabWidget_currentChanged(int index)
{
    reload_data();
}

void MainWindow::on_newScan_clicked(void)
{
    tmpScan.clear();
    MainWindow::changeState(ScanState);
}

void MainWindow::on_stopScan_clicked(void)
{
    tmpScan.clear();
    emit stopScan();
    MainWindow::changeState(EditState);
}

void MainWindow::scanIsInterrupted(void)
{
    tmpScan.clear();
    //qDebug() << "Scan has stopped";
    MainWindow::changeState(EditState);
}

void MainWindow::on_saveSettingsButton_clicked()
{
    if(newScanList.getScanNumbers() == 0)
    {
        QMessageBox::information(this, "Information", "Sorry, but no scan is loaded.");
        return;
    }
    QString fileName = newScanList.getCurrentScan().scanName + ".dat";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(0, "Error!", file.errorString());
        return;
    }
    QTextStream out(&file);
    out << "This data file is for scan " << newScanList.getCurrentScan().scanName << ", written on " << QDate::currentDate().toString() << '\n';
    out << newScanList.getCurrentScan().Params.startPos << '\n';
    out << newScanList.getCurrentScan().Params.finPos << '\n';
    out << newScanList.getCurrentScan().Params.scanSpeed << '\n';
    out << (int)(newScanList.getCurrentScan().Params.polSettings[0])*1 + (int)(newScanList.getCurrentScan().Params.polSettings[1])*2 + (int)(newScanList.getCurrentScan().Params.polSettings[2])*4 << '\n';
    out << "All these data has been saved to the scan file, too\n";
    file.close();
}
