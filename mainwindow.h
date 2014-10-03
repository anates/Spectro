#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include "Globale.h"
#include "add_functions.h"

class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
class QAction;
class QActionGroup;
class QMenu;

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

    void on_loadGenericButton_clicked();

    void on_saveGenericData_clicked();

    void open();

    void openGeneric();

    void save();

    void saveGeneric();


private:

    void replot();
    void createActions();
    void createMenus();



    Ui::MainWindow *ui;

    QMap<double, double> Scandata;
    QVector<bool> polarizerSettings;
    QPen pen;
    QwtPlotCurve Curve;
    QwtPlotGrid Grid;

    QMenu *fileMenu;
    QAction *openAct;
    QAction *openGenericAct;
    QAction *saveAct;
    QAction *saveGenericAct;
};

#endif // MAINWINDOW_H
