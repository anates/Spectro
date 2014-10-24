#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::polarizerSettings.resize(3);
    MainWindow::loadConfig();
    createActions();
    createMenus();
    ui->loadGenericButton->setToolTip(tr("Load scan from a file"));
    //ui->saveButton->setToolTip(tr("Save scan to a file"));
    ui->scanButton->setToolTip("Start scan");
    ui->horizontalLayout_2->setStretchFactor(ui->qwtPlot, 19);
    ui->horizontalLayout_2->setStretchFactor(ui->formLayout_2, 1);
    MainWindow::currentScanNumber = 0;
    MainWindow::setContextMenuPolicy(Qt::CustomContextMenu);
    ui->LastScan->hide();
    ui->NextScan->hide();
    ui->ChooseScanLabel->hide();
    ui->selectScanBox->hide();
    ui->selectScanLabel->hide();
    ui->progressBar->hide();
    ui->progressBar->setValue(0);
    MainWindow::setWindowTitle("");
    ui->gridTabWidget->setCurrentIndex(0);

    ui->currentPosition->setReadOnly(true);
    ui->currentSpeed->setReadOnly(true);
    ui->currentWaveNumber->setReadOnly(true);
    ui->photoCounter->setReadOnly(true);

    MainWindow::newDPC = new DPC;
    connect(newDPC, SIGNAL(currentCount(int)), SLOT(oncurrentCount(int)));
    connect(newDPC, SIGNAL(finished()), newDPC, SLOT(deleteLater()));

    qDebug() << QThread::currentThread() << "constructor";

    QString myStyleSheet = QString("QProgressBar{ border: 2px solid black; border-radius: 5px; text-align: center} QProgressBar::chunk { background: green; width: 10px; margin: 0.5px}");
    QString s = ui->progressBar->styleSheet().append(myStyleSheet);
    ui->progressBar->setStyleSheet(s);

    ui->currentPosition->setText(QString::number(newSpectrometer.MonoPos));
    ui->currentSpeed->setText(QString::number(newSpectrometer.MonoSpeed));

    //DataProcessingThread dataProcessor;
    //connect(dataProcessor, SIGNAL(dataProcessor.currentCount(int)), ui->photoCounter, SLOT(ui->photoCounter->setText(QString)));
    //dataProcessor.start();
    //ui->qwtPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    //connect(ui->qwtPlot, SIGNAL(customContextMenuRequested(QPoint)), SLOT(customMenuRequested(QPoint)));
    //ui->qwtPlot->contextMenuEvent(QContextMenuEvent *event);
    //ui->gridTabWidget->TabShape = QTabWidget::Triangular;
}

MainWindow::~MainWindow()
{
    MainWindow::writeConfig();
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
    vectorToMap(newScanList.Scans[currentScanNumber-1].values.Data/*currentScan.values.Data*/, MainWindow::Scandata);
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
        newScan.finPos = finScan;
        newScan.startPos = startScan;
        newScan.scanSpeed = scanSpeed;
        newScan.polSettings.push_back((bool)(monoSetting%2 == 1));
        newScan.polSettings.push_back((bool)(monoSetting%2 == 0 && monoSetting != 4));
        newScan.polSettings.push_back((bool)(monoSetting >= 4));
        if(newScan.values.Data.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
            return;
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            MainWindow::newScanList.Scans.push_back(newScan);
            MainWindow::newScanList.scanFileNames.push_back(fileName);
            if(MainWindow::newScanList.Scans.size() > 1)
            {
                ui->LastScan->show();
                ui->NextScan->show();
                ui->ChooseScanLabel->show();
                ui->selectScanLabel->show();
                ui->selectScanBox->show();
            }
            currentScan = newScanList.Scans[currentScanNumber];
            currentScanNumber++;
            ui->selectScanBox->addItem(currentScan.scanName);
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
        newScan.polSettings[0] = false;
        newScan.polSettings[1] = false;
        newScan.polSettings[2] = false;
        newScan.av = NoAverage;
        newScan.finPos = -1;
        newScan.scanName = fileName;
        newScan.scanSpeed = -1;
        newScan.startPos = -1;
        read_unformatted_file(newScan, fileName);
        //Generische Daten werden eingegeben, müssen später mit richtigen Werten ersetzt werden

        if(newScan.values.Data.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            MainWindow::newScanList.Scans.push_back(newScan);
            MainWindow::newScanList.scanFileNames.push_back(fileName);
            if(MainWindow::newScanList.Scans.size() > 1)
            {
                ui->LastScan->show();
                ui->NextScan->show();
                ui->ChooseScanLabel->show();
                ui->selectScanLabel->show();
                ui->selectScanBox->show();
            }
            currentScan = newScanList.Scans[currentScanNumber];
            currentScanNumber++;
            ui->selectScanBox->addItem(currentScan.scanName);
            MainWindow::setWindowTitle(fileName);
            if(newScan.finPos != -1 && newScan.scanSpeed != -1 && newScan.startPos != -1)
            {
                ui->setStartPosition->setText(QString::number(newScan.startPos));
                ui->setTargetPosition->setText(QString::number(newScan.finPos));
                ui->setScanSpeed->setText(QString::number(newScan.scanSpeed));
                ui->dispXValue->setChecked(newScan.polSettings[0]);
                ui->dispYValue->setChecked(newScan.polSettings[1]);
                ui->dispZValue->setChecked(newScan.polSettings[2]);
            }
            MainWindow::replot();
        }
    }
}

void MainWindow::save()
{
    if(newScanList.Scans.isEmpty())
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
        if(!MainWindow::newScanList.Scans.isEmpty())
        {
            out << MainWindow::newScanList.Scans[currentScanNumber-1].scanName;
            qint32 monoSetting = (int)(MainWindow::newScanList.Scans[currentScanNumber-1].polSettings[0]) + (int)(MainWindow::newScanList.Scans[0].polSettings[1])*2 + (int)(MainWindow::newScanList.Scans[0].polSettings[2])*4;
            out << monoSetting;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].startPos;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].finPos;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].scanSpeed;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].values.Data;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].log.countNumber;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].log.laserIntensity;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].log.name;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].log.sensitivity;
            out << MainWindow::newScanList.Scans[currentScanNumber-1].log.slitWidth;
        }
        else
            QMessageBox::information(this, tr("No scan data"),tr("No scan opened!"));
    }
}

void MainWindow::saveGeneric()
{

    if(newScanList.Scans.isEmpty())
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
                newScanList.Scans[currentScanNumber-1].scanName = fileName;
            else
                newScanList.Scans[currentScanNumber-1].scanName = ui->scanName->text();
            if(ui->setScanSpeed->text() != "")
                newScanList.Scans[currentScanNumber-1].scanSpeed = ui->setScanSpeed->text().toDouble();
            if(ui->setStartPosition->text() != "")
                newScanList.Scans[currentScanNumber-1].startPos = ui->setStartPosition->text().toDouble();
            if(ui->setTargetPosition->text() != "")
                newScanList.Scans[currentScanNumber-1].finPos = ui->setTargetPosition->text().toDouble();
            write_unformatted_file(newScanList.Scans[currentScanNumber-1]/*MainWindow::Scandata*/, fileName);
            if(saveLogFile)
                write_log_file(newScanList.Scans[currentScanNumber-1], fileName);
        }
    }
}

void MainWindow::saveGenericAllPlots()
{
    if(newScanList.Scans.isEmpty())
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
        for(int i = 0; i < newScanList.Scans.size(); i++)
        {
            write_unformatted_file(newScanList.Scans[i], fileName + QString::number(i+1));
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
    if(newScanList.Scans[currentScanNumber-1].polSettings.size() == 3)
        newScanList.Scans[currentScanNumber-1].polSettings[0] = checked;
    else
    {
        QMessageBox::information(this, tr("Exceptional Error"), tr("Exceptional error happened, program is exiting."));
        getch();
        exit(-1);
    };
}

void MainWindow::on_dispYValue_toggled(bool checked)
{
    if(newScanList.Scans[currentScanNumber-1].polSettings.size() == 3)
        newScanList.Scans[currentScanNumber-1].polSettings[1] = checked;
    else
    {
        QMessageBox::information(this, tr("Exceptional Error"), tr("Exceptional error happened, program is exiting."));
        getch();
        exit(-1);
    };
}

void MainWindow::on_dispZValue_toggled(bool checked)
{
    if(newScanList.Scans[currentScanNumber-1].polSettings.size() == 3)
        newScanList.Scans[currentScanNumber-1].polSettings[2] = checked;
    else
    {
        QMessageBox::information(this, tr("Exceptional Error"), tr("Exceptional error happened, program is exiting."));
        getch();
        exit(-1);
    };
}

void MainWindow::on_gridTabWidget_currentChanged(int index)
{

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
            break;
        }
        case EditState:
        {
            ui->loadGenericButton->show();
            ui->loadSettingsButton->show();
            ui->dispXValue->setEnabled(1);
            ui->dispYValue->setEnabled(1);
            ui->dispZValue->setEnabled(1);
            ui->gridTabWidget->setTabEnabled(1, true);
            ui->gridTabWidget->setTabEnabled(2, true);
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
    if(ui->setScanSpeed->text().isEmpty() || ui->setStartPosition->text().isEmpty() || ui->setTargetPosition->text().isEmpty() || ui->scanName->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error!"), tr("Not all neccessary information entered, please check your entered data!"));
        return;
    }
    struct Scan newScan;
    newScanList.Scans.push_back(newScan);
    currentScanNumber++;
    QMessageBox msgBox;
    msgBox.setText("Information.");
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
            newScanList.Scans[currentScanNumber-1].log.name = lineName->text();
            newScanList.Scans[currentScanNumber-1].log.laserIntensity = linePower->text().toDouble();
            newScanList.Scans[currentScanNumber-1].log.sensitivity = lineSens->text().toDouble();
            newScanList.Scans[currentScanNumber-1].log.countNumber = lineCount->text().toDouble();
            newScanList.Scans[currentScanNumber-1].log.slitWidth = lineSlit->text().toDouble();
            newScanList.Scans[currentScanNumber-1].log.logfileSet = true;
        }
        else
        {
            newScanList.Scans[currentScanNumber-1].log.logfileSet = false;
        }
    }
    ui->progressBar->show();
    ui->progressBar->setValue(1);
    newScan.finPos = ui->setTargetPosition->text().toDouble();
    newScan.startPos = ui->setStartPosition->text().toDouble();
    newScan.scanSpeed = ui->setScanSpeed->text().toDouble();
    newScan.scanName = ui->scanName->text();
    scanner *newScanner = new scanner(newScan.startPos, newScan.finPos, newScan.scanSpeed, newSpectrometer.MonoPos, (newScan.finPos-newScan.startPos)>0?true:false);
    connect(newScanner, SIGNAL(currentStatus(qreal)), SLOT(CurrentScanStatus(qreal)));
    connect(newScanner, SIGNAL(finished()), newScanner, SLOT(deleteLater()));
    connect(newScanner, SIGNAL(finished()), this, SLOT(closeProgressBar()));
    newScanner->start();
    //Analyze(MainWindow::newScanList);
}

void MainWindow::closeProgressBar()
{
    ui->progressBar->hide();
}

void MainWindow::CurrentScanStatus(qreal status)
{
    ui->progressBar->setValue((int)(status));
}

void MainWindow::on_LastScan_clicked()
{
    MainWindow::currentScan.values.Data.clear();
    MainWindow::replot();
    int tmpCurrentScanNumber = currentScanNumber - 1;
    tmpCurrentScanNumber = (tmpCurrentScanNumber <= 0)?MainWindow::newScanList.Scans.size() - 1:tmpCurrentScanNumber-1;
    MainWindow::currentScan = MainWindow::newScanList.Scans[tmpCurrentScanNumber];
    MainWindow::setWindowTitle(MainWindow::currentScan.scanName);
    currentScanNumber = tmpCurrentScanNumber + 1;
    MainWindow::replot();
}

void MainWindow::on_NextScan_clicked()
{
    MainWindow::currentScan.values.Data.clear();
    MainWindow::replot();
    int tmpCurrentScanNumber = currentScanNumber - 1;
    tmpCurrentScanNumber = (tmpCurrentScanNumber >= newScanList.Scans.size()-1)?0:tmpCurrentScanNumber+1;
    MainWindow::currentScan = MainWindow::newScanList.Scans[tmpCurrentScanNumber];
    currentScanNumber = tmpCurrentScanNumber + 1;
    MainWindow::setWindowTitle(MainWindow::currentScan.scanName);
    MainWindow::replot();
}

void MainWindow::on_selectScanBox_currentIndexChanged(int index)
{
    MainWindow::currentScanNumber = index + 1;
    MainWindow::replot();
}

void MainWindow::on_saveScan_clicked()
{
    saveGeneric();
}

void MainWindow::reload_data()
{
    ui->setScanSpeed->setText(QString::number(newScanList.Scans[currentScanNumber-1].scanSpeed));
    ui->setStartPosition->setText(QString::number(newScanList.Scans[currentScanNumber-1].startPos));
    ui->setTargetPosition->setText(QString::number(newScanList.Scans[currentScanNumber-1].finPos));
    ui->dispXValue->setChecked(newScanList.Scans[currentScanNumber-1].polSettings[0]);
    ui->dispYValue->setChecked(newScanList.Scans[currentScanNumber-1].polSettings[1]);
    ui->dispZValue->setChecked(newScanList.Scans[currentScanNumber-1].polSettings[2]);
    ui->scanName->setText(newScanList.Scans[currentScanNumber-1].scanName);
    ui->logfileName->setText(newScanList.Scans[currentScanNumber-1].log.name);
    ui->laserPower->setText(QString::number(newScanList.Scans[currentScanNumber-1].log.laserIntensity));
    ui->slitWidth->setText(QString::number(newScanList.Scans[currentScanNumber-1].log.slitWidth));
    ui->countNumber->setText(QString::number(newScanList.Scans[currentScanNumber-1].log.countNumber));
    ui->sensitivity->setText(QString::number(newScanList.Scans[currentScanNumber-1].log.sensitivity));
    ui->currentPosition->setText(QString::number(newSpectrometer.MonoPos));
    ui->currentSpeed->setText(QString::number(newSpectrometer.MonoSpeed));
    ui->currentWaveNumber->setText("Muss berechnet werden");
}

void MainWindow::on_stepBackMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    MonoNed(1, newSpectrometer.MonoPos);
}

void MainWindow::on_stepForwardMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    MonoOpp(1, newSpectrometer.MonoPos);
}

void MainWindow::on_mvButton_2_clicked()
{
    if(ui->moveData->text().toDouble() < 0)
        MonoNed(ui->moveData->text().toDouble(), newSpectrometer.MonoPos);
    else
        MonoOpp(ui->moveData->text().toDouble(), newSpectrometer.MonoPos);
}

//Muss noch verbessert werden, funktioniert noch nicht
//void MainWindow::customContextMenuRequested(const QPoint &pos)
//{
////    QModelIndex index=ui->qwtPlot->indexAt(pos);

//    QMenu *menu=new QMenu(this);
//    menu->addAction(new QAction("Action 1", this));
//    menu->addAction(new QAction("Action 2", this));
//    menu->addAction(new QAction("Action 3", this));
//    //menu->popup(ui->qwtPlot->viewport()->mapToGlobal(pos));
//}

void MainWindow::on_logButton_clicked()
{
    if(newScanList.Scans.isEmpty())
    {
        QMessageBox::information(this, "Error", "No scan is currently loaded!");
        return;
    }
    if(newScanList.Scans[currentScanNumber-1].log.logfileSet)
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
        newScanList.Scans[currentScanNumber-1].log.countNumber = ui->countNumber->text().toDouble();
        newScanList.Scans[currentScanNumber-1].log.laserIntensity = ui->laserPower->text().toDouble();
        newScanList.Scans[currentScanNumber-1].log.sensitivity = ui->sensitivity->text().toDouble();
        newScanList.Scans[currentScanNumber-1].log.slitWidth = ui->slitWidth->text().toDouble();
        newScanList.Scans[currentScanNumber-1].log.name = ui->logfileName->text();
        newScanList.Scans[currentScanNumber-1].log.logfileSet = true;
    }
    ui->gridTabWidget->setCurrentIndex(0);
}

void MainWindow::createLogData()
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
    in >> monoPos;
    in >> monoSpeed;
    newSpectrometer.MonoPos = monoPos.toDouble();
    newSpectrometer.MonoSpeed = monoSpeed.toDouble();
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
    out << newSpectrometer.MonoPos << '\n';
    out << newSpectrometer.MonoSpeed;
    file.close();
}

void MainWindow::on_activateCounter_clicked()
{
    newDPC->start();
}

void MainWindow::on_execButton_2_clicked()
{
    if(ui->newPosition->text().toDouble() != newSpectrometer.MonoPos)
        moveToTarget(ui->newPosition->text().toDouble(), newSpectrometer.MonoPos);
    else if(ui->newSpeed->text().toDouble() != newSpectrometer.MonoSpeed)
        newSpectrometer.MonoSpeed = ui->newSpeed->text().toDouble();
    reload_data();
}
