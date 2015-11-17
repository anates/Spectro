#ifndef LOGFILEDIALOG_H
#define LOGFILEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "logfile.h"

namespace Ui {
class LogFileDialog;
}

class LogFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogFileDialog(QWidget *parent = 0);
    ~LogFileDialog();

    LogFile getLog(void);

private slots:
    void on_LogConfirm_clicked();

    void on_LogCancel_clicked();

private:
    Ui::LogFileDialog *ui;
    LogFile localLog;
};

#endif // LOGFILEDIALOG_H
