#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMap>
#include <QWidget>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_grid.h>
#include <qwt/qwt_picker.h>
#include <qwt/qwt_plot_picker.h>
#include <qwt/qwt_picker_machine.h>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QJsonObject>
#include <QJsonValue>

#include "../remoteController/tx_thread.h"
#include "add_functions.h"
#include "scanlist.h"
#include "spectrometer.h"
#include "txcontroller.h"

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
    void calibrate(void);
    void oncurrentCount(int counts);

    void closeProgressBar(void);

    void addNewValue(qreal wNumber, qreal counts);
    void scanIsInterrupted(void);
    //Scanning slot
    void CurrentScanStatus(qreal status);
    void incomingData(QPair<int, int> data);
    void scanIsFinished(void);
    //Movement Slots
    void PositionChanged(void);
    void StepperMoving(void);
    //Mouse slots
    void mousePoint(const QPointF &point);
    //TX slots
    void connectStatus(bool status);
    //Analyst slots
    void calibrateScan(ScanData &newScan);
    void sortPoints(void);
    QPair<QPair<int, int>, QPair<int, int> > getNearestPoints(int xVal);
    int calculateValue(QPair<int, int> targetPoint, QPair<int, int> firstPoint, QPair<int, int> secondPoint);
    int calculateInvValue(QPair<int, int> targetPoint, QPair<int, int> firstPoint, QPair<int, int> secondPoint);
signals:
    //Polarizer signals
    void xPolarizerMoved(Polarizer, bool);
    void yPolarizerMoved(Polarizer, bool);
    void zPolarizerMoved(Polarizer, bool);
    //Stepper signals
    void MoveStepUp(int, int);
    void MoveStepDown(int, int);
    void MoveToTarget(int, int);
    //DPC signals
    void stopCounting(void);
    //Controller signals
    void stopControlling(void);
    //Scanner signals
    void stopScan(void);
    void startScan(void);
    void killScanner(void);
    void initScanner(int, int, int, int, bool);
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

    void on_gridTabWidget_currentChanged(int index);

    void on_newScan_clicked(void);

    void on_stopScan_clicked(void);

    void on_saveSettingsButton_clicked();

    void on_loadSettingsButton_clicked();

    void on_centerMono_clicked(void);

    void on_connect_clicked();

    void on_CalibButton_clicked();

    void on_CalibFinished_clicked();

    void on_CalibConfirm_clicked();

    void on_AddMovementLog_clicked();

    void on_AddMovementCommentLog_clicked();

private:


    QMutex mutex/*, cmutex*/;
    QWaitCondition EngineMoving/*, CountCond*/;


    QwtPlotPicker* plotPicker;
    QwtPickerMachine* pickerMachine;

    enum State {ScanState, EditState, MoveState, CalibState};
    State currentState;
    void replot();
    void createActions();
    void createMenus();
    void changeState(State newState);
    void clear_window(void);
    QVector<QPair<int, int> > CorrectionValues;

    Ui::MainWindow *ui;

    //Movement Logging
    bool movementLogging = false;
    QString MovementLogFile;
    QFile *LogFile = NULL;
    QTextStream *LogStream = NULL;
    void logThis(QVariant data);

    QMap<double, double> Scandata;
    QVector<bool> polarizerSettings;
    ScanList newScanList;
    struct Scan tmpScan;
    int currentScanNumber;
    Spectrometer_Control *newSpectrometer;
    bool calibrated;

    //TX
    QString ipAddr;
    quint32 port;

    //QWT tools
    QPen pen;
    QwtPlotCurve Curve;
    QwtPlotGrid Grid;
    //Menu actions
    QMenu *fileMenu;
    QAction *openAct;
    QAction *openGenericAct;
    QAction *saveAct;
    QAction *saveGenericAct;
    QAction *saveGenericAll;
    QAction *calibrateAct;

    //DPC *newDPC;
    //Spec_Control *newSpecControl;
    QThread *SCThread;
    //scanner *newScanner;
};

#endif // MAINWINDOW_H
