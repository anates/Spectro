#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::polarizerSettings.resize(3);
    createActions();
    createMenus();
    ui->loadGenericButton->setToolTip(tr("Load scan from a file"));
    //ui->saveButton->setToolTip(tr("Save scan to a file"));
    ui->scanButton->setToolTip("Start scan");
    ui->horizontalLayout_2->setStretchFactor(ui->qwtPlot, 19);
    ui->horizontalLayout_2->setStretchFactor(ui->formLayout_2, 1);
    MainWindow::currentScanNumber = 0;
    ui->LastScan->hide();
    ui->NextScan->hide();
    ui->ChooseScanLabel->hide();
    ui->selectScanBox->hide();
    ui->selectScanLabel->hide();
    ui->progressBar->hide();
    ui->progressBar->setValue(0);
    MainWindow::setWindowTitle("");
    //ui->gridTabWidget->TabShape = QTabWidget::Triangular;
}

MainWindow::~MainWindow()
{
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
        if(magic != 0xB00B1E5)
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
        Scandata.empty();
        in >> scanName;
        in >> monoSetting;
        in >> startScan;
        in >> finScan;
        in >> scanSpeed;
        in >> Scandata;
        newScan.scanName = scanName;
        newScan.finPos = finScan;
        newScan.startPos = startScan;
        newScan.scanSpeed = scanSpeed;
        newScan.polSettings.push_back((bool)(monoSetting%2 == 1));
        newScan.polSettings.push_back((bool)(monoSetting%2 == 0 && monoSetting != 4));
        newScan.polSettings.push_back((bool)(monoSetting >= 4));
        //TODO hier!!!Nur was?
        if(Scandata.isEmpty())
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
            QMessageBox::information(this, tr("Info"),QString::number(currentScanNumber) + " " + QString::number(newScanList.Scans.size()));
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
        out << (quint32)0xB00B1E5;
        out << (qint32)123;
        out.setVersion(QDataStream::Qt_4_5);//Hier muss noch Portabilität eingebaut werden, siehe auch http://qt-project.org/doc/qt-4.8/qdatastream.html
        if(!MainWindow::newScanList.Scans.isEmpty())
        {
            out << MainWindow::newScanList.Scans[currentScanNumber].scanName;
            qint32 monoSetting = (int)MainWindow::newScanList.Scans[currentScanNumber-1].polSettings[0] + (int)MainWindow::newScanList.Scans[0].polSettings[1] + (int)MainWindow::newScanList.Scans[0].polSettings[2];
            out << monoSetting;
            out << MainWindow::newScanList.Scans[currentScanNumber].startPos;
            out << MainWindow::newScanList.Scans[currentScanNumber].finPos;
            out << MainWindow::newScanList.Scans[currentScanNumber].scanSpeed;
        }
        out << MainWindow::newScanList.Scans[currentScanNumber].values.Data;
    }
}

void MainWindow::saveGeneric()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan file (old)(*.txt);;All Files(*)"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
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
    }
}

void MainWindow::saveGenericAllPlots()
{
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
    if(polarizerSettings.size() == 3)
        polarizerSettings[0] = checked;
    else
    {
        QMessageBox::information(this, tr("Exceptional Error"), tr("Exceptional error happened, program is exiting."));
        getch();
        exit(-1);
    };
}

void MainWindow::on_dispYValue_toggled(bool checked)
{
    if(polarizerSettings.size() == 3)
        polarizerSettings[1] = checked;
    else
    {
        QMessageBox::information(this, tr("Exceptional Error"), tr("Exceptional error happened, program is exiting."));
        getch();
        exit(-1);
    };
}

void MainWindow::on_dispZValue_toggled(bool checked)
{
    if(polarizerSettings.size() == 3)
        polarizerSettings[2] = checked;
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
    MainWindow::changeState(ScanState);
    //Nothing to do here
    MainWindow::changeState(EditState);
    //Analyze(MainWindow::newScanList);
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
}
