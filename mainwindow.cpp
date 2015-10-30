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
    MainWindow::newSpectrometer = new Spectrometer_Control(&mutex, &EngineMoving);
    MainWindow::calibrated = false;
    MainWindow::placed_correctly = false;
    ui->CalibratedBox->setDisabled(true);
    MainWindow::loadConfig();
    this->manualScan = false;
    ui->manual_confirmValue->setEnabled(false);
    //Setup of TX data in UI
    ui->ipAddress->setInputMask("000.000.000.000");

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
    ui->XValsLabel->hide();
    ui->change_Xvals->hide();
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
    ui->MovingProgressBar->setValue(0);
    ui->manual_ProgressBar->setValue(0);
    //ui->gridTabWidget->setTabEnabled(3, false);
    ui->movingBox->setDisabled(true);
    ui->currentPosition->setReadOnly(true);
    ui->currentWavelength->setReadOnly(true);
    ui->currentWaveNumber->setReadOnly(true);
    ui->photoCounter->setReadOnly(true);
    //ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    ui->currentPosition->setText(QString::number(this->currentPosition_local));
    ui->MovementLogFileComment->hide();
    ui->label_3->hide();
    ui->AddMovementCommentLog->hide();
    //ui->currentWavelength->setText(QString::number(newSpectrometer->getMonoSpeed()));

    //Some fancy stuff for style
    QString myStyleSheet = QString("QProgressBar{ border: 2px solid black; border-radius: 5px; text-align: center} QProgressBar::chunk { background: green; width: 10px; margin: 0.5px}");
    QString s = ui->progressBar->styleSheet().append(myStyleSheet);
    ui->progressBar->setStyleSheet(s);

    QList<QString> xvals;
    xvals.append("Wavenumbers");
    xvals.append("Wavelengths");
    ui->change_Xvals->addItems(xvals);
    this->xVals = false;
    this->logFinished = false;

    //Creating connections
    connect(newSpectrometer, &Spectrometer_Control::currentCounterData, this, &MainWindow::oncurrentCount);
    connect(newSpectrometer, &Spectrometer_Control::TX_status, this, &MainWindow::connectStatus);
    connect(newSpectrometer, &Spectrometer_Control::currentData, this, &MainWindow::incomingData);
    connect(newSpectrometer, &Spectrometer_Control::currentScanPosition, this, &MainWindow::CurrentScanStatus);
    connect(newSpectrometer, &Spectrometer_Control::scanFinished, this, &MainWindow::scanIsFinished);
    connect(newSpectrometer, &Spectrometer_Control::currentStatus, this, &MainWindow::newStepperStatus);
    connect(newSpectrometer, &Spectrometer_Control::SerialIsConnected, this, &MainWindow::serialConnectionUsed);
    //connect(newSpectrometer, &Spectrometer_Control::scanFinished, this, &MainWindow::PositionChanged);
    connect(newSpectrometer, &Spectrometer_Control::positionChanged, this, &MainWindow::PositionChanged);
    connect(newSpectrometer, &Spectrometer_Control::stepperIsStopped, this, &MainWindow::stepperStopped);
    connect(newSpectrometer, &Spectrometer_Control::stepperMoving, this, &MainWindow::StepperMoving);
    connect(plotPicker, SIGNAL(selected(const QPointF&)), this, SLOT(mousePoint(QPointF)));
    connect(this, &MainWindow::continue_scan, this, &MainWindow::continue_this_scan);
    ui->manual_confirmValue->setEnabled(false);
    //Thread work
    this->SshSocket = NULL;
    //set current state:
    changeState(EditState);
    //load current serial port list
    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();
    for(int i = 0; i < list.size(); i++)
        ui->serial_ComboBox->addItem(list[i].description());
    QList<QString> baudRateList;
    baudRateList.append(QString::number(300));
    baudRateList.append(QString::number(600));
    baudRateList.append(QString::number(1200));
    baudRateList.append(QString::number(2400));
    baudRateList.append(QString::number(4800));
    baudRateList.append(QString::number(9600));
    baudRateList.append(QString::number(19200));
    ui->lockin_baud_combo->addItems(baudRateList);
    QList<QString> stopBitList;
    stopBitList.append(QString::number(1));
    stopBitList.append(QString::number(2));
    ui->lockin_stop_combo->addItems(stopBitList);
    QList<QString> parityList;
    parityList.append("None");
    parityList.append("Even");
    parityList.append("Odd");
    ui->lockin_Parity->addItems(parityList);
    QList<QString> echoList;
    echoList.append("No echo mode");
    echoList.append("Echo mode");
    ui->lockin_EchoMode->addItems(echoList);
//    serial = new QSerialPort(this);

    //connect(serial, &QSerialPort::error, this, &MainWindow::handleError);
//    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
//            SLOT(handleError(QSerialPort::SerialPortError)));
//    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);

}

MainWindow::~MainWindow()
{
    MainWindow::writeConfig();
    emit stopCounting();
    emit stopControlling();
    emit killScanner();
    qDebug() << "Disconnecting SSH connection";
    if(this->SshSocket != NULL)
    {
        this->SshSocket->disconnectFromHost();
        qDebug() << "Disconnected from SSH Host";
        qDebug() << this->SshSocket;
        delete this->SshSocket;
    }
    qDebug() << "SSH disconnected!";
    qDebug() << "Cleaning main!";
    qDebug() << "SC, DPC and SC cleaned";
    delete MainWindow::newSpectrometer;
    qDebug() << "Scanner and Spec cleaned";
    delete MainWindow::plotPicker;
    qDebug() << "plotPicker cleaned";
    if(MainWindow::pickerMachine != NULL)
    {
        qDebug() << pickerMachine;
        //delete MainWindow::pickerMachine;//Leads to crash, strange
    }
    qDebug() << "pickerMachine cleaned";
    if(this->LogFile != NULL || this->LogStream != NULL || this->movementLogging != false)
    {
        this->LogFile->close();
        delete this->LogFile;
        delete this->LogStream;
    }
    qDebug() << "LogFile sauber";
    delete ui;
    qDebug() << "ui sauber";
}

void MainWindow::connectStatus(bool status)
{
    ui->MainTXcon->setChecked(status);
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
    if(newScanList.getLength() > 0)
    {
        if(newScanList.getCurrentScan().hasWN)
            vectorToMap(newScanList.getCurrentScan().getValues().getData()/*currentScan.values.Data*/, MainWindow::Scandata, this->xVals);
        else
            vectorToMap(newScanList.getCurrentScan().getValues().getData(), MainWindow::Scandata, false);
        x = QVector<double>::fromList(Scandata.keys());
        y = QVector<double>::fromList(Scandata.values());

        MainWindow::Curve.setSamples(x, y);
        MainWindow::Curve.attach(ui->qwtPlot);
        ui->qwtPlot->updateAxes();
        ui->qwtPlot->show();
        ui->qwtPlot->replot();
    }
    MainWindow::reload_data();
}

void MainWindow::open()//Missing update to v.4
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
        QVector<QPair<qreal, qreal> > Data_tmp;
        in >> Data_tmp;//newScan.setValues().setData();
        QVector<std::tuple<qreal, qreal, qreal> > Data;
        for(int i = 0; i < Data_tmp.size(); i++)
            Data.push_back(std::make_tuple(Data_tmp[i].first, 0, Data_tmp[i].second));
        newScan.setValues().setData() = Data;
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
            ui->change_Xvals->show();
            ui->XValsLabel->show();
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

void MainWindow::openGeneric()//Missing magic numbers?
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
            return;
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            MainWindow::newScanList.addScan(newScan);
            MainWindow::newScanList.addFileName(fileName);
            ui->change_Xvals->show();
            ui->XValsLabel->show();
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
        QVector<QPair<double, double> > DataVector;
        for(int i = 0; i < MainWindow::newScanList.getCurrentScan().values.Data.size(); i++)
            DataVector.push_back(qMakePair(std::get<0>(MainWindow::newScanList.getCurrentScan().values.Data[i]), std::get<2>(MainWindow::newScanList.getCurrentScan().values.Data[i])));
        out.setVersion(QDataStream::Qt_4_5);//Hier muss noch Portabilität eingebaut werden, siehe auch http://qt-project.org/doc/qt-4.8/qdatastream.html
        if(MainWindow::newScanList.getScanNumbers()!=0)
        {
            out << MainWindow::newScanList.getCurrentScan().scanName;
            qint32 monoSetting = (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[0]) + (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[1])*2 + (int)(MainWindow::newScanList.getCurrentScan().Params.polSettings[2])*4;
            out << monoSetting;
            out << MainWindow::newScanList.getCurrentScan().Params.startPos;
            out << MainWindow::newScanList.getCurrentScan().Params.finPos;
            out << MainWindow::newScanList.getCurrentScan().Params.scanSpeed;
            out << DataVector;
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
    //Maybe result in crash!???
    delete yes;
    delete no;
    //Maybe result in crash???
    yes = NULL;
    no = NULL;
    //Analyze(MainWindow::newScanList);
}

void MainWindow::incomingData(QPair<int, int> data)
{
    tmpScan.values.Data.push_back(std::make_tuple(data.first + ui->setStartPosition->text().toInt(), 0, data.second));
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
    return qMakePair(qMakePair(0, 0), qMakePair(0, 0));
}

int MainWindow::calculateValue(std::tuple<int, int, int> targetTuple, QPair<int, int> firstPoint = qMakePair(0, 0), QPair<int, int> secondPoint = qMakePair(0, 0))
{
    QPair<int, int> targetPoint = qMakePair(std::get<0>(targetTuple), std::get<2>(targetTuple));
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
        QPair<QPair<int, int>, QPair<int, int> > nextPoints = getNearestPoints(std::get<0>(newScan.Data[i]));
        std::get<0>(newScan.Data[i]) = calculateValue(newScan.Data[i], nextPoints.first, nextPoints.second);
    }
}

void MainWindow::scanIsFinished(void)
{

//    if(this->manualScan == false)
//    {

//    }
//    else
//    {
//        if(this->current_step == 0)
//            this->createLogFile();
//        else
//            this->startManualMeasurement();
//    }
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
    tmpScan.values.Data.push_back(std::make_tuple(wNumber, 0, counts));
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
    //ui->currentPosition->setText(QString::number(newSpectrometer->getMonoPos()));
    ui->currentPosition->setText(QString::number(this->currentPosition_local));
    //ui->currentWavelength->setText(QString::number(newSpectrometer->getMonoSpeed()));
    ui->newPosition->clear();
    ui->newWaveNumber->clear();
    ui->newWavelength->clear();
    //if(!calibrated)
    //int currentPos = newSpectrometer->getMonoPos();
    int currentPos = this->currentPosition_local;
    double waveNumber = convertPosToWN(currentPos);
    ui->currentWaveNumber->setText(QString::number(waveNumber));
    ui->currentWavelength->setText(QString::number(convertWNtoWL(waveNumber)));
    ui->manual_currWaveLength->setReadOnly(true);
    ui->manual_currWaveLength->setText(QString::number(convertWNtoWL(waveNumber)));
    ui->manual_currWaveNum->setReadOnly(true);
    ui->manual_currWaveNum->setText(QString::number(waveNumber));
    /*else
    {
        ui->currentWaveNumber->setText(QString::number(calculateValue(qMakePair(ui->currentPosition->text().toInt(), 0), CorrectionValues.first(), CorrectionValues.last())));
    }*/
}

void MainWindow::on_stepBackMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    if(this->currentPosition_local == 0)
    {
        qDebug() << "Moving down not possible!";
        return;
    }
    newSpectrometer->moveStepper(1, 0);
    this->currentPosition_local--;
    //emit MoveStepDown(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() - 1);
    reload_data();
    //Muss ausgebaut werden
    //MonoNed(1, newSpectrometer.getMonoPos());
}

void MainWindow::on_stepForwardMono_clicked()
{
    //CHECK IF STOP NOT HERE???
    if(this->currentPosition_local == 99999/0.0048)
    {
        qDebug() << "Moving up not possible!";
        return;
    }
    newSpectrometer->moveStepper(1, 1);
    this->currentPosition_local++;
    //emit MoveStepUp(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() + 1);
    reload_data();
}

void MainWindow::on_mvButton_2_clicked()
{
    if(this->movementLogging)
        this->logThis(QVariant(ui->moveData->text().toDouble()));
    if(ui->moveData->text().toDouble() < 0)
    {   //Hier müssen Signale und Slots rein!
        newSpectrometer->moveStepper(fabs(ui->moveData->text().toInt()), 0);
        this->currentPosition_local -= fabs(ui->moveData->text().toInt());
        //emit MoveStepDown(newSpectrometer->getMonoPos(), newSpectrometer->getMonoPos() + ui->moveData->text().toInt());
        ui->moveData->setText("");
    }
    else
    {
        newSpectrometer->moveStepper(fabs(ui->moveData->text().toInt()), 1);
        this->currentPosition_local += fabs(ui->moveData->text().toInt());
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
            delete replace;
            delete cancel;
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
    this->currentPosition_local = monoPos.toDouble();
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
    this->reload_data();
}

void MainWindow::oncurrentCount(double counts)
{
    qDebug() << "New counts: " << QString::number(counts);
    qDebug() << "New counts: " << counts;
    ui->photoCounter->setText(QString::number(counts));
    if(ui->manual_automat->isChecked())
        emit this->continue_scan(counts);
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
    //out << newSpectrometer->getMonoPos() << '\n';
    out << this->currentPosition_local << '\n';
    //out << newSpectrometer->getMonoSpeed() << '\n';
    out << (int)(newSpectrometer->getPolarizers()[0])*1 + (int)(newSpectrometer->getPolarizers()[1])*2 + (int)(newSpectrometer->getPolarizers()[2])*4 << '\n';
    if(calibrated == true)
        out << CalibrationData;
    file.close();
}

void MainWindow::on_execButton_2_clicked()
{
    //Max-/Min-Limit should be implemented!
    //Log should be implemented!!
    if(/*(ui->newPosition->text().toInt() != /*newSpectrometer->getMonoPos() this->currentPosition_local) && !ui->newPosition->text().isEmpty()*/ui->newPosition->text().isEmpty() == false)
    {
        //newSpectrometer->moveStepper(fabs(newSpectrometer->getMonoPos() - ui->newPosition->text().toInt()), ((ui->newPosition->text().toInt() - newSpectrometer->getMonoPos()) >= 0));
        qDebug() << "New moving position is: " << ui->newPosition->text();
        double targetPosition = ui->newPosition->text().toDouble();
        newSpectrometer->moveStepper(fabs(this->currentPosition_local - targetPosition), ((targetPosition - this->currentPosition_local) >= 0));
        if(targetPosition >= this->currentPosition_local)
            this->currentPosition_local = targetPosition;
        else
            this->currentPosition_local = targetPosition;
        reload_data();

        return;
    }
    else if(/*ui->newWaveNumber->text().toDouble() != convertPosToWN(/*newSpectrometer->getMonoPos()this->currentPosition_local) && */!ui->newWaveNumber->text().isEmpty())
    {
        //newSpectrometer->moveStepper(fabs(convertWNtoPos(ui->newWaveNumber->text().toDouble()) - newSpectrometer->getMonoPos()), convertWNtoPos(ui->newWaveNumber->text().toDouble()) >= newSpectrometer->getMonoPos());
        double targetWN = ui->newWaveNumber->text().toDouble();
        qDebug() << "New WN-value is: " << targetWN;
        double new_position = convertWNtoPos(targetWN);
        qDebug() << "Current new position is: " << new_position;
        qDebug() << "Position difference is: " << new_position - this->currentPosition_local;
        newSpectrometer->moveStepper(fabs(new_position - this->currentPosition_local), new_position >= this->currentPosition_local);
        this->currentPosition_local = new_position;
        reload_data();

        return;
    }
    else if(!(ui->newWavelength->text().isEmpty()))
    {
        //newSpectrometer->moveStepper(fabs(convertWLtoPos(ui->newWavelength->text().toDouble()) - newSpectrometer->getMonoPos()), convertWLtoPos(ui->newWavelength->text().toDouble()) >= newSpectrometer->getMonoPos());
        double targetWL = ui->newWavelength->text().toDouble();
        qDebug() << "New WL-value is: " << QString::number((int)(convertWLtoPos(targetWL)));
        qDebug() << "Old WL-value is: " << QString::number(this->currentPosition_local);
        qDebug() << "Movement difference is: " << convertWLtoPos(targetWL) - this->currentPosition_local;
        newSpectrometer->moveStepper(fabs(convertWLtoPos(targetWL) - this->currentPosition_local), convertWLtoPos(targetWL) >= this->currentPosition_local);
        this->currentPosition_local = convertWLtoPos(targetWL);
        reload_data();

        return;
    }
    return;

}

void MainWindow::StepperMoving(void)
{
    //qDebug() << "Stepper moving!";
    ui->movingBox2->setChecked(true);
    ui->movingBox->setChecked(true);
    ui->manual_confirmValue->setEnabled(false);
    reload_data();
}

void MainWindow::PositionChanged()
{
    this->stepperStopped();
    reload_data();
    //qDebug() << "STP finished!";
}

void MainWindow::on_gridTabWidget_currentChanged(int index)
{
    int i = index;
    i++;
    reload_data();
}

void MainWindow::newStepperStatus(int status)
{
    ui->MovingProgressBar->setValue(status);
    this->reload_data();
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
    this->SshSocket = new qsshsocket;
    qDebug() << "Socket starting";
    this->SshSocket->start();
    qDebug() << "Socket connecting";
    this->SshSocket->connectToHost(ui->ipAddress->text());
    qDebug() << "Is connected? " << this->SshSocket->isConnected();
    qDebug() << "Socket logging in";
    this->SshSocket->login("root", "");
    qDebug() << "Is logged in? " << this->SshSocket->isLoggedIn();
    qDebug() << "Socket executing command";
    this->SshSocket->executeCommand("/home/debian/qt-workspace/remoteController_revII/remoteController_revII");
    sleep(1);
    qDebug() << "Is disconnected? " << this->SshSocket->isConnected();
    qDebug() << "Connecting now!";
    sleep(1);
    newSpectrometer->useRemote(ui->ipAddress->text(), 50000);
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


void MainWindow::on_AddMovementLog_clicked()
{
    //qDebug() << "Logging started!";
    ui->LoggingBox->setChecked(true);
    if(ui->MovementLogFileName->text().isEmpty())
    {
        //qDebug() << "Filename is missing";
        this->MovementLogFile = QDate::currentDate().toString();
    }
    else
    {
        this->MovementLogFile = ui->MovementLogFileName->text();
    }
    this->LogFile = new QFile(this->MovementLogFile);
    this->LogFile->open(QIODevice::ReadWrite);
    this->LogStream = new QTextStream(this->LogFile);
    ui->label_2->show();
    ui->label_3->show();
    ui->AddMovementCommentLog->show();
    ui->MovementLogFileComment->show();
    ui->MovementLogFileName->show();
    this->movementLogging = true;
}

void MainWindow::logThis(QVariant data)
{
    //qDebug() << "Logging this: " + data.toString();
    *(this->LogStream) << data.toString() << '\n';
}

void MainWindow::on_AddMovementCommentLog_clicked()
{
    this->logThis(QVariant(ui->MovementLogFileComment->text()));
    ui->MovementLogFileComment->clear();
}

void MainWindow::on_manual_StartMeasurement_clicked()
{
    ui->manual_ProgressBar->setValue(0);

    if(ui->manual_StartWL->text().isEmpty() || ui->manual_StopWL->text().isEmpty() || ui->manual_Steps->text().isEmpty() || ui->manual_centralWL->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error"), QString("Not all neccessary information entered, please try again!"));
        return;
    }
    if(ui->manual_StartWL->text().toDouble() > ui->manual_StopWL->text().toDouble())
    {
        QMessageBox::information(this, tr("Error"), QString("Start wavelength is bigger than stop wavelength, please try again!"));
        ui->manual_StartWL->setText(QString(""));
        ui->manual_StopWL->setText(QString(""));
        return;
    }
    if(ui->manual_Steps->text().toInt() <= 0)
    {
        QMessageBox::information(this, tr("Error"), QString("Impossible step value entered!"));
        ui->manual_Steps->setText(QString(""));
        return;
    }
    ui->manual_numAqu->setReadOnly(true);
    ui->manual_StartWL->setReadOnly(true);
    ui->manual_StopWL->setReadOnly(true);
    ui->manual_Steps->setReadOnly(true);
    ui->manual_centralWL->setReadOnly(true);
    //double currentPosition = newSpectrometer->getMonoPos();
    double currentPosition = this->currentPosition_local;
    double startWL = ui->manual_StartWL->text().toDouble();
    double newPosition = convertWLtoPos(startWL);
    this->manualScan = true;
    newSpectrometer->setAquisitions(ui->manual_numAqu->text().toInt());
    newSpectrometer->moveStepper(fabs(currentPosition - newPosition), (currentPosition < newPosition));
    this->createLogFile();
    this->currentPosition_local = newPosition;
    ui->manual_confirmValue->setEnabled(true);
}

void MainWindow::createLogFile()
{
    this->placed_correctly = true;
    QMessageBox::information(this, tr("Information"), QString("Spectrometer is adjusted, please continue with the other button!"));
    QMessageBox msgBox;
    //msgBox.setText("Information.");
    msgBox.setInformativeText("Do you want add a config file?");
    QPushButton *yes = msgBox.addButton(tr("&Yes"), QMessageBox::ActionRole);
    QPushButton *no = msgBox.addButton(tr("&No"), QMessageBox::ActionRole);
    msgBox.exec();
    ui->manual_StartMeasurement->setEnabled(false);
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
    tmpScan.hasWN = true;
    tmpScan.Params.finPos = ui->manual_StopWL->text().toDouble();
    tmpScan.Params.startPos = ui->manual_StartWL->text().toDouble();
    if(ui->manualScanName->text().isEmpty() == true)
        tmpScan.scanName = QString("Manual Scan");
    else
        tmpScan.scanName = ui->manualScanName->text();
    tmpScan.isCalibrated = this->calibrated;
    tmpScan.Central_WL = ui->manual_centralWL->text().toDouble();
    delete yes;
    delete no;
    yes = NULL;
    no = NULL;
    ui->manual_StartWL->setReadOnly(true);
    ui->manual_StopWL->setReadOnly(true);
    ui->manual_Steps->setReadOnly(true);
    this->current_step = 0;
    if(ui->movingBox2->isChecked())
        this->logFinished = true;
    else
        newSpectrometer->get_analog_value();
}

void MainWindow::continue_this_scan(double counts)
{
    this->reload_data();
    double current_Value = counts;
    ui->manual_currentValue->setText(QString::number(counts));
    tmpScan.values.Data.push_back(std::make_tuple(convertWNtoWL(ui->manual_currWaveNum->text().toDouble()), ui->manual_CentralWN->text().toDouble() - convertPosToWN(this->currentPosition_local), current_Value));
    double WL_difference = ui->manual_StopWL->text().toDouble() - ui->manual_StartWL->text().toDouble();
    double WL_stepSize = WL_difference/ui->manual_Steps->text().toDouble();
    ui->manual_ProgressBar->setValue((int)((double)(this->current_step)/ui->manual_Steps->text().toDouble()*100));
    if(current_step == ui->manual_Steps->text().toInt())
    {
        QMessageBox::information(this, tr("Information"), QString("Scan finished, returning!"));
        ui->manual_automat->setChecked(false);
        ui->manual_StartWL->setReadOnly(false);
        ui->manual_StartMeasurement->setEnabled(true);
        this->placed_correctly = false;
        this->current_step = 0;
        this->manualScan = false;
        ui->manual_StartWL->setText(QString(""));
        ui->manual_StopWL->setText(QString(""));
        ui->manual_StopWL->setReadOnly(false);
        ui->manual_numAqu->setReadOnly(false);
        ui->manual_ProgressBar->setValue(0);
        ui->manual_centralWL->setReadOnly(false);
        ui->manual_Steps->setReadOnly(false);
        ui->manual_centralWL->setText("");
        ui->manual_Steps->setText(QString(""));
        newScanList.addScan(this->tmpScan);
        newScanList.getNextScan();
        ui->selectScanBox->addItem(newScanList.getCurrentScan().scanName);
        this->tmpScan.clear();
        this->reload_data();
        this->replot();
        this->logFinished = false;
        ui->manual_confirmValue->setEnabled(false);
        return;
    }
    else
    {
        double next_step_size = convertWLtoPos(convertPosToWL(this->currentPosition_local) + WL_stepSize) - this->currentPosition_local;
        qDebug() << "Current step is: " << this->current_step;
        qDebug() << "Current step size is: " << next_step_size;
        this->current_step += 1;
        newSpectrometer->moveStepper(next_step_size, true);
        this->currentPosition_local += next_step_size;
        return;
    }
}

void MainWindow::on_manual_confirmValue_clicked()
{
    this->reload_data();
    if(this->placed_correctly == false)
    {
        QMessageBox::information(this, tr("Error"), QString("Please use the ""Start measurement""-button before using this button."));
        return;
    }
    if(ui->manual_currentValue->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error"), QString("Please enter a value in the value line edit!"));
        return;
    }
    double current_Value = ui->manual_currentValue->text().toDouble();
    ui->manual_currentValue->setText("");
    tmpScan.values.Data.push_back(std::make_tuple(convertWNtoWL(ui->manual_currWaveNum->text().toDouble()), ui->manual_CentralWN->text().toDouble() - convertPosToWN(this->currentPosition_local), current_Value));
    double WL_difference = ui->manual_StopWL->text().toDouble() - ui->manual_StartWL->text().toDouble();
    double WL_stepSize = WL_difference/ui->manual_Steps->text().toDouble();
    ui->manual_ProgressBar->setValue((int)((double)(this->current_step)/ui->manual_Steps->text().toDouble()*100));
    if(current_step == ui->manual_Steps->text().toInt())
    {
        QMessageBox::information(this, tr("Information"), QString("Scan finished, returning!"));
        ui->manual_StartWL->setReadOnly(false);
        ui->manual_StartMeasurement->setEnabled(true);
        this->placed_correctly = false;
        this->current_step = 0;
        ui->manual_ProgressBar->setValue(0);
        this->manualScan = false;
        ui->manual_StartWL->setText(QString(""));
        ui->manual_StopWL->setText(QString(""));
        ui->manual_StopWL->setReadOnly(false);
        ui->manual_numAqu->setReadOnly(false);
        ui->manual_centralWL->setReadOnly(false);
        ui->manual_Steps->setReadOnly(false);
        ui->manual_centralWL->setText("");
        ui->manual_Steps->setText(QString(""));
        newScanList.addScan(this->tmpScan);
        newScanList.getNextScan();
        ui->selectScanBox->addItem(newScanList.getCurrentScan().scanName);
        this->tmpScan.clear();
        this->reload_data();
        this->replot();
        this->logFinished = false;
        ui->manual_confirmValue->setEnabled(false);
        return;
    }
    else
    {
        double next_step_size = convertWLtoPos(convertPosToWL(this->currentPosition_local) + WL_stepSize) - this->currentPosition_local;
        qDebug() << "Current step is: " << this->current_step;
        qDebug() << "Current step size is: " << next_step_size;
        this->current_step += 1;
        newSpectrometer->moveStepper(next_step_size, true);
        this->currentPosition_local += next_step_size;
        return;
    }
}

void MainWindow::stepperStopped()
{
    ui->movingBox2->setChecked(false);
    ui->movingBox->setChecked(false);
    ui->manual_confirmValue->setEnabled(true);
    if(this->logFinished)
        this->newSpectrometer->get_analog_value();
    return;
}

void MainWindow::on_manual_centralWL_textEdited(const QString &arg1)
{
    ui->manual_CentralWN->setText(QString::number(convertWLtoWN(arg1.toDouble())));
}

void MainWindow::on_manual_StartWL_textEdited(const QString &arg1)
{
    ui->manual_StartWN->setText(QString::number(convertWLtoWN(arg1.toDouble())));
}

void MainWindow::on_manual_StopWL_textEdited(const QString &arg1)
{
    ui->manual_StopWN->setText(QString::number(convertWLtoWN(arg1.toDouble())));
}

void MainWindow::on_manual_CentralWN_textEdited(const QString &arg1)
{
    ui->manual_centralWL->setText(QString::number(convertWNtoWL(arg1.toDouble())));
}

void MainWindow::on_manual_StartWN_textEdited(const QString &arg1)
{
    ui->manual_StartWL->setText(QString::number(convertWNtoWL(arg1.toDouble())));
}

void MainWindow::on_manual_StopWN_textEdited(const QString &arg1)
{
    ui->manual_StopWL->setText(QString::number(convertWNtoWL(arg1.toDouble())));
}

void MainWindow::on_manual_currWaveNum_textChanged(const QString &arg1)
{
    if(ui->manual_CentralWN->text().isEmpty() == false)
        ui->manual_DeltaWN->setText(QString::number(ui->manual_CentralWN->text().toDouble() - convertPosToWN(this->currentPosition_local)));
}

void MainWindow::on_manual_CentralWN_textChanged(const QString &arg1)
{
    ui->manual_DeltaWN->setText(QString::number(convertPosToWN(this->currentPosition_local) - ui->manual_CentralWN->text().toDouble()));
}

void MainWindow::on_connect_serial_clicked()
{
    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();
    this->BaudRate = 0;
    this->parity = true;
    int switchSetting = (ui->lockin_1up->isChecked()?1:0)*4+(ui->lockin_2up->isChecked()?1:0)*2 + (ui->lockin_3up->isChecked()?1:0);
    switch(switchSetting)
    {
    case 1:
        this->BaudRate = 2400;
        ui->lockin_baud_combo->setCurrentIndex(3);
        break;
    case 2:
        this->BaudRate = 600;
        ui->lockin_baud_combo->setCurrentIndex(1);
        break;
    case 3:
        this->BaudRate = 9600;
        ui->lockin_baud_combo->setCurrentIndex(5);
        break;
    case 4:
        this->BaudRate = 300;
        ui->lockin_baud_combo->setCurrentIndex(0);
        break;
    case 5:
        this->BaudRate = 4800;
        ui->lockin_baud_combo->setCurrentIndex(4);
        break;
    case 6:
        this->BaudRate = 1200;
        ui->lockin_baud_combo->setCurrentIndex(2);
        break;
    case 7:
        this->BaudRate = 19200;
        ui->lockin_baud_combo->setCurrentIndex(6);
        break;
    default:
        this->BaudRate = 9600;
        break;
    }
    this->parity = ui->lockin_4up->isChecked();
    this->useParity = ui->lockin_5down->isChecked();
    bool echoMode = ui->lockin_6down->isChecked();
    this->numStopBits = (ui->lockin_7up->isChecked()?2:1);
//    serial->setPortName(list[ui->serial_ComboBox->currentIndex()].portName());
//    serial->setBaudRate(this->BaudRate);
//    serial->setDataBits(QSerialPort::Data8);
//    serial->setParity(QSerialPort::NoParity);
//    serial->setStopBits((this->numStopBits==1)?QSerialPort::OneStop:QSerialPort::TwoStop);
//    serial->setFlowControl(QSerialPort::NoFlowControl);
//    if (serial->open(QIODevice::ReadWrite)) {
//        qDebug() << tr("Connected to %1 : %2, %3, %4, %5, %6")
//                          .arg(list[ui->serial_ComboBox->currentIndex()].portName()).arg(this->BaudRate).arg(QSerialPort::Data8)
//                          .arg(QSerialPort::NoParity).arg((this->numStopBits==1)?QSerialPort::OneStop:QSerialPort::TwoStop).arg(QSerialPort::NoFlowControl);
//    } else {
//        QMessageBox::critical(this, tr("Error"), serial->errorString());

//        //showStatusMessage(tr("Open error"));
//    }
//    if(echoMode != true)
//    {
//        QMessageBox::information(this, tr("Error"),tr("Please set the echo switch (Switch 6) to ""Down"". Then try again!"));
//        return;
//    }
    this->newSpectrometer->initSerial(list[ui->serial_ComboBox->currentIndex()].portName(), 1000, this->BaudRate, this->numStopBits, this->parity, this->useParity, echoMode);
    qDebug() << "Current serial is: " << list[ui->serial_ComboBox->currentIndex()].portName();
    //this->newSpectrometer->get_analog_value();
}

void MainWindow::on_serial_transmitt_clicked()
{
    this->newSpectrometer->get_analog_value();
//    QString data = "Q1\x00D";
//    serial->write(data.toLocal8Bit());
//    qDebug() << data;
}

void MainWindow::serialConnectionUsed(bool status)
{
    if(status == true)
    {
        ui->serialCheckbox->setChecked(true);
        ui->serialCheckbox->setDisabled(true);
        ui->connect_serial->setDisabled(true);
    }
}

void MainWindow::on_lockin_1up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_1up->setEnabled(true);
        ui->lockin_1down->setEnabled(false);
    }
    else
    {
        ui->lockin_1up->setEnabled(false);
        ui->lockin_1down->setEnabled(true);
    }
}

void MainWindow::on_lockin_2up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_2up->setEnabled(true);
        ui->lockin_2down->setEnabled(false);
    }
    else
    {
        ui->lockin_2up->setEnabled(false);
        ui->lockin_2down->setEnabled(true);
    }
}

void MainWindow::on_lockin_3up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_3up->setEnabled(true);
        ui->lockin_3down->setEnabled(false);
    }
    else
    {
        ui->lockin_3up->setEnabled(false);
        ui->lockin_3down->setEnabled(true);
    }
}

void MainWindow::on_lockin_4up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_4up->setEnabled(true);
        ui->lockin_4down->setEnabled(false);
    }
    else
    {
        ui->lockin_4up->setEnabled(false);
        ui->lockin_4down->setEnabled(true);
    }
}

void MainWindow::on_lockin_5up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_5up->setEnabled(true);
        ui->lockin_4up->setEnabled(false);
        ui->lockin_4down->setEnabled(false);
        ui->lockin_4up->setChecked(false);
        ui->lockin_4down->setChecked(false);
        ui->lockin_5down->setEnabled(false);
    }
    else
    {
        ui->lockin_5up->setEnabled(false);
        ui->lockin_4down->setEnabled(true);
        ui->lockin_4up->setEnabled(true);
        ui->lockin_5down->setEnabled(true);
    }
}

void MainWindow::on_lockin_6up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_6up->setEnabled(true);
        ui->lockin_6down->setEnabled(false);
    }
    else
    {
        ui->lockin_6up->setEnabled(false);
        ui->lockin_6down->setEnabled(true);
    }
}

void MainWindow::on_lockin_7up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_7up->setEnabled(true);
        ui->lockin_7down->setEnabled(false);
    }
    else
    {
        ui->lockin_7up->setEnabled(false);
        ui->lockin_7down->setEnabled(true);
    }
}

void MainWindow::on_lockin_8up_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_8up->setEnabled(true);
        ui->lockin_8down->setEnabled(false);
    }
    else
    {
        ui->lockin_8up->setEnabled(false);
        ui->lockin_8down->setEnabled(true);
    }
}

void MainWindow::on_lockin_1down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_1up->setEnabled(false);
        ui->lockin_1down->setEnabled(true);
    }
    else
    {
        ui->lockin_1up->setEnabled(true);
        ui->lockin_1down->setEnabled(false);
    }
}

void MainWindow::on_lockin_2down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_2up->setEnabled(false);
        ui->lockin_2down->setEnabled(true);
    }
    else
    {
        ui->lockin_2up->setEnabled(true);
        ui->lockin_2down->setEnabled(false);
    }
}

void MainWindow::on_lockin_3down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_3up->setEnabled(false);
        ui->lockin_3down->setEnabled(true);
    }
    else
    {
        ui->lockin_3up->setEnabled(true);
        ui->lockin_3down->setEnabled(false);
    }
}

void MainWindow::on_lockin_4down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_4up->setEnabled(false);
        ui->lockin_4down->setEnabled(true);
    }
    else
    {
        ui->lockin_4up->setEnabled(true);
        ui->lockin_4down->setEnabled(false);
    }
}

void MainWindow::on_lockin_5down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_5up->setEnabled(false);
        ui->lockin_5down->setEnabled(true);
        ui->lockin_4down->setEnabled(true);
        ui->lockin_4up->setEnabled(true);
        ui->lockin_4down->setChecked(true);
        ui->lockin_4up->setChecked(true);
    }
    else
    {
        ui->lockin_4down->setEnabled(false);
        ui->lockin_4up->setEnabled(false);
        ui->lockin_4down->setChecked(false);
        ui->lockin_4up->setChecked(false);
        ui->lockin_5up->setEnabled(true);
        ui->lockin_5down->setEnabled(false);
    }
}

void MainWindow::on_lockin_6down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_6up->setEnabled(false);
        ui->lockin_6down->setEnabled(true);
    }
    else
    {
        ui->lockin_6up->setEnabled(true);
        ui->lockin_6down->setEnabled(false);
    }
}

void MainWindow::on_lockin_7down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_7up->setEnabled(false);
        ui->lockin_7down->setEnabled(true);
    }
    else
    {
        ui->lockin_7up->setEnabled(true);
        ui->lockin_7down->setEnabled(false);
    }
}

void MainWindow::on_lockin_8down_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->lockin_8up->setEnabled(false);
        ui->lockin_8down->setEnabled(true);
    }
    else
    {
        ui->lockin_8up->setEnabled(true);
        ui->lockin_8down->setEnabled(false);
    }
}

void MainWindow::set_1(bool status)
{
    if(status)
    {
        ui->lockin_1up->setChecked(true);
        ui->lockin_1down->setChecked(false);
    }
    else
    {
        ui->lockin_1up->setChecked(false);
        ui->lockin_1down->setChecked(true);
    }
}

void MainWindow::set_2(bool status)
{
    if(status)
    {
        ui->lockin_2up->setChecked(true);
        ui->lockin_2down->setChecked(false);
    }
    else
    {
        ui->lockin_2up->setChecked(false);
        ui->lockin_2down->setChecked(true);
    }
}

void MainWindow::set_3(bool status)
{
    if(status)
    {
        ui->lockin_3up->setChecked(true);
        ui->lockin_3down->setChecked(false);
    }
    else
    {
        ui->lockin_3up->setChecked(false);
        ui->lockin_3down->setChecked(true);
    }
}

void MainWindow::set_4(bool status)
{
    if(status)
    {
        ui->lockin_4up->setChecked(true);
        ui->lockin_4down->setChecked(false);
    }
    else
    {
        ui->lockin_4up->setChecked(false);
        ui->lockin_4down->setChecked(true);
    }
}

void MainWindow::set_5(bool status)
{
    if(status)
    {
        ui->lockin_5up->setChecked(true);
        ui->lockin_5down->setChecked(false);
    }
    else
    {
        ui->lockin_5up->setChecked(false);
        ui->lockin_5down->setChecked(true);
    }
}

void MainWindow::set_6(bool status)
{
    if(status)
    {
        ui->lockin_6up->setChecked(true);
        ui->lockin_6down->setChecked(false);
    }
    else
    {
        ui->lockin_6up->setChecked(false);
        ui->lockin_6down->setChecked(true);
    }
}

void MainWindow::set_7(bool status)
{
    if(status)
    {
        ui->lockin_7up->setChecked(true);
        ui->lockin_7down->setChecked(false);
    }
    else
    {
        ui->lockin_7up->setChecked(false);
        ui->lockin_7down->setChecked(true);
    }
}

void MainWindow::set_8(bool status)
{
    if(status)
    {
        ui->lockin_8up->setChecked(true);
        ui->lockin_8down->setChecked(false);
    }
    else
    {
        ui->lockin_8up->setChecked(false);
        ui->lockin_8down->setChecked(true);
    }
}


void MainWindow::on_lockin_baud_combo_currentIndexChanged(const QString &arg1)
{
    this->BaudRate = arg1.toInt();
    switch(this->BaudRate)
    {
    case 2400:
        this->set_1(false);
        this->set_2(false);
        this->set_3(true);
        break;
    case 600:
        this->set_1(false);
        this->set_2(true);
        this->set_3(false);
        break;
    case 9600:
        this->set_1(false);
        this->set_2(true);
        this->set_3(true);
        break;
    case 300:
        this->set_1(true);
        this->set_2(false);
        this->set_3(false);
        break;
    case 4800:
        this->set_1(true);
        this->set_2(false);
        this->set_3(true);
        break;
    case 1200:
        this->set_1(true);
        this->set_2(true);
        this->set_3(false);
        break;
    case 19200:
        this->set_1(true);
        this->set_2(true);
        this->set_3(true);
        break;
    default:
        this->set_1(false);
        this->set_2(true);
        this->set_3(true);
    }
    int switchSetting = (ui->lockin_1up->isChecked()?1:0)*4+(ui->lockin_2up->isChecked()?1:0)*2 + (ui->lockin_3up->isChecked()?1:0);
    switch(switchSetting)
    {
    case 1:
        this->BaudRate = 2400;
        break;
    case 2:
        this->BaudRate = 600;
        break;
    case 3:
        this->BaudRate = 9600;
        break;
    case 4:
        this->BaudRate = 300;
        break;
    case 5:
        this->BaudRate = 4800;
        break;
    case 6:
        this->BaudRate = 1200;
        break;
    case 7:
        this->BaudRate = 19200;
        break;
    default:
        this->BaudRate = 9600;
        break;
    }
}

void MainWindow::on_lockin_stop_combo_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "1")
        this->set_7(false);
    else
        this->set_7(true);
}

void MainWindow::on_lockin_Parity_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "None")
        this->set_5(true);
    else if(arg1 == "Even")
    {
        this->set_5(false);
        this->set_4(false);
    }
    else if(arg1 == "Odd")
    {
        this->set_5(false);
        this->set_4(true);
    }
    else
        this->set_5(true);
}

void MainWindow::on_lockin_EchoMode_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "No echo mode")
        this->set_6(true);
    else
        this->set_6(false);
}

void MainWindow::on_UpdateCurrentPosition_clicked()
{
    this->currentPosition_local = ui->updateCurrentPositionLine->text().toDouble()/0.0048;
    ui->updateCurrentPositionLine->setText("");
    this->reload_data();
}

void MainWindow::on_manual_CancelScan_clicked()
{

}

void MainWindow::on_change_Xvals_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Wavenumbers")
        this->xVals = true;
    else
        this->xVals = false;
    this->replot();
}
