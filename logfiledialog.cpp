#include "logfiledialog.h"
#include "ui_logfiledialog.h"

LogFileDialog::LogFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogFileDialog)
{
    ui->setupUi(this);
    this->localLog.clear();
}

LogFileDialog::~LogFileDialog()
{
    delete ui;
}

void LogFileDialog::on_LogConfirm_clicked()
{
    if(ui->LogName->text().isEmpty() || ui->LogPower->text().isEmpty() || ui->LogSens->text().isEmpty() || ui->LogSlit1->text().isEmpty())
    {
        QMessageBox::information(this, tr("Error"), QString("A value is missing, please try again!"));
        return;
    }
    this->localLog.laserIntensity = ui->LogPower->text().toDouble();
    this->localLog.name = ui->LogName->text();
    this->localLog.sensitivity = ui->LogSens->text().toDouble();
    this->localLog.logfileSet = true;
    QVector<double> slits;
    slits.push_back(ui->LogSlit1->text().toDouble());
    slits.push_back(ui->LogSlit2->text().isEmpty()?ui->LogSlit1->text().toDouble():ui->LogSlit2->text().toDouble());
    slits.push_back(ui->LogSlit3->text().isEmpty()?(ui->LogSlit2->text().isEmpty()?ui->LogSlit1->text().toDouble():ui->LogSlit2->text().toDouble()):ui->LogSlit3->text().toDouble());
    slits.push_back(ui->LogSlit4->text().isEmpty()?(ui->LogSlit1->text().toDouble()):ui->LogSlit4->text().toDouble());
    this->localLog.slits = slits;
    this->done(1);
}



void LogFileDialog::on_LogCancel_clicked()
{
    this->localLog.clear();
    this->done(0);
}

LogFile LogFileDialog::getLog()
{
    return this->localLog;
}


