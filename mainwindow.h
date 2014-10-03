#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>

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

private:
    Ui::MainWindow *ui;

    QMap<double, double> Scandata;
};

#endif // MAINWINDOW_H
