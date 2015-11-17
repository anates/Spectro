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
#include <QtSerialPort/QSerialPortInfo>

#include "../remoteController/tx_thread.h"
#include "qsshsocket.h"
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
    void oncurrentCount(double counts);
    void onCurrentAquisition(double counts);
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
    void newStepperStatus(int status);
    //Mouse slots
    void mousePoint(const QPointF &point);
    //TX slots
    void connectStatus(bool status);
    //Analyst slots
    void calibrateScan(ScanData &newScan);
    void sortPoints(void);
    QPair<QPair<int, int>, QPair<int, int> > getNearestPoints(int xVal);
    int calculateValue(std::tuple<int, int, int> targetTuple, QPair<int, int> firstPoint, QPair<int, int> secondPoint);
    int calculateInvValue(QPair<int, int> targetPoint, QPair<int, int> firstPoint, QPair<int, int> secondPoint);

    void serialConnectionUsed(bool status);
    void set_1(bool status);
    void set_2(bool status);
    void set_3(bool status);
    void set_4(bool status);
    void set_5(bool status);
    void set_6(bool status);
    void set_7(bool status);
    void set_8(bool status);

    void continue_this_scan(double counts);

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
    //Internal
    void continue_scan(double counts);
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

    void stepperStopped();

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

    void on_manual_StartMeasurement_clicked();

    void on_manual_confirmValue_clicked();

    void on_manual_centralWL_textEdited(const QString &arg1);

    void on_manual_StartWL_textEdited(const QString &arg1);

    void on_manual_StopWL_textEdited(const QString &arg1);

    void on_manual_CentralWN_textEdited(const QString &arg1);

    void on_manual_StartWN_textEdited(const QString &arg1);

    void on_manual_StopWN_textEdited(const QString &arg1);

    //void on_manual_currWaveNum_textEdited(const QString &arg1);

    void on_manual_currWaveNum_textChanged(const QString &arg1);

    void on_manual_CentralWN_textChanged(const QString &arg1);

    void on_connect_serial_clicked();

    void on_serial_transmitt_clicked();

    void on_lockin_1up_stateChanged(int arg1);

    void on_lockin_2up_stateChanged(int arg1);

    void on_lockin_3up_stateChanged(int arg1);

    void on_lockin_4up_stateChanged(int arg1);

    void on_lockin_5up_stateChanged(int arg1);

    void on_lockin_6up_stateChanged(int arg1);

    void on_lockin_7up_stateChanged(int arg1);

    void on_lockin_8up_stateChanged(int arg1);

    void on_lockin_1down_stateChanged(int arg1);

    void on_lockin_2down_stateChanged(int arg1);

    void on_lockin_3down_stateChanged(int arg1);

    void on_lockin_4down_stateChanged(int arg1);

    void on_lockin_5down_stateChanged(int arg1);

    void on_lockin_6down_stateChanged(int arg1);

    void on_lockin_7down_stateChanged(int arg1);

    void on_lockin_8down_stateChanged(int arg1);

    void on_lockin_baud_combo_currentIndexChanged(const QString &arg1);

    void on_lockin_stop_combo_currentIndexChanged(const QString &arg1);

    void on_lockin_Parity_currentIndexChanged(const QString &arg1);

    void on_lockin_EchoMode_currentIndexChanged(const QString &arg1);

    void on_UpdateCurrentPosition_clicked();

    void on_manual_CancelScan_clicked();

    void on_change_Xvals_currentIndexChanged(const QString &arg1);

    void on_lockin_SetTime_clicked();


    void on_setTimeConstant_currentIndexChanged(const QString &arg1);

    void on_lockin_getTime_clicked();

    void on_setInterpolationMethod_currentIndexChanged(const QString &arg1);

    void on_setInterpolationVariables_currentIndexChanged(const QString &arg1);

private:


    QMutex mutex/*, cmutex*/;
    QWaitCondition EngineMoving/*, CountCond*/;

    bool xVals;

    QwtPlotPicker* plotPicker;
    QwtPickerMachine* pickerMachine;

    //SSH connection
    qsshsocket *SshSocket;
    //End SSH connection
    //Serial connection
    int BaudRate;
    int numStopBits;
    int parity;
    bool useParity;

    QString portName;
    QString request;
//    int numStopBits;
//    bool useParity;
//    bool parity;
    int waitTimeout;
//    int baudrate;
    QSerialPort *serial;
    //End serial connection

    enum State {ScanState, EditState, MoveState, CalibState};
    State currentState;
    void replot();
    void replot_interpolation();
    void createActions();
    void createLogFile();
    void startManualMeasurement();
    void createMenus();
    void changeState(State newState);
    void clear_window(void);
    QVector<QPair<int, int> > CorrectionValues;

    Ui::MainWindow *ui;

    //Movement Logging
    bool movementLogging = false;
    QString MovementLogFile;
    int currentPosition_local;
    QFile *LogFile = NULL;
    QTextStream *LogStream = NULL;
    void logThis(QVariant data);
    bool manualScan;

    QMap<double, double> Scandata;
    QMap<double, double> InterpolatedData;
    QVector<bool> polarizerSettings;
    ScanList newScanList;
    struct Scan tmpScan;
    int currentScanNumber;
    Spectrometer_Control *newSpectrometer;
    bool calibrated;
    bool logFinished;
    //Manual movement
    bool placed_correctly;
    int current_step;
    //TX
    QString ipAddr;
    quint32 port;

    //QWT tools
    QPen pen, pen_orig, pen_interp;
    QwtPlotCurve Curve, Curve_orig, Curve_interp;
    QwtPlotGrid Grid, Grid_orig, Grid_interp;
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
