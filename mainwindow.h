#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include "Globale.h"

class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_xPol_clicked(bool checked);

    void on_yPol_clicked(bool checked);

    void on_zPol_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    QMap<double, double> Scandata;
    QVector<bool> polarizerSettings;
};

#endif // MAINWINDOW_H
