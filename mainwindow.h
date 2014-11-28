#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMap>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <QThread>
#include <QJsonObject>
#include <QJsonValue>
#include "Globale.h"
#include "../remoteController/tx_thread.h"
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
    void calibrate(void);
    void oncurrentCount(int counts);
    void CurrentScanStatus(qreal status);
    void closeProgressBar(void);
    void scanIsFinished(void);
    void addNewValue(qreal wNumber, qreal counts);
    void scanIsInterrupted(void);
    //TX Slots
    //MainTX slots
    void wrongDeviceMain(void);
    void gotNewDataMain(QVariant data);
    void MainKilled(void);
    void NoServer(void);
    //PCTX slots
    void wrongDevicePC(void);
    void gotNewDataPC(QVariant data);
    void PCkilled(void);
    //FLTX slots
    void wrongDeviceFL(void);
    void gotNewFileFL(QVariant data);
    void FLkilled(void);
    //PolTX slots
    void wrongDevicePol(void);
    void gotNewConnectionPol(QVariant address);
    void Polkilled(void);
    //STPTX slots
    void wrongDeviceSTP(void);
    void gotNewConnectionSTP(QVariant address);
    void STPkilled(void);

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
    //MainTX signals
    void killMain(void);
    void connectMain(QString, quint32);
    //FLTX signals
    void killFL(void);
    void connectFL(QString, quint32);
    //PCTX signals
    void killPC(void);
    void connectPC(QString, quint32);
    //PolTX signals
    void killPol(void);
    void sendDataPoll(QVariant);
    //STPTX signals
    void killSTP(void);
    void sendDataSTP(QVariant);

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

private:

    enum State {ScanState, EditState, MoveState, CalibState};
    void replot();
    void createActions();
    void createMenus();
    void changeState(State newState);
    void clear_window(void);
    //void contextMenuEvent(QContextMenuEvent *event);

    //void customContextMenuRequested(const QPoint &pos);


    Ui::MainWindow *ui;

    QMap<double, double> Scandata;
    QVector<bool> polarizerSettings;
    ScanList newScanList;
    struct Scan tmpScan;
    int currentScanNumber;
    Spectrometer *newSpectrometer;

    //TX
    QString ipAddr;
    quint32 port;
    TX_thread *Main_TX;//Client
    Server *PolTX;//Server
    TX_thread *PCTX;//Client
    Server *STPTX;//Server
    TX_thread *FLTX; //Client

    bool MainTXRun, PolTXRun, PCTXRun, STPTXRun, FLRun;
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

    DPC *newDPC;
    Spec_Control *newSpecControl;
    QThread *SCThread;
    scanner *newScanner;
};

#endif // MAINWINDOW_H
