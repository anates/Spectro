#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::polarizerSettings.resize(3);
    ui->loadButton->setToolTip(tr("Load scan from a file"));
    ui->saveButton->setToolTip(tr("Save contacts to a file"));
    ui->scanButton->setToolTip("Start scan");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
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

void MainWindow::on_saveButton_clicked()
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

void MainWindow::on_xPol_clicked(bool checked)
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

void MainWindow::on_yPol_clicked(bool checked)
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

void MainWindow::on_zPol_clicked(bool checked)
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

void MainWindow::on_loadGenericButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scan file"), "", tr("All Files(*)")); //Eventuell auf mehrere Files erweitern, damit man mehrere Scans gleichzeitig laden kann
    if(fileName.isEmpty())
        return;
    else
    {
        read_unformatted_file(Scandata, fileName);

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

void MainWindow::replot()
{
    MainWindow::Grid.attach(ui->qwtPlot);

    MainWindow::Curve.setTitle("Raman spectra");
    MainWindow::Curve.setRenderHint(QwtPlotItem::RenderAntialiased, true);

    MainWindow::pen.setStyle(Qt::SolidLine);
    MainWindow::pen.setWidth(3);
    MainWindow::pen.setBrush(Qt::black);
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
    QMessageBox::information(this, tr("Info"),QString::number(x[x.size()-1]));
}

void MainWindow::on_saveGenericData_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save scan"), "", tr("Scan file (old)(*.txt);;All Files(*)"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
        write_unformatted_file(MainWindow::Scandata, fileName);
}
