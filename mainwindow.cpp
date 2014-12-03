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
    MainWindow::currentState = EditState;
    MainWindow::currentScanNumber = 0;
    MainWindow::setContextMenuPolicy(Qt::CustomContextMenu);
    MainWindow::setWindowTitle("");
    //MainWindow::newDPC = new DPC;
    MainWindow::newSpectrometer = new Spectrometer_Control(&mutex, &EngineMoving, &cmutex, &CountCond);
    MainWindow::calibrated = false;
    ui->CalibratedBox->setDisabled(true);
    MainWindow::loadConfig();

    //MainWindow::newSpecControl = new Spec_Control(newSpectrometer->getMonoPos());
    //MainWindow::newScanner = new scanner;
    //Setup of TX-Clients
    MainWindow::ipAddr = "127.0.0.1";
    MainWindow::port = 40000;
    MainWindow::Main_TX = NULL;//new TX_thread(MainWindow::ipAddr, MainWindow::port);
    MainWindow::PCTX = NULL;
    MainWindow::PolTX = NULL;
    MainWindow::STPTX = NULL;
    MainWindow::FLTX = NULL;

    //Setup of TX data in UI
    ui->STPTXcon->setDisabled(true);
    ui->MainTXcon->setDisabled(true);
    ui->PCTXcon->setDisabled(true);
    ui->PolTXcon->setDisabled(true);
    ui->FLTXcon->setDisabled(true);
    ui->ipAddress->setInputMask("000.000.000.000");

    MainWindow::MainTXRun = false;
    MainWindow::PolTXRun = false;
    MainWindow::PCTXRun = false;
    MainWindow::STPTXRun = false;

    //Setup of QWT picker
    MainWindow::plotPicker= new QwtPlotPicker(ui->qwtPlot->xBottom, ui->qwtPlot->yLeft, QwtPicker::CrossRubberBand, QwtPicker::AlwaysOn, ui->qwtPlot->canvas());
    pickerMachine = new QwtPickerClickPointMachine();
    plotPicker->setStateMachine(pickerMachine);

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
    ui->CalibButton->hide();
    ui->CalibDataMes1->hide();
    ui->CalibDataMes2->hide();
    ui->CalibDataRe1->hide();
    ui->CalibDataRe2->hide();
    ui->CalibFinished->hide();
    ui->CalibLabel->hide();
    ui->CalibLabel1->hide();
    ui->CalibLabel2->hide();
    ui->AddCalibration->hide();
    ui->gridTabWidget->setCurrentIndex(0);
    ui->gridTabWidget->setTabEnabled(3, false);
    ui->movingBox->setDisabled(true);
    ui->newWaveNumber->setDisabled(true);
    ui->currentPosition->setReadOnly(true);
    ui->currentSpeed->setReadOnly(true);
    ui->currentWaveNumber->setReadOnly(true);
    ui->photoCounter->setReadOnly(true);
    ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    //ui->currentSpeed->setText(QString::number(newSpectrometer->getMonoSpeed()));

    //Some fancy stuff for style
    QString myStyleSheet = QString("QProgressBar{ border: 2px solid black; border-radius: 5px; text-align: center} QProgressBar::chunk { background: green; width: 10px; margin: 0.5px}");
    QString s = ui->progressBar->styleSheet().append(myStyleSheet);
    ui->progressBar->setStyleSheet(s);

    //Creating connections
    connect(newSpectrometer, &Spectrometer_Control::currentCounterData, this, &MainWindow::oncurrentCount);
    connect(newSpectrometer, &Spectrometer_Control::currentData, this, &MainWindow::incomingData);
    connect(newSpectrometer, &Spectrometer_Control::currentScanPosition, this, &MainWindow::CurrentScanStatus);
    connect(newSpectrometer, &Spectrometer_Control::scanFinished, this, &MainWindow::scanIsFinished);
    connect(newSpectrometer, &Spectrometer_Control::positionChanged, this, &MainWindow::PositionChanged);
    connect(newSpectrometer, &Spectrometer_Control::stepperMoving, this, &MainWindow::StepperMoving);
    connect(plotPicker, SIGNAL(selected(const QPointF&)), this, SLOT(mousePoint(QPointF)));

    //Thread work
//    newSpecControl->moveToThread(SCThread);
    //set current state:
    changeState(EditState);
    //Running subthreads
//    SCThread->start();
    //newSpecControl->start();
    //newDPC->start();
    //newScanner->start();

}

MainWindow::~MainWindow()
{
    MainWindow::writeConfig();
    emit stopCounting();
    emit stopControlling();
    emit killScanner();
    //newSpecControl->wait(5000);
    //newDPC->wait(500);
    //newScanner->wait(500);
    //MainWindow::SCThread->wait(500);
    //qDebug() << "Is DPC still counting: " << newDPC->isRunning();
    //qDebug() << "Is ControlThread still running?" << newSpecControl->isRunning();
    //qDebug() << "Is scanner still running?" << newScanner->isRunning();
    qDebug() << "Cleaning main!";
    //delete MainWindow::SCThread;
    //delete MainWindow::newDPC;
    //delete MainWindow::newSpecControl;
    qDebug() << "SC, DPC and SC cleaned";
    delete MainWindow::newSpectrometer;
    //delete MainWindow::newScanner;
    qDebug() << "Scanner and Spec cleaned";
    delete MainWindow::plotPicker;
    qDebug() << "plotPicker cleaned";
    if(MainWindow::pickerMachine != NULL)
    {
        qDebug() << pickerMachine;
        //delete MainWindow::pickerMachine;//Leads to crash, strange
    }
    qDebug() << "pickerMachine cleaned";
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
    vectorToMap(newScanList.getCurrentScan().getValues().getData()/*currentScan.values.Data*/, MainWindow::Scandata);
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
        class Scan newScan;
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
        if(magic != 0x8008135 || magic != 0x80081E5 || magic != 0xB0081E5)//Three versions, newest one last
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
        //newScan.values.Data.empty();
        newScan.getValues().setData().empty();//Highly risky, try to replace it???
        in >> scanName;
        in >> monoSetting;
        in >> startScan;
        in >> finScan;
        in >> scanSpeed;
        //in >> newScan.values.Data;
        in >> newScan.setValues().setData();
        if(magic == 0x80081E5 || magic == 0xB0081E5)
        {
            //in >> newScan.log.countNumber;
            in >> newScan.getLog().getCount();
            in >> newScan.getLog().getIntensity();
            in >> newScan.getLog().getName();
            in >> newScan.getLog().getSensitivity();
            in >> newScan.getLog().getSlit();
        }
        if(magic == 0xB0081E5)
            in >> newScan.isCalibrated;
        newScan.scanName = scanName;
        newScan.Params.finPos = finScan;
        newScan.Params.startPos = startScan;
        newScan.Params.scanSpeed = scanSpeed;
        newScan.Params.polSettings.push_back((bool)(monoSetting%2 == 1));
        newScan.Params.polSettings.push_back((bool)(monoSetting%2 == 0 && monoSetting != 4));
        newScan.Params.polSettings.push_back((bool)(monoSetting >= 4));
        newScan.readonly = true;
        if(newScan.getValues().getData().isEmpty())
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
//            if(newScan.Params.finPos != -1 && newScan.Params.scanSpeed != -1 && newScan.Params.startPos != -1)
//            {
                ui->setStartPosition->setText(QString::number(newScan.Params.startPos));
                ui->setTargetPosition->setText(QString::number(newScan.Params.finPos));
                if(newScan.Params.scanSpeed == (-1))
                    ui->setScanSpeed->setText("n/A");
                else
                    ui->setScanSpeed->setText(QString::number(newScan.Params.scanSpeed));
                ui->dispXValue->setChecked(newScan.Params.polSettings[0]);
                ui->dispYValue->setChecked(newScan.Params.polSettings[1]);
                ui->dispZValue->setChecked(newScan.Params.polSettings[2]);
//            }
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
        out << (quint32)0xB0081E5;
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
            out << MainWindow::newScanList.getCurrentScan().isCalibrated;
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

    calibrateAct = new QAction(tr("&Calibrate spectrometer"), this);
    calibrateAct->setStatusTip(tr("Calibrate spectrometer"));
    connect(calibrateAct, SIGNAL(triggered()), this, SLOT(calibrate()));

}

void MainWindow::calibrate()
{
    changeState(CalibState);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(openGenericAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveGenericAct);
    fileMenu->addAction(saveGenericAll);
    fileMenu->addAction(calibrateAct);
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
            currentState = ScanState;
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
            ui->saveSettingsButton->hide();
            ui->loadSettingsButton->show();
            ui->scanName->setReadOnly(false);
            ui->scanButton->show();
            ui->stopScan->show();
            ui->newScan->hide();
            break;
        }
        case EditState:
        {
            currentState = EditState;
            ui->horizontalLayout_2->setStretchFactor(ui->qwtPlot, 19);
            ui->horizontalLayout_2->setStretchFactor(ui->formLayout_2, 1);
            ui->scanName->show();
            ui->loadGenericButton->show();
            ui->NameLabel->show();
            ui->setScanSpeed->setReadOnly(true);
            ui->setStartPosition->setReadOnly(true);
            ui->setTargetPosition->setReadOnly(true);
            ui->scanName->setReadOnly(true);
            ui->loadSettingsButton->show();
            ui->dispXValue->show();
            ui->dispYValue->show();
            ui->dispZValue->show();
            ui->dispXValue->setEnabled(1);
            ui->dispYValue->setEnabled(1);
            ui->dispZValue->setEnabled(1);
            ui->gridTabWidget->setTabEnabled(1, true);
            ui->gridTabWidget->setTabEnabled(2, true);
            ui->loadSettingsButton->hide();
            ui->saveSettingsButton->show();
            ui->scanButton->hide();
            ui->stopScan->hide();
            ui->saveScan->show();
            ui->newScan->show();
            ui->CalibButton->hide();
            ui->CalibDataMes1->hide();
            ui->CalibDataMes2->hide();
            ui->CalibDataRe1->hide();
            ui->CalibDataRe2->hide();
            ui->CalibFinished->hide();
            ui->CalibLabel->hide();
            ui->CalibLabel1->hide();
            ui->CalibLabel2->hide();
            ui->AddCalibration->hide();
            ui->PolarizerLabel->show();
            ui->CalibReVal->hide();
            ui->CalibMesVal->hide();
            ui->CalibConfirm->hide();
            if(MainWindow::newScanList.getScanNumbers() > 1)
            {
                ui->LastScan->show();
                ui->NextScan->show();
                ui->ChooseScanLabel->show();
                ui->selectScanLabel->show();
                ui->selectScanBox->show();
            }
            break;
        }
        case CalibState:
        {
            currentState = CalibState;
            clear_window();
            ui->CalibReVal->show();
            ui->CalibConfirm->show();
            ui->CalibMesVal->show();
            ui->horizontalLayout_2->setStretchFactor(ui->qwtPlot, 15);
            ui->horizontalLayout_2->setStretchFactor(ui->CalibLayout, 5);
            ui->CalibLayout->setColumnStretch(1, 10);
            ui->CalibLayout->setColumnStretch(2, 200);
            ui->scanName->hide();
            ui->NameLabel->hide();
            ui->setScanSpeed->setReadOnly(false);
            ui->setStartPosition->setReadOnly(false);
            ui->setTargetPosition->setReadOnly(false);
            ui->loadGenericButton->hide();
            ui->loadSettingsButton->hide();
            ui->NextScan->hide();
            ui->saveScan->hide();
            ui->newScan->hide();
            ui->LastScan->hide();
            ui->dispXValue->hide();
            ui->dispYValue->hide();
            ui->dispZValue->hide();
            ui->CalibButton->show();
            ui->CalibDataMes1->show();
            ui->CalibDataMes2->show();
            ui->CalibDataRe1->show();
            ui->CalibDataRe2->show();
            ui->CalibFinished->show();
            ui->CalibLabel->show();
            ui->AddCalibration->show();
            ui->CalibLabel1->show();
            ui->CalibLabel2->show();
            ui->PolarizerLabel->hide();
            ui->saveSettingsButton->hide();
            break;
        }
        case MoveState:
        {
            break;
        }
    }
}

void MainWindow::on_scanButton_clicked()//Muss ueberarbeitet werden???
{
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
    tmpScan.isCalibrated = false;
    //qDebug() << "Scanner is initialized";
    //emit initScanner(tmpScan.Params.startPos, tmpScan.Params.finPos, tmpScan.Params.scanSpeed, newSpectrometer->getMonoPos(), (tmpScan.Params.finPos-tmpScan.Params.startPos)>0?true:false);
    //qDebug() << "Scanner is going to be started!";
    newSpectrometer->scan(ui->setStartPosition->text().toInt(), ui->setTargetPosition->text().toInt(), ui->setScanSpeed->text().toInt());
    yes = NULL;
    no = NULL;
    //Analyze(MainWindow::newScanList);
}

void MainWindow::incomingData(QPair<int, int> data)
{
    tmpScan.values.Data.push_back(qMakePair(data.first + ui->setStartPosition->text().toInt(), data.second));
    qDebug() << "Incoming data in main: i=" << data.first << ", counts=" << data.second << " and tmpScan.size=" << tmpScan.getValues().getData().size();
}

void MainWindow::closeProgressBar()
{
    ui->progressBar->hide();
}

void MainWindow::sortPoints()
{
    qSort(CorrectionValues);
}

QPair<QPair<int, int>, QPair<int, int> > MainWindow::getNearestPoints(int xVal)
{
    QPair<QPair<int, int>, QPair<int, int> > points;
    if(CorrectionValues.size() < 2)
    {
        QMessageBox::information(this, "Error", "Too few data for calibration avaliable. Can not calibrate scan!");
        return qMakePair(qMakePair(0, 0), qMakePair(0, 0));
    }
    for(int i = 0; i < CorrectionValues.size(); i++)
    {
        points.first = CorrectionValues[i];
        points.second = CorrectionValues[i+1];
        if(i+1 == CorrectionValues.size())
            return points;
        else
        {
            if(xVal < points.first.first)
                return points;
            else
                if((points.first.first - xVal) < 0 && (points.second.first - xVal) > 0)
                    return points;
        }

    }
}

int MainWindow::calculateValue(QPair<int, int> targetPoint, QPair<int, int> firstPoint = qMakePair(0, 0), QPair<int, int> secondPoint = qMakePair(0, 0))
{
    if((firstPoint.first == 0 && secondPoint.first == 0) || (firstPoint.second == 0 && secondPoint.second == 0))
    {
        QMessageBox::information(this, "Error", "No sufficient informations for calculating correction values");
        return -1000;
    }
    double m = (double)(firstPoint.second - secondPoint.second)/(double)(firstPoint.first - secondPoint.first);
    QPair<int, int> nextPoint = (fabs(targetPoint.first - firstPoint.first) <= fabs(targetPoint.first - secondPoint.first))?firstPoint : secondPoint;
    return m*(targetPoint.first - nextPoint.first) + nextPoint.second;
}

int MainWindow::calculateInvValue(QPair<int, int> targetPoint, QPair<int, int> firstPoint, QPair<int, int> secondPoint)
{
    if((firstPoint.first == 0 && secondPoint.first == 0) || (firstPoint.second == 0 && secondPoint.second == 0))
    {
        QMessageBox::information(this, "Error", "No sufficient informations for calculating correction values");
        return -1000;
    }
    double m = (double)(firstPoint.second - secondPoint.second)/(double)(firstPoint.first - secondPoint.first);
    //Ausgehend davon, dass die Steigung linear ist (DANGER???)
    return ((double)targetPoint.second/*-(double)firstPoint.second*/)/m;
}

void MainWindow::calibrateScan(ScanData &newScan)
{
    for(int i = 0; i < newScan.Data.size(); i++)
    {
        QPair<QPair<int, int>, QPair<int, int> > nextPoints = getNearestPoints(newScan.Data[i].first);
        newScan.Data[i].first = calculateValue(newScan.Data[i], nextPoints.first, nextPoints.second);
    }
}

void MainWindow::scanIsFinished(void)
{
    if(calibrated)
    {
        calibrateScan(MainWindow::tmpScan.values);
        MainWindow::tmpScan.isCalibrated = true;
    };
    tmpScan.values.Data.pop_front();
    tmpScan.values.Data.pop_front();
    newScanList.addScan(MainWindow::tmpScan);
    newScanList.getNextScan();
    if(currentState != CalibState)
        ui->selectScanBox->addItem(newScanList.getCurrentScan().scanName);
    else
        ui->selectScanBox->addItem("Calibration");
    closeProgressBar();
    tmpScan.clear();
    if(currentState != CalibState)
        changeState(EditState);
    reload_data();
    replot();
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
        if(newScanList.getCurrentScan().Params.scanSpeed == -1)
            ui->setScanSpeed->setText("n/A");
        else
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
        ui->CalibratedBox->setChecked(newScanList.getCurrentScan().isCalibrated);
    }
    ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    //ui->currentSpeed->setText(QString::number(newSpectrometer->getMonoSpeed()));
    ui->newPosition->clear();
    ui->newWaveNumber->clear();
    ui->newSpeed->clear();
    if(!calibrated)
        ui->currentWaveNumber->setText("Muss berechnet werden");
    else
    {
        ui->currentWaveNumber->setText(QString::number(calculateValue(qMakePair(ui->currentPosition->text().toInt(), 0), CorrectionValues.first(), CorrectionValues.last())));
    }
}

void MainWindow::on_stepBackMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    newSpectrometer->moveStepper(1, 0);
    //emit MoveStepDown(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() - 1);
    reload_data();
    //Muss ausgebaut werden
    //MonoNed(1, newSpectrometer.getMonoPos());
}

void MainWindow::on_stepForwardMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    newSpectrometer->moveStepper(1, 1);
    //emit MoveStepUp(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() + 1);
    reload_data();
}

void MainWindow::on_mvButton_2_clicked()
{
    if(ui->moveData->text().toDouble() < 0)
    {   //Hier müssen Signale und Slots rein!
        newSpectrometer->moveStepper(fabs(ui->moveData->text().toInt()), 0);
        //emit MoveStepDown(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() + ui->moveData->text().toInt());
        ui->moveData->setText("");
    }
    else
    {
        newSpectrometer->moveStepper(fabs(ui->moveData->text().toInt()), 1);
        //emit MoveStepUp(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() + ui->moveData->text().toInt());
        ui->moveData->setText("");
    }
    reload_data();
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
        {
            replace = NULL;
            cancel = NULL;
            return;
        }
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
        QMessageBox::information(0, "error", "No config file found!");
        return;
    }
    QTextStream in(&file);
    QString monoPos, monoSpeed;
    QString calibData;
    QStringList Data;
    int PolarizerConfig;
    monoPos = in.readLine();//in >> monoPos;
    qDebug() << "MonoPos from Config: " << monoPos;
    //in >> monoSpeed;
    PolarizerConfig = in.readLine().toInt();//in >> PolarizerConfig;
    qDebug() << "PolarizerConfig from Config: " << PolarizerConfig;
    calibData = in.readLine();
    qDebug() << "Calibration data: " << calibData;
    if(calibData.isEmpty())
        calibrated = false;
    else
    {
        Data = calibData.split(" ");
        qDebug() << "Data size is: " << Data.size();
        if(Data.size()%2 == 0)
        {
            for(int i = 0; i < Data.size(); i+=2)
            {
                CorrectionValues.push_back(qMakePair(Data[i].toInt(), Data[i+1].toInt()));
            }
        }
        else
        {
            Data.pop_back();
            for(int i = 0; i < Data.size(); i+=2)
            {
                CorrectionValues.push_back(qMakePair(Data[i].toInt(), Data[i+1].toInt()));
            }
        }
        qDebug() << "Size of the corrected values: " << CorrectionValues.size();
        if(CorrectionValues.size() > 0)
        {
            sortPoints();
            calibrated = true;
            ui->CalibratedBox->setChecked(true);
            qDebug() << "Yay, new correction values!";
        }
    }


    newSpectrometer->setMonoPos(monoPos.toDouble());
    //newSpectrometer->setMonoSpeed(monoSpeed.toDouble());
    newSpectrometer->setPolarizers(xPol, (PolarizerConfig % 2 == 1)?true:false );
    newSpectrometer->setPolarizers(yPol, (PolarizerConfig == 2 || PolarizerConfig == 3 || PolarizerConfig == 6)?true:false);
    newSpectrometer->setPolarizers(zPol, (PolarizerConfig >= 4)?true:false);
    ui->dispXValue->setChecked(newSpectrometer->getPolarizerState(xPol));
    ui->dispYValue->setChecked(newSpectrometer->getPolarizerState(yPol));
    ui->dispZValue->setChecked(newSpectrometer->getPolarizerState(zPol));
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
    QString CalibrationData;
    if(calibrated == true)
    {

        for(int i = 0; i < CorrectionValues.size(); i++)
        {
            CalibrationData += QString::number(CorrectionValues[i].first) + " " + QString::number(CorrectionValues[i].second) + " ";
        }
    }
    out << newSpectrometer->getMonoPos() << '\n';
    //out << newSpectrometer->getMonoSpeed() << '\n';
    out << (int)(newSpectrometer->getPolarizers()[0])*1 + (int)(newSpectrometer->getPolarizers()[1])*2 + (int)(newSpectrometer->getPolarizers()[2])*4 << '\n';
    if(calibrated == true)
        out << CalibrationData;
    file.close();
}

void MainWindow::on_execButton_2_clicked()
{
    if((ui->newPosition->text().toInt() != newSpectrometer->getMonoPos()) && !ui->newPosition->text().isEmpty())
    {
        newSpectrometer->moveStepper(fabs(newSpectrometer->getMonoPos() - ui->newPosition->text().toInt()), ((ui->newPosition->text().toInt() - newSpectrometer->getMonoPos()) >= 0));
    }
    if((ui->newWaveNumber->text().toInt() != calculateValue(qMakePair(newSpectrometer->getMonoPos(), 0), CorrectionValues.first(), CorrectionValues.last())) && !ui->newWaveNumber->text().isEmpty())
    {
        int newTarget = calculateInvValue(qMakePair(0, ui->newWaveNumber->text().toInt()), CorrectionValues.first(), CorrectionValues.last());
        qDebug() << "New Target is: " << newTarget;
        newSpectrometer->moveStepper(fabs(newSpectrometer->getMonoPos() - newTarget), (newTarget - newSpectrometer->getMonoPos()) >= 0);
    }
    reload_data();
}

void MainWindow::StepperMoving(void)
{
    qDebug() << "Stepper moving!";
    ui->movingBox->setChecked(true);
    reload_data();
}

void MainWindow::PositionChanged()
{
    reload_data();
    ui->movingBox->setChecked(false);
}

void MainWindow::on_gridTabWidget_currentChanged(int index)
{
    reload_data();
}

void MainWindow::on_newScan_clicked(void)
{
    tmpScan.clear();
    tmpScan.isLoaded = true;
    MainWindow::clear_window();
    MainWindow::changeState(ScanState);
}

void MainWindow::on_stopScan_clicked(void)
{
    tmpScan.clear();
    emit stopScan();
    reload_data();
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan data file (*.dat);;All Files(*)"));
    //QString fileName = newScanList.getCurrentScan().scanName + ".dat";
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

void MainWindow::on_loadSettingsButton_clicked()
{
    if(tmpScan.isLoaded == false)
    {
        QMessageBox::information(this, "Information", "Sorry, but no scan is loaded.");
        return;
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scan data file"), "", tr("Scan Data(*.dat);;All Files(*)"));
    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
            return;
        }
        QTextStream in(&file);
        in.readLine();
        tmpScan.Params.startPos = in.readLine().toDouble();
        ui->setStartPosition->setText(QString::number(tmpScan.Params.startPos));
        tmpScan.Params.finPos = in.readLine().toDouble();
        ui->setTargetPosition->setText(QString::number(tmpScan.Params.finPos));
        tmpScan.Params.scanSpeed = in.readLine().toDouble();
        ui->setScanSpeed->setText(QString::number(tmpScan.Params.scanSpeed));
        qreal polPos = in.readLine().toDouble();
        tmpScan.Params.polSettings[0] = (polPos == 1 || polPos == 3 || polPos == 5 || polPos == 7);
        tmpScan.Params.polSettings[1] = (polPos == 2 || polPos == 6);
        tmpScan.Params.polSettings[2] = (polPos >= 4);
        ui->dispXValue->setChecked(tmpScan.Params.polSettings[0]);
        ui->dispYValue->setChecked(tmpScan.Params.polSettings[1]);
        ui->dispZValue->setChecked(tmpScan.Params.polSettings[2]);
        file.close();
    }


}

void MainWindow::on_centerMono_clicked(void)
{
    QMessageBox::information(this, "Information", "Sorry, not implemented yet. Come back later!");
}

void MainWindow::clear_window(void)
{
    ui->setScanSpeed->setText("");
    ui->setStartPosition->setText("");
    ui->setTargetPosition->setText("");
    ui->scanName->setText("");
    QVector<double> x, y;
    for(int i = 0; i < 1; i++)
    {
        x.push_back((double)i);
        y.push_back(0.0);
    }
    MainWindow::Curve.setSamples(x, y);
    MainWindow::Curve.attach(ui->qwtPlot);
    ui->qwtPlot->updateAxes();
    ui->qwtPlot->show();
    ui->qwtPlot->replot();
    //ui->qwtPlot->detachItems(QwtPlotItem::Rtti_PlotItem, true);
}

void MainWindow::on_connect_clicked()
{
    if(ui->ipAddress->text().isEmpty() || ui->port->text().isEmpty())
    {
        QMessageBox::information(this, "Information", "One of the required fields has not been filled out. Please fill out all fields before connecting!");
        return;
    }
    QHostAddress myIp;
    if(!myIp.setAddress(ui->ipAddress->text()))
    {
        QMessageBox::information(this, "Information", "No valid ip address entered. Please verify!");
        return;
    }
    qDebug() << "Connecting now!";
    MainWindow::Main_TX = new TX_thread(MainWindow::ipAddr, MainWindow::port, "DATA");
    MainWindow::PCTX = new TX_thread(MainWindow::ipAddr, MainWindow::port + 2, "DATA");
    MainWindow::PolTX = new Server(MainWindow::ipAddr, MainWindow::port + 3);
    MainWindow::STPTX = new Server(MainWindow::ipAddr, MainWindow::port + 1);
    MainWindow::FLTX = new TX_thread(MainWindow::ipAddr, MainWindow::port + 4, "FILE");
    //Connecting mainTX
    connect(this, SIGNAL(killMain()), Main_TX, SLOT(killTX()));
    connect(this, SIGNAL(connectMain(QString,quint32)), Main_TX, SLOT(connect_to_TX(QString,quint32)));
    connect(Main_TX, SIGNAL(gotNewData(QVariant)), this, SLOT(gotNewDataMain(QVariant)));
    connect(Main_TX, SIGNAL(noServer()), this, SLOT(NoServer()));
    //connecting PCTX
    connect(this, &MainWindow::killPC, PCTX, &TX_thread::killTX);
    connect(this, &MainWindow::connectPC, PCTX, &TX_thread::connect_to_TX);
    connect(PCTX, &TX_thread::gotNewData, this, &MainWindow::gotNewDataPC);
    connect(PCTX, &TX_thread::noServer, this, &MainWindow::NoServer);
    //Connect FLTX
    connect(this, &MainWindow::killFL, FLTX, &TX_thread::killTX);
    connect(this, &MainWindow::connectFL, FLTX, &TX_thread::connect_to_TX);
    connect(FLTX, &TX_thread::gotNewData, this, &MainWindow::gotNewFileFL);
    connect(FLTX, &TX_thread::noServer, this, &MainWindow::NoServer);
    //Connecting PolTX && STPTX
    connect(this, &MainWindow::sendDataPoll, PolTX, &Server::sendData);
    connect(this, &MainWindow::sendDataSTP, STPTX, &Server::sendData);
    connect(PolTX, &Server::gotNewConnection, this, &MainWindow::gotNewConnectionPol);
    connect(STPTX, &Server::gotNewConnection, this, &MainWindow::gotNewConnectionSTP);
    Main_TX->start();
    PCTX->start();
    FLTX->start();
    emit connectMain(ui->ipAddress->text(), ui->port->text().toUInt());
}

void MainWindow::gotNewDataMain(QVariant data)
{
    if(data.toString() == "BBB")
    {
        ui->MainTXcon->setChecked(true);
        if(PCTX == NULL)
        {
            PCTX = new TX_thread(MainWindow::ipAddr, MainWindow::port + 2, "DATA");
            //connect PC
            connect(this, &MainWindow::killPC, PCTX, &TX_thread::killTX);
            connect(this, &MainWindow::connectPC, PCTX, &TX_thread::connect_to_TX);
            connect(PCTX, &TX_thread::gotNewData, this, &MainWindow::gotNewDataPC);
            connect(PCTX, &TX_thread::noServer, this, &MainWindow::NoServer);
        }
        emit MainWindow::connectPC(ui->ipAddress->text(), ui->port->text().toUInt() + 2);
        emit MainWindow::connectFL(ui->ipAddress->text(), ui->port->text().toUInt() + 4);
    }
    else
    {
        QMessageBox::information(this, "Error", data.toString());
        return;
    }
    MainWindow::MainTXRun = true;
    ui->MainTXcon->setChecked(true);
}

void MainWindow::wrongDeviceMain()
{

}

void MainWindow::MainKilled()
{
    MainTXRun = false;
}

void MainWindow::NoServer()
{
    QMessageBox::information(this, "Error", "No server found, please check connection!");
}

void MainWindow::gotNewDataPC(QVariant data)
{
    if(data.toString() == "INIT")
    {
        MainWindow::PCTXRun = true;
        ui->PCTXcon->setChecked(true);
    }
    else
    {
        quint32 counts = data.toUInt();
        //Now Data has to be saved!
    }
}

void MainWindow::wrongDevicePC()
{

}

void MainWindow::PCkilled()
{
    MainWindow::PCTXRun = false;
}

void MainWindow::gotNewConnectionPol(QVariant address)
{
    if(/*address.toString() == ui->ipAddress->text()*/true)
    {
        ui->PolTXcon->setChecked(true);
        qDebug() << "Pol got connected";
        PolTXRun = true;
    }
    else
        QMessageBox::information(this, "Error", "PolTX got connected from an alien ip address!");
}

void MainWindow::wrongDevicePol()
{

}

void MainWindow::Polkilled()
{
    PolTXRun = false;
}

void MainWindow::gotNewConnectionSTP(QVariant address)
{
    if(address.toString() == ui->ipAddress->text())
    {
        ui->STPTXcon->setChecked(true);
        qDebug() << "STP got connected!";
        STPTXRun = true;
    }
    else
        QMessageBox::information(this, "Error", "STPTX got connected from an alien ip address!");
}

void MainWindow::wrongDeviceSTP()
{

}

void MainWindow::STPkilled()
{
    STPTXRun = false;
}

void MainWindow::wrongDeviceFL()
{

}

void MainWindow::FLkilled()
{
    MainWindow::FLRun = false;
}

void MainWindow::gotNewFileFL(QVariant data)
{
    if(data.toString() == "FILE")
    {
        MainWindow::FLRun = true;
        ui->FLTXcon->setChecked(true);
    }
    else
    {
        QString fileName = "Data.txt";
        QString new_fileName = fileName;
        int i = 0;
        while(access(fileName.toStdString().c_str(), F_OK) == -1)
        {
            new_fileName = fileName;
            i++;
            new_fileName += i;
        }
        QFile file(new_fileName);
        file.open(QIODevice::WriteOnly);
        file.write(data.toByteArray());
        file.close();
    }
}

void MainWindow::on_CalibButton_clicked()
{
    if(ui->setScanSpeed->text().isEmpty() || ui->setStartPosition->text().isEmpty() || ui->setTargetPosition->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error!"), tr("Not all neccessary information entered, please check your entered data!"));
        return;
    }
    ui->progressBar->show();
    ui->progressBar->setValue(1);
    tmpScan.Params.finPos = ui->setTargetPosition->text().toDouble();
    tmpScan.Params.startPos = ui->setStartPosition->text().toDouble();
    tmpScan.Params.scanSpeed = ui->setScanSpeed->text().toDouble();
    tmpScan.scanName = ui->scanName->text();
    //qDebug() << "Scanner is initialized";
    //emit initScanner(tmpScan.Params.startPos, tmpScan.Params.finPos, tmpScan.Params.scanSpeed, newSpectrometer->getMonoPos(), (tmpScan.Params.finPos-tmpScan.Params.startPos)>0?true:false);
    //qDebug() << "Scanner is going to be started!";
    newSpectrometer->scan(tmpScan.Params.startPos, tmpScan.Params.finPos, tmpScan.Params.scanSpeed);
}

void MainWindow::on_CalibFinished_clicked()
{
    changeState(EditState);
}

void MainWindow::on_CalibConfirm_clicked()
{
    //Hardcoded is evil, replace it!
    if(!ui->CalibDataMes1->text().isEmpty() && !ui->CalibDataRe1->text().isEmpty())
        CorrectionValues.push_back(qMakePair(ui->CalibDataMes1->text().toInt(), ui->CalibDataRe1->text().toInt()));
    if(!ui->CalibDataMes2->text().isEmpty() && !ui->CalibDataRe2->text().isEmpty())
        CorrectionValues.push_back(qMakePair(ui->CalibDataMes2->text().toInt(), ui->CalibDataRe2->text().toInt()));
    if(CorrectionValues.size() == 0)
    {
        QMessageBox::information(this, "Error", "No correction values entered, please check your input!");
        return;
    }
    else
        QMessageBox::information(this, "Information", "All correction data has been saved!");
    ui->CalibDataMes1->clear();
    ui->CalibDataMes2->clear();
    ui->CalibDataRe1->clear();
    ui->CalibDataRe2->clear();
    MainWindow::clear_window();
    calibrated = true;
    changeState(EditState);
}

void MainWindow::mousePoint(const QPointF &point)
{
    QPointF newPoint = point;
    ui->xPos->setText(QString::number(newPoint.rx()));
    ui->yPos->setText(QString::number(newPoint.ry()));
}
