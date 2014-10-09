#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include "Globale.h"
//#include "add_functions.h"
//#include "Globale.h"

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
    void on_loadGenericButton_clicked();

    void open();

    void openGeneric();

    void save();

    void saveGeneric();

    void saveGenericAllPlots();

    void on_dispXValue_toggled(bool checked);

    void on_dispYValue_toggled(bool checked);

    void on_dispZValue_toggled(bool checked);

    void on_gridTabWidget_currentChanged(int index);

    void on_scanButton_clicked();

    void on_LastScan_clicked();

    void on_NextScan_clicked();

private:

    enum State {ScanState, EditState, MoveState};
    void replot();
    void createActions();
    void createMenus();
    void changeState(State newState);


    Ui::MainWindow *ui;

    QMap<qreal, qreal> Scandata;
    QVector<bool> polarizerSettings;
    ScanList newScanList;
    struct Scan currentScan;
    int currentScanNumber;

    QPen pen;
    QwtPlotCurve Curve;
    QwtPlotGrid Grid;

    QMenu *fileMenu;
    QAction *openAct;
    QAction *openGenericAct;
    QAction *saveAct;
    QAction *saveGenericAct;
    QAction *saveGenericAll;


};

#endif // MAINWINDOW_H
