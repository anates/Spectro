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

    MainWindow::Curve.setTitle("Raman spectra");
    MainWindow::Curve.setRenderHint(QwtPlotItem::RenderAntialiased, true);

    MainWindow::pen.setStyle(Qt::SolidLine);
    MainWindow::pen.setWidth(3);
    MainWindow::pen.setBrush(Qt::red);
    MainWindow::pen.setCapStyle(Qt::RoundCap);
    MainWindow::pen.setJoinStyle(Qt::RoundJoin);

    MainWindow::Curve.setPen(MainWindow::pen);

    QVector<double> x, y;
    x = QVector<double>::fromList(Scandata.keys());
    y = QVector<double>::fromList(Scandata.values());

    MainWindow::Curve.setSamples(x, y);
    MainWindow::Curve.attach(ui->qwtPlot);
    ui->qwtPlot->updateAxes();
    ui->qwtPlot->show();
    ui->qwtPlot->replot();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scan file"), "", tr("Scan file (*.sca);;All Files(*)")); //Eventuell auf mehrere Files erweitern, damit man mehrere Scans gleichzeitig laden kann
    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);//Siehe unten wegen Kompatibilität
        Scandata.empty();
        in >> Scandata;

        if(Scandata.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
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
        read_unformatted_file(newScan.values, fileName);
        //newScan.polSettings = polarizerSettings;//Muss manuell eingegeben werden!

        if(newScan.values.Data.isEmpty())
        {
            QMessageBox::information(this, tr("No scan data in file"),tr("The file you are attempting to open contains no scan data"));//Eventuell Scan eigenen Header verpassen
        }
        else
        {
            QMessageBox::information(0, "Information", "Finished loading, all data imported, no data checked!");
            vectorToMap(newScan.values.Data, MainWindow::Scandata);
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
        out.setVersion(QDataStream::Qt_4_5);//Hier muss noch Portabilität eingebaut werden, siehe auch http://qt-project.org/doc/qt-4.8/qdatastream.html
        out << Scandata;
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
        write_unformatted_file(MainWindow::Scandata, fileName);
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

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(openGenericAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveGenericAct);
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
