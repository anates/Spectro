#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <QThread>
#include "Globale.h"
//#include "Maaling.h"
//#include "add_functions.h"

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
    
public slots:
    void oncurrentCount(int counts);
    void CurrentScanStatus(qreal status);
    void closeProgressBar(void);
    void scanIsFinished(void);
    void addNewValue(qreal wNumber, qreal counts);

signals:
    //Polarizer signals
    void xPolarizerMoved(Polarizer, bool);
    void yPolarizerMoved(Polarizer, bool);
    void zPolarizerMoved(Polarizer, bool);
    //Stepper signals
    void MoveStepUp(qreal, qreal, bool);
    void MoveStepDown(qreal, qreal, bool);

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

    void on_scanButton_clicked();

    void on_LastScan_clicked();

    void on_NextScan_clicked();

    void on_selectScanBox_currentIndexChanged(int index);

    void on_saveScan_clicked();

    void reload_data();

    void on_stepBackMono_clicked();

    void on_stepForwardMono_clicked();

    void on_mvButton_2_clicked();

    void on_logButton_clicked();

    void createLogData();

    void loadConfig();

    void writeConfig();

//    void on_activateCounter_clicked();

    void on_execButton_2_clicked();

private:

    enum State {ScanState, EditState, MoveState};
    void replot();
    void createActions();
    void createMenus();
    void changeState(State newState);
    //void contextMenuEvent(QContextMenuEvent *event);

    //void customContextMenuRequested(const QPoint &pos);


    Ui::MainWindow *ui;

    QMap<qreal, qreal> Scandata;
    QVector<bool> polarizerSettings;
    ScanList newScanList;
    struct Scan tmpScan;
    int currentScanNumber;
    struct Spectrometer *newSpectrometer;

    QPen pen;
    QwtPlotCurve Curve;
    QwtPlotGrid Grid;

    QMenu *fileMenu;
    QAction *openAct;
    QAction *openGenericAct;
    QAction *saveAct;
    QAction *saveGenericAct;
    QAction *saveGenericAll;

    DPC *newDPC;
    Spec_Control *newSpecControl;
    QThread *SCThread;
    scanner *newScanner;
};

#endif // MAINWINDOW_H
