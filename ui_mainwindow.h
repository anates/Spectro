/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwt/qwt_plot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTabWidget *gridTabWidget;
    QWidget *plotTab;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QwtPlot *qwtPlot;
    QFormLayout *formLayout_2;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *photoCounter;
    QPushButton *activateCounter;
    QFrame *line;
    QLabel *NameLabel;
    QLineEdit *scanName;
    QLabel *StartLabel;
    QLineEdit *setStartPosition;
    QLabel *TargetLabel;
    QLineEdit *setTargetPosition;
    QLabel *AccurLabel;
    QLineEdit *setScanSpeed;
    QLabel *PolarizerLabel;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *dispXValue;
    QCheckBox *dispYValue;
    QCheckBox *dispZValue;
    QPushButton *newScan;
    QPushButton *scanButton;
    QPushButton *stopScan;
    QPushButton *saveSettingsButton;
    QPushButton *loadSettingsButton;
    QPushButton *loadGenericButton;
    QPushButton *saveScan;
    QLabel *ChooseScanLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *LastScan;
    QPushButton *NextScan;
    QPushButton *CalibButton;
    QPushButton *CalibFinished;
    QLabel *CalibLabel;
    QGridLayout *CalibLayout;
    QLineEdit *CalibDataMes1;
    QLineEdit *CalibDataMes2;
    QLabel *CalibLabel1;
    QLineEdit *CalibDataRe2;
    QLabel *CalibReVal;
    QLabel *CalibMesVal;
    QLineEdit *CalibDataRe1;
    QLabel *CalibLabel2;
    QPushButton *AddCalibration;
    QPushButton *CalibConfirm;
    QLabel *selectScanLabel;
    QComboBox *selectScanBox;
    QLabel *mouseLabel;
    QGridLayout *MouseLayout;
    QLabel *xPosLabel;
    QLineEdit *xPos;
    QLineEdit *yPos;
    QLabel *yPosLabel;
    QCheckBox *CalibratedBox;
    QCheckBox *movingBox;
    QWidget *manualScan;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *manual_currWaveNum;
    QLabel *label_18;
    QLineEdit *manual_currWaveLength;
    QLabel *label_43;
    QCheckBox *manual_automat;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_24;
    QLineEdit *manual_centralWL;
    QLabel *label_20;
    QLineEdit *manual_StartWL;
    QLabel *label_21;
    QLineEdit *manual_StopWL;
    QLabel *label_19;
    QLineEdit *manual_Steps;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_26;
    QLineEdit *manual_CentralWN;
    QLabel *label_27;
    QLineEdit *manual_StartWN;
    QLabel *label_25;
    QLineEdit *manual_StopWN;
    QLabel *label_28;
    QLineEdit *manual_DeltaWN;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_23;
    QLineEdit *manualScanName;
    QLabel *label_44;
    QLineEdit *manual_numAqu;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *manual_StartMeasurement;
    QProgressBar *manual_ProgressBar;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_22;
    QLineEdit *manual_currentValue;
    QPushButton *manual_confirmValue;
    QPushButton *manual_CancelScan;
    QWidget *scanTab;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_7;
    QLineEdit *newWavelength;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *moveData;
    QPushButton *mvButton_2;
    QGridLayout *gridLayout_2;
    QPushButton *centerMono;
    QPushButton *stepBackMono;
    QPushButton *stepForwardMono;
    QLabel *label;
    QCheckBox *movingBox2;
    QLineEdit *currentWavelength;
    QLineEdit *newWaveNumber;
    QLabel *label_13;
    QLabel *label_9;
    QLineEdit *currentWaveNumber;
    QPushButton *execButton_2;
    QLineEdit *newPosition;
    QLineEdit *currentPosition;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QLineEdit *updateCurrentPositionLine;
    QLabel *label_47;
    QPushButton *UpdateCurrentPosition;
    QPushButton *AddMovementLog;
    QGridLayout *MovementLogLayout;
    QLabel *label_2;
    QLineEdit *MovementLogFileName;
    QLabel *label_3;
    QLineEdit *MovementLogFileComment;
    QPushButton *AddMovementCommentLog;
    QCheckBox *LoggingBox;
    QProgressBar *MovingProgressBar;
    QWidget *logTab;
    QFormLayout *formLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_14;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLineEdit *laserPower;
    QLabel *label_6;
    QLineEdit *slitWidth;
    QLabel *label_7;
    QLineEdit *sensitivity;
    QLabel *label_8;
    QLineEdit *countNumber;
    QLabel *label_15;
    QLineEdit *logfileName;
    QPushButton *logButton;
    QWidget *RemoteTab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *connect;
    QCheckBox *MainTXcon;
    QLineEdit *port;
    QLabel *ipLabel;
    QLineEdit *ipAddress;
    QLabel *portLabel;
    QLabel *label_17;
    QWidget *Lockintab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QComboBox *serial_ComboBox;
    QPushButton *connect_serial;
    QLabel *label_30;
    QLineEdit *lockin_CommandReturn_Value;
    QPushButton *serial_transmitt;
    QCheckBox *serialCheckbox;
    QLineEdit *lockin_commandValue;
    QLineEdit *lockin_CommandReturn;
    QComboBox *lockin_command;
    QLabel *label_29;
    QGridLayout *gridLayout_6;
    QLabel *label_31;
    QLabel *label_32;
    QCheckBox *lockin_2down;
    QLabel *label_35;
    QLabel *label_33;
    QCheckBox *lockin_4down;
    QLabel *label_37;
    QLabel *label_34;
    QCheckBox *lockin_7up;
    QLabel *label_38;
    QCheckBox *lockin_1down;
    QCheckBox *lockin_5up;
    QCheckBox *lockin_8up;
    QCheckBox *lockin_6down;
    QCheckBox *lockin_5down;
    QLabel *label_36;
    QCheckBox *lockin_1up;
    QCheckBox *lockin_3up;
    QCheckBox *lockin_2up;
    QCheckBox *lockin_4up;
    QCheckBox *lockin_6up;
    QCheckBox *lockin_8down;
    QCheckBox *lockin_7down;
    QLabel *label_39;
    QLabel *label_40;
    QCheckBox *lockin_3down;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_41;
    QComboBox *lockin_baud_combo;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_42;
    QComboBox *lockin_stop_combo;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_45;
    QComboBox *lockin_Parity;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_46;
    QComboBox *lockin_EchoMode;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1013, 902);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridTabWidget = new QTabWidget(centralWidget);
        gridTabWidget->setObjectName(QStringLiteral("gridTabWidget"));
        plotTab = new QWidget();
        plotTab->setObjectName(QStringLiteral("plotTab"));
        gridLayout = new QGridLayout(plotTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(plotTab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qwtPlot = new QwtPlot(plotTab);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));

        horizontalLayout_2->addWidget(qwtPlot);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_16 = new QLabel(plotTab);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_16);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        photoCounter = new QLineEdit(plotTab);
        photoCounter->setObjectName(QStringLiteral("photoCounter"));

        horizontalLayout_5->addWidget(photoCounter);

        activateCounter = new QPushButton(plotTab);
        activateCounter->setObjectName(QStringLiteral("activateCounter"));

        horizontalLayout_5->addWidget(activateCounter);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        line = new QFrame(plotTab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, line);

        NameLabel = new QLabel(plotTab);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, NameLabel);

        scanName = new QLineEdit(plotTab);
        scanName->setObjectName(QStringLiteral("scanName"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, scanName);

        StartLabel = new QLabel(plotTab);
        StartLabel->setObjectName(QStringLiteral("StartLabel"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, StartLabel);

        setStartPosition = new QLineEdit(plotTab);
        setStartPosition->setObjectName(QStringLiteral("setStartPosition"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, setStartPosition);

        TargetLabel = new QLabel(plotTab);
        TargetLabel->setObjectName(QStringLiteral("TargetLabel"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, TargetLabel);

        setTargetPosition = new QLineEdit(plotTab);
        setTargetPosition->setObjectName(QStringLiteral("setTargetPosition"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, setTargetPosition);

        AccurLabel = new QLabel(plotTab);
        AccurLabel->setObjectName(QStringLiteral("AccurLabel"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, AccurLabel);

        setScanSpeed = new QLineEdit(plotTab);
        setScanSpeed->setObjectName(QStringLiteral("setScanSpeed"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, setScanSpeed);

        PolarizerLabel = new QLabel(plotTab);
        PolarizerLabel->setObjectName(QStringLiteral("PolarizerLabel"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, PolarizerLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dispXValue = new QCheckBox(plotTab);
        dispXValue->setObjectName(QStringLiteral("dispXValue"));

        horizontalLayout_3->addWidget(dispXValue);

        dispYValue = new QCheckBox(plotTab);
        dispYValue->setObjectName(QStringLiteral("dispYValue"));

        horizontalLayout_3->addWidget(dispYValue);

        dispZValue = new QCheckBox(plotTab);
        dispZValue->setObjectName(QStringLiteral("dispZValue"));

        horizontalLayout_3->addWidget(dispZValue);


        formLayout_2->setLayout(9, QFormLayout::FieldRole, horizontalLayout_3);

        newScan = new QPushButton(plotTab);
        newScan->setObjectName(QStringLiteral("newScan"));

        formLayout_2->setWidget(11, QFormLayout::FieldRole, newScan);

        scanButton = new QPushButton(plotTab);
        scanButton->setObjectName(QStringLiteral("scanButton"));

        formLayout_2->setWidget(12, QFormLayout::FieldRole, scanButton);

        stopScan = new QPushButton(plotTab);
        stopScan->setObjectName(QStringLiteral("stopScan"));

        formLayout_2->setWidget(13, QFormLayout::FieldRole, stopScan);

        saveSettingsButton = new QPushButton(plotTab);
        saveSettingsButton->setObjectName(QStringLiteral("saveSettingsButton"));

        formLayout_2->setWidget(14, QFormLayout::FieldRole, saveSettingsButton);

        loadSettingsButton = new QPushButton(plotTab);
        loadSettingsButton->setObjectName(QStringLiteral("loadSettingsButton"));

        formLayout_2->setWidget(15, QFormLayout::FieldRole, loadSettingsButton);

        loadGenericButton = new QPushButton(plotTab);
        loadGenericButton->setObjectName(QStringLiteral("loadGenericButton"));

        formLayout_2->setWidget(16, QFormLayout::FieldRole, loadGenericButton);

        saveScan = new QPushButton(plotTab);
        saveScan->setObjectName(QStringLiteral("saveScan"));

        formLayout_2->setWidget(17, QFormLayout::FieldRole, saveScan);

        ChooseScanLabel = new QLabel(plotTab);
        ChooseScanLabel->setObjectName(QStringLiteral("ChooseScanLabel"));

        formLayout_2->setWidget(18, QFormLayout::LabelRole, ChooseScanLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LastScan = new QPushButton(plotTab);
        LastScan->setObjectName(QStringLiteral("LastScan"));

        horizontalLayout->addWidget(LastScan);

        NextScan = new QPushButton(plotTab);
        NextScan->setObjectName(QStringLiteral("NextScan"));

        horizontalLayout->addWidget(NextScan);


        formLayout_2->setLayout(18, QFormLayout::FieldRole, horizontalLayout);

        CalibButton = new QPushButton(plotTab);
        CalibButton->setObjectName(QStringLiteral("CalibButton"));

        formLayout_2->setWidget(19, QFormLayout::FieldRole, CalibButton);

        CalibFinished = new QPushButton(plotTab);
        CalibFinished->setObjectName(QStringLiteral("CalibFinished"));

        formLayout_2->setWidget(20, QFormLayout::FieldRole, CalibFinished);

        CalibLabel = new QLabel(plotTab);
        CalibLabel->setObjectName(QStringLiteral("CalibLabel"));

        formLayout_2->setWidget(21, QFormLayout::LabelRole, CalibLabel);

        CalibLayout = new QGridLayout();
        CalibLayout->setSpacing(6);
        CalibLayout->setObjectName(QStringLiteral("CalibLayout"));
        CalibDataMes1 = new QLineEdit(plotTab);
        CalibDataMes1->setObjectName(QStringLiteral("CalibDataMes1"));

        CalibLayout->addWidget(CalibDataMes1, 1, 1, 1, 1);

        CalibDataMes2 = new QLineEdit(plotTab);
        CalibDataMes2->setObjectName(QStringLiteral("CalibDataMes2"));

        CalibLayout->addWidget(CalibDataMes2, 2, 1, 1, 1);

        CalibLabel1 = new QLabel(plotTab);
        CalibLabel1->setObjectName(QStringLiteral("CalibLabel1"));

        CalibLayout->addWidget(CalibLabel1, 1, 0, 1, 1);

        CalibDataRe2 = new QLineEdit(plotTab);
        CalibDataRe2->setObjectName(QStringLiteral("CalibDataRe2"));

        CalibLayout->addWidget(CalibDataRe2, 2, 2, 1, 1);

        CalibReVal = new QLabel(plotTab);
        CalibReVal->setObjectName(QStringLiteral("CalibReVal"));

        CalibLayout->addWidget(CalibReVal, 0, 2, 1, 1);

        CalibMesVal = new QLabel(plotTab);
        CalibMesVal->setObjectName(QStringLiteral("CalibMesVal"));

        CalibLayout->addWidget(CalibMesVal, 0, 1, 1, 1);

        CalibDataRe1 = new QLineEdit(plotTab);
        CalibDataRe1->setObjectName(QStringLiteral("CalibDataRe1"));

        CalibLayout->addWidget(CalibDataRe1, 1, 2, 1, 1);

        CalibLabel2 = new QLabel(plotTab);
        CalibLabel2->setObjectName(QStringLiteral("CalibLabel2"));

        CalibLayout->addWidget(CalibLabel2, 2, 0, 1, 1);

        AddCalibration = new QPushButton(plotTab);
        AddCalibration->setObjectName(QStringLiteral("AddCalibration"));

        CalibLayout->addWidget(AddCalibration, 3, 1, 1, 1);

        CalibConfirm = new QPushButton(plotTab);
        CalibConfirm->setObjectName(QStringLiteral("CalibConfirm"));

        CalibLayout->addWidget(CalibConfirm, 3, 2, 1, 1);


        formLayout_2->setLayout(21, QFormLayout::FieldRole, CalibLayout);

        selectScanLabel = new QLabel(plotTab);
        selectScanLabel->setObjectName(QStringLiteral("selectScanLabel"));

        formLayout_2->setWidget(22, QFormLayout::LabelRole, selectScanLabel);

        selectScanBox = new QComboBox(plotTab);
        selectScanBox->setObjectName(QStringLiteral("selectScanBox"));

        formLayout_2->setWidget(22, QFormLayout::FieldRole, selectScanBox);

        mouseLabel = new QLabel(plotTab);
        mouseLabel->setObjectName(QStringLiteral("mouseLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, mouseLabel);

        MouseLayout = new QGridLayout();
        MouseLayout->setSpacing(6);
        MouseLayout->setObjectName(QStringLiteral("MouseLayout"));
        xPosLabel = new QLabel(plotTab);
        xPosLabel->setObjectName(QStringLiteral("xPosLabel"));

        MouseLayout->addWidget(xPosLabel, 0, 0, 1, 1);

        xPos = new QLineEdit(plotTab);
        xPos->setObjectName(QStringLiteral("xPos"));

        MouseLayout->addWidget(xPos, 0, 1, 1, 1);

        yPos = new QLineEdit(plotTab);
        yPos->setObjectName(QStringLiteral("yPos"));

        MouseLayout->addWidget(yPos, 0, 3, 1, 1);

        yPosLabel = new QLabel(plotTab);
        yPosLabel->setObjectName(QStringLiteral("yPosLabel"));

        MouseLayout->addWidget(yPosLabel, 0, 2, 1, 1);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, MouseLayout);

        CalibratedBox = new QCheckBox(plotTab);
        CalibratedBox->setObjectName(QStringLiteral("CalibratedBox"));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, CalibratedBox);

        movingBox = new QCheckBox(plotTab);
        movingBox->setObjectName(QStringLiteral("movingBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, movingBox);


        horizontalLayout_2->addLayout(formLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridTabWidget->addTab(plotTab, QString());
        manualScan = new QWidget();
        manualScan->setObjectName(QStringLiteral("manualScan"));
        verticalLayoutWidget = new QWidget(manualScan);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(2, 9, 981, 781));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        manual_currWaveNum = new QLineEdit(verticalLayoutWidget);
        manual_currWaveNum->setObjectName(QStringLiteral("manual_currWaveNum"));

        horizontalLayout_6->addWidget(manual_currWaveNum);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_6->addWidget(label_18);

        manual_currWaveLength = new QLineEdit(verticalLayoutWidget);
        manual_currWaveLength->setObjectName(QStringLiteral("manual_currWaveLength"));

        horizontalLayout_6->addWidget(manual_currWaveLength);

        label_43 = new QLabel(verticalLayoutWidget);
        label_43->setObjectName(QStringLiteral("label_43"));

        horizontalLayout_6->addWidget(label_43);

        manual_automat = new QCheckBox(verticalLayoutWidget);
        manual_automat->setObjectName(QStringLiteral("manual_automat"));

        horizontalLayout_6->addWidget(manual_automat);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_24 = new QLabel(verticalLayoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_7->addWidget(label_24);

        manual_centralWL = new QLineEdit(verticalLayoutWidget);
        manual_centralWL->setObjectName(QStringLiteral("manual_centralWL"));

        horizontalLayout_7->addWidget(manual_centralWL);

        label_20 = new QLabel(verticalLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_7->addWidget(label_20);

        manual_StartWL = new QLineEdit(verticalLayoutWidget);
        manual_StartWL->setObjectName(QStringLiteral("manual_StartWL"));

        horizontalLayout_7->addWidget(manual_StartWL);

        label_21 = new QLabel(verticalLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_7->addWidget(label_21);

        manual_StopWL = new QLineEdit(verticalLayoutWidget);
        manual_StopWL->setObjectName(QStringLiteral("manual_StopWL"));

        horizontalLayout_7->addWidget(manual_StopWL);

        label_19 = new QLabel(verticalLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_7->addWidget(label_19);

        manual_Steps = new QLineEdit(verticalLayoutWidget);
        manual_Steps->setObjectName(QStringLiteral("manual_Steps"));

        horizontalLayout_7->addWidget(manual_Steps);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_26 = new QLabel(verticalLayoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_11->addWidget(label_26);

        manual_CentralWN = new QLineEdit(verticalLayoutWidget);
        manual_CentralWN->setObjectName(QStringLiteral("manual_CentralWN"));

        horizontalLayout_11->addWidget(manual_CentralWN);

        label_27 = new QLabel(verticalLayoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_11->addWidget(label_27);

        manual_StartWN = new QLineEdit(verticalLayoutWidget);
        manual_StartWN->setObjectName(QStringLiteral("manual_StartWN"));

        horizontalLayout_11->addWidget(manual_StartWN);

        label_25 = new QLabel(verticalLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_11->addWidget(label_25);

        manual_StopWN = new QLineEdit(verticalLayoutWidget);
        manual_StopWN->setObjectName(QStringLiteral("manual_StopWN"));

        horizontalLayout_11->addWidget(manual_StopWN);

        label_28 = new QLabel(verticalLayoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_11->addWidget(label_28);

        manual_DeltaWN = new QLineEdit(verticalLayoutWidget);
        manual_DeltaWN->setObjectName(QStringLiteral("manual_DeltaWN"));

        horizontalLayout_11->addWidget(manual_DeltaWN);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_23 = new QLabel(verticalLayoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_10->addWidget(label_23);

        manualScanName = new QLineEdit(verticalLayoutWidget);
        manualScanName->setObjectName(QStringLiteral("manualScanName"));

        horizontalLayout_10->addWidget(manualScanName);

        label_44 = new QLabel(verticalLayoutWidget);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_10->addWidget(label_44);

        manual_numAqu = new QLineEdit(verticalLayoutWidget);
        manual_numAqu->setObjectName(QStringLiteral("manual_numAqu"));

        horizontalLayout_10->addWidget(manual_numAqu);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        manual_StartMeasurement = new QPushButton(verticalLayoutWidget);
        manual_StartMeasurement->setObjectName(QStringLiteral("manual_StartMeasurement"));

        horizontalLayout_8->addWidget(manual_StartMeasurement);

        manual_ProgressBar = new QProgressBar(verticalLayoutWidget);
        manual_ProgressBar->setObjectName(QStringLiteral("manual_ProgressBar"));
        manual_ProgressBar->setValue(24);

        horizontalLayout_8->addWidget(manual_ProgressBar);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_22 = new QLabel(verticalLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_9->addWidget(label_22);

        manual_currentValue = new QLineEdit(verticalLayoutWidget);
        manual_currentValue->setObjectName(QStringLiteral("manual_currentValue"));

        horizontalLayout_9->addWidget(manual_currentValue);

        manual_confirmValue = new QPushButton(verticalLayoutWidget);
        manual_confirmValue->setObjectName(QStringLiteral("manual_confirmValue"));

        horizontalLayout_9->addWidget(manual_confirmValue);

        manual_CancelScan = new QPushButton(verticalLayoutWidget);
        manual_CancelScan->setObjectName(QStringLiteral("manual_CancelScan"));

        horizontalLayout_9->addWidget(manual_CancelScan);


        verticalLayout_2->addLayout(horizontalLayout_9);

        gridTabWidget->addTab(manualScan, QString());
        scanTab = new QWidget();
        scanTab->setObjectName(QStringLiteral("scanTab"));
        formLayout = new QFormLayout(scanTab);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        newWavelength = new QLineEdit(scanTab);
        newWavelength->setObjectName(QStringLiteral("newWavelength"));

        gridLayout_7->addWidget(newWavelength, 4, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        moveData = new QLineEdit(scanTab);
        moveData->setObjectName(QStringLiteral("moveData"));

        horizontalLayout_4->addWidget(moveData);

        mvButton_2 = new QPushButton(scanTab);
        mvButton_2->setObjectName(QStringLiteral("mvButton_2"));

        horizontalLayout_4->addWidget(mvButton_2);


        gridLayout_7->addLayout(horizontalLayout_4, 7, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        centerMono = new QPushButton(scanTab);
        centerMono->setObjectName(QStringLiteral("centerMono"));

        gridLayout_2->addWidget(centerMono, 0, 1, 1, 1);

        stepBackMono = new QPushButton(scanTab);
        stepBackMono->setObjectName(QStringLiteral("stepBackMono"));

        gridLayout_2->addWidget(stepBackMono, 0, 0, 1, 1);

        stepForwardMono = new QPushButton(scanTab);
        stepForwardMono->setObjectName(QStringLiteral("stepForwardMono"));

        gridLayout_2->addWidget(stepForwardMono, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 8, 2, 1, 1);

        label = new QLabel(scanTab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_7->addWidget(label, 5, 0, 1, 1);

        movingBox2 = new QCheckBox(scanTab);
        movingBox2->setObjectName(QStringLiteral("movingBox2"));

        gridLayout_7->addWidget(movingBox2, 5, 1, 1, 1);

        currentWavelength = new QLineEdit(scanTab);
        currentWavelength->setObjectName(QStringLiteral("currentWavelength"));
        currentWavelength->setReadOnly(true);

        gridLayout_7->addWidget(currentWavelength, 4, 1, 1, 1);

        newWaveNumber = new QLineEdit(scanTab);
        newWaveNumber->setObjectName(QStringLiteral("newWaveNumber"));

        gridLayout_7->addWidget(newWaveNumber, 3, 2, 1, 1);

        label_13 = new QLabel(scanTab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_7->addWidget(label_13, 1, 0, 1, 1);

        label_9 = new QLabel(scanTab);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_7->addWidget(label_9, 4, 0, 1, 1);

        currentWaveNumber = new QLineEdit(scanTab);
        currentWaveNumber->setObjectName(QStringLiteral("currentWaveNumber"));
        currentWaveNumber->setReadOnly(true);

        gridLayout_7->addWidget(currentWaveNumber, 3, 1, 1, 1);

        execButton_2 = new QPushButton(scanTab);
        execButton_2->setObjectName(QStringLiteral("execButton_2"));

        gridLayout_7->addWidget(execButton_2, 6, 2, 1, 1);

        newPosition = new QLineEdit(scanTab);
        newPosition->setObjectName(QStringLiteral("newPosition"));

        gridLayout_7->addWidget(newPosition, 1, 2, 1, 1);

        currentPosition = new QLineEdit(scanTab);
        currentPosition->setObjectName(QStringLiteral("currentPosition"));
        currentPosition->setReadOnly(true);

        gridLayout_7->addWidget(currentPosition, 1, 1, 1, 1);

        label_11 = new QLabel(scanTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_7->addWidget(label_11, 3, 0, 1, 1);

        label_12 = new QLabel(scanTab);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_7->addWidget(label_12, 0, 1, 1, 1);

        label_10 = new QLabel(scanTab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_7->addWidget(label_10, 0, 2, 1, 1);

        updateCurrentPositionLine = new QLineEdit(scanTab);
        updateCurrentPositionLine->setObjectName(QStringLiteral("updateCurrentPositionLine"));

        gridLayout_7->addWidget(updateCurrentPositionLine, 2, 1, 1, 1);

        label_47 = new QLabel(scanTab);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_7->addWidget(label_47, 2, 0, 1, 1);

        UpdateCurrentPosition = new QPushButton(scanTab);
        UpdateCurrentPosition->setObjectName(QStringLiteral("UpdateCurrentPosition"));

        gridLayout_7->addWidget(UpdateCurrentPosition, 2, 2, 1, 1);


        formLayout->setLayout(0, QFormLayout::SpanningRole, gridLayout_7);

        AddMovementLog = new QPushButton(scanTab);
        AddMovementLog->setObjectName(QStringLiteral("AddMovementLog"));

        formLayout->setWidget(1, QFormLayout::FieldRole, AddMovementLog);

        MovementLogLayout = new QGridLayout();
        MovementLogLayout->setSpacing(6);
        MovementLogLayout->setObjectName(QStringLiteral("MovementLogLayout"));
        label_2 = new QLabel(scanTab);
        label_2->setObjectName(QStringLiteral("label_2"));

        MovementLogLayout->addWidget(label_2, 0, 0, 1, 1);

        MovementLogFileName = new QLineEdit(scanTab);
        MovementLogFileName->setObjectName(QStringLiteral("MovementLogFileName"));

        MovementLogLayout->addWidget(MovementLogFileName, 0, 1, 1, 1);

        label_3 = new QLabel(scanTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        MovementLogLayout->addWidget(label_3, 1, 0, 1, 1);

        MovementLogFileComment = new QLineEdit(scanTab);
        MovementLogFileComment->setObjectName(QStringLiteral("MovementLogFileComment"));

        MovementLogLayout->addWidget(MovementLogFileComment, 1, 1, 1, 1);

        AddMovementCommentLog = new QPushButton(scanTab);
        AddMovementCommentLog->setObjectName(QStringLiteral("AddMovementCommentLog"));

        MovementLogLayout->addWidget(AddMovementCommentLog, 2, 1, 1, 1);

        LoggingBox = new QCheckBox(scanTab);
        LoggingBox->setObjectName(QStringLiteral("LoggingBox"));

        MovementLogLayout->addWidget(LoggingBox, 3, 1, 1, 1);

        MovingProgressBar = new QProgressBar(scanTab);
        MovingProgressBar->setObjectName(QStringLiteral("MovingProgressBar"));
        MovingProgressBar->setValue(24);

        MovementLogLayout->addWidget(MovingProgressBar, 4, 1, 1, 1);


        formLayout->setLayout(2, QFormLayout::FieldRole, MovementLogLayout);

        gridTabWidget->addTab(scanTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QStringLiteral("logTab"));
        formLayout_4 = new QFormLayout(logTab);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_14 = new QLabel(logTab);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout->addWidget(label_14);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_5 = new QLabel(logTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_5);

        laserPower = new QLineEdit(logTab);
        laserPower->setObjectName(QStringLiteral("laserPower"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, laserPower);

        label_6 = new QLabel(logTab);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_6);

        slitWidth = new QLineEdit(logTab);
        slitWidth->setObjectName(QStringLiteral("slitWidth"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, slitWidth);

        label_7 = new QLabel(logTab);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        sensitivity = new QLineEdit(logTab);
        sensitivity->setObjectName(QStringLiteral("sensitivity"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, sensitivity);

        label_8 = new QLabel(logTab);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_8);

        countNumber = new QLineEdit(logTab);
        countNumber->setObjectName(QStringLiteral("countNumber"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, countNumber);

        label_15 = new QLabel(logTab);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_15);

        logfileName = new QLineEdit(logTab);
        logfileName->setObjectName(QStringLiteral("logfileName"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, logfileName);


        verticalLayout->addLayout(formLayout_3);

        logButton = new QPushButton(logTab);
        logButton->setObjectName(QStringLiteral("logButton"));

        verticalLayout->addWidget(logButton);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        gridTabWidget->addTab(logTab, QString());
        RemoteTab = new QWidget();
        RemoteTab->setObjectName(QStringLiteral("RemoteTab"));
        gridLayoutWidget = new QWidget(RemoteTab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 581, 551));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        connect = new QPushButton(gridLayoutWidget);
        connect->setObjectName(QStringLiteral("connect"));

        gridLayout_3->addWidget(connect, 2, 1, 1, 1);

        MainTXcon = new QCheckBox(gridLayoutWidget);
        MainTXcon->setObjectName(QStringLiteral("MainTXcon"));

        gridLayout_3->addWidget(MainTXcon, 3, 1, 1, 1);

        port = new QLineEdit(gridLayoutWidget);
        port->setObjectName(QStringLiteral("port"));

        gridLayout_3->addWidget(port, 1, 1, 1, 1);

        ipLabel = new QLabel(gridLayoutWidget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));

        gridLayout_3->addWidget(ipLabel, 0, 0, 1, 1);

        ipAddress = new QLineEdit(gridLayoutWidget);
        ipAddress->setObjectName(QStringLiteral("ipAddress"));

        gridLayout_3->addWidget(ipAddress, 1, 0, 1, 1);

        portLabel = new QLabel(gridLayoutWidget);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        gridLayout_3->addWidget(portLabel, 0, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 3, 0, 1, 1);

        gridTabWidget->addTab(RemoteTab, QString());
        Lockintab = new QWidget();
        Lockintab->setObjectName(QStringLiteral("Lockintab"));
        gridLayoutWidget_2 = new QWidget(Lockintab);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 971, 671));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        serial_ComboBox = new QComboBox(gridLayoutWidget_2);
        serial_ComboBox->setObjectName(QStringLiteral("serial_ComboBox"));

        gridLayout_4->addWidget(serial_ComboBox, 0, 1, 1, 1);

        connect_serial = new QPushButton(gridLayoutWidget_2);
        connect_serial->setObjectName(QStringLiteral("connect_serial"));

        gridLayout_4->addWidget(connect_serial, 6, 1, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_4->addWidget(label_30, 10, 0, 1, 1);

        lockin_CommandReturn_Value = new QLineEdit(gridLayoutWidget_2);
        lockin_CommandReturn_Value->setObjectName(QStringLiteral("lockin_CommandReturn_Value"));

        gridLayout_4->addWidget(lockin_CommandReturn_Value, 9, 1, 1, 1);

        serial_transmitt = new QPushButton(gridLayoutWidget_2);
        serial_transmitt->setObjectName(QStringLiteral("serial_transmitt"));

        gridLayout_4->addWidget(serial_transmitt, 8, 1, 1, 1);

        serialCheckbox = new QCheckBox(gridLayoutWidget_2);
        serialCheckbox->setObjectName(QStringLiteral("serialCheckbox"));

        gridLayout_4->addWidget(serialCheckbox, 10, 1, 1, 1);

        lockin_commandValue = new QLineEdit(gridLayoutWidget_2);
        lockin_commandValue->setObjectName(QStringLiteral("lockin_commandValue"));

        gridLayout_4->addWidget(lockin_commandValue, 7, 1, 1, 1);

        lockin_CommandReturn = new QLineEdit(gridLayoutWidget_2);
        lockin_CommandReturn->setObjectName(QStringLiteral("lockin_CommandReturn"));

        gridLayout_4->addWidget(lockin_CommandReturn, 9, 0, 1, 1);

        lockin_command = new QComboBox(gridLayoutWidget_2);
        lockin_command->setObjectName(QStringLiteral("lockin_command"));

        gridLayout_4->addWidget(lockin_command, 7, 0, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_4->addWidget(label_29, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_31 = new QLabel(gridLayoutWidget_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_6->addWidget(label_31, 0, 8, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_6->addWidget(label_32, 0, 7, 1, 1);

        lockin_2down = new QCheckBox(gridLayoutWidget_2);
        lockin_2down->setObjectName(QStringLiteral("lockin_2down"));

        gridLayout_6->addWidget(lockin_2down, 2, 2, 1, 1);

        label_35 = new QLabel(gridLayoutWidget_2);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_6->addWidget(label_35, 0, 4, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_6->addWidget(label_33, 0, 6, 1, 1);

        lockin_4down = new QCheckBox(gridLayoutWidget_2);
        lockin_4down->setObjectName(QStringLiteral("lockin_4down"));

        gridLayout_6->addWidget(lockin_4down, 2, 4, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_6->addWidget(label_37, 0, 3, 1, 1);

        label_34 = new QLabel(gridLayoutWidget_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_6->addWidget(label_34, 0, 5, 1, 1);

        lockin_7up = new QCheckBox(gridLayoutWidget_2);
        lockin_7up->setObjectName(QStringLiteral("lockin_7up"));

        gridLayout_6->addWidget(lockin_7up, 1, 7, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_6->addWidget(label_38, 0, 1, 1, 1);

        lockin_1down = new QCheckBox(gridLayoutWidget_2);
        lockin_1down->setObjectName(QStringLiteral("lockin_1down"));

        gridLayout_6->addWidget(lockin_1down, 2, 1, 1, 1);

        lockin_5up = new QCheckBox(gridLayoutWidget_2);
        lockin_5up->setObjectName(QStringLiteral("lockin_5up"));

        gridLayout_6->addWidget(lockin_5up, 1, 5, 1, 1);

        lockin_8up = new QCheckBox(gridLayoutWidget_2);
        lockin_8up->setObjectName(QStringLiteral("lockin_8up"));

        gridLayout_6->addWidget(lockin_8up, 1, 8, 1, 1);

        lockin_6down = new QCheckBox(gridLayoutWidget_2);
        lockin_6down->setObjectName(QStringLiteral("lockin_6down"));

        gridLayout_6->addWidget(lockin_6down, 2, 6, 1, 1);

        lockin_5down = new QCheckBox(gridLayoutWidget_2);
        lockin_5down->setObjectName(QStringLiteral("lockin_5down"));

        gridLayout_6->addWidget(lockin_5down, 2, 5, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_2);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_6->addWidget(label_36, 0, 2, 1, 1);

        lockin_1up = new QCheckBox(gridLayoutWidget_2);
        lockin_1up->setObjectName(QStringLiteral("lockin_1up"));

        gridLayout_6->addWidget(lockin_1up, 1, 1, 1, 1);

        lockin_3up = new QCheckBox(gridLayoutWidget_2);
        lockin_3up->setObjectName(QStringLiteral("lockin_3up"));

        gridLayout_6->addWidget(lockin_3up, 1, 3, 1, 1);

        lockin_2up = new QCheckBox(gridLayoutWidget_2);
        lockin_2up->setObjectName(QStringLiteral("lockin_2up"));

        gridLayout_6->addWidget(lockin_2up, 1, 2, 1, 1);

        lockin_4up = new QCheckBox(gridLayoutWidget_2);
        lockin_4up->setObjectName(QStringLiteral("lockin_4up"));

        gridLayout_6->addWidget(lockin_4up, 1, 4, 1, 1);

        lockin_6up = new QCheckBox(gridLayoutWidget_2);
        lockin_6up->setObjectName(QStringLiteral("lockin_6up"));

        gridLayout_6->addWidget(lockin_6up, 1, 6, 1, 1);

        lockin_8down = new QCheckBox(gridLayoutWidget_2);
        lockin_8down->setObjectName(QStringLiteral("lockin_8down"));

        gridLayout_6->addWidget(lockin_8down, 2, 8, 1, 1);

        lockin_7down = new QCheckBox(gridLayoutWidget_2);
        lockin_7down->setObjectName(QStringLiteral("lockin_7down"));

        gridLayout_6->addWidget(lockin_7down, 2, 7, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_6->addWidget(label_39, 1, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_2);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout_6->addWidget(label_40, 2, 0, 1, 1);

        lockin_3down = new QCheckBox(gridLayoutWidget_2);
        lockin_3down->setObjectName(QStringLiteral("lockin_3down"));

        gridLayout_6->addWidget(lockin_3down, 2, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout_6, 1, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_41 = new QLabel(gridLayoutWidget_2);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_12->addWidget(label_41);

        lockin_baud_combo = new QComboBox(gridLayoutWidget_2);
        lockin_baud_combo->setObjectName(QStringLiteral("lockin_baud_combo"));

        horizontalLayout_12->addWidget(lockin_baud_combo);


        gridLayout_4->addLayout(horizontalLayout_12, 2, 1, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_42 = new QLabel(gridLayoutWidget_2);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_14->addWidget(label_42);

        lockin_stop_combo = new QComboBox(gridLayoutWidget_2);
        lockin_stop_combo->setObjectName(QStringLiteral("lockin_stop_combo"));

        horizontalLayout_14->addWidget(lockin_stop_combo);


        gridLayout_4->addLayout(horizontalLayout_14, 3, 1, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_45 = new QLabel(gridLayoutWidget_2);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_15->addWidget(label_45);

        lockin_Parity = new QComboBox(gridLayoutWidget_2);
        lockin_Parity->setObjectName(QStringLiteral("lockin_Parity"));

        horizontalLayout_15->addWidget(lockin_Parity);


        gridLayout_4->addLayout(horizontalLayout_15, 4, 1, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_46 = new QLabel(gridLayoutWidget_2);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_16->addWidget(label_46);

        lockin_EchoMode = new QComboBox(gridLayoutWidget_2);
        lockin_EchoMode->setObjectName(QStringLiteral("lockin_EchoMode"));

        horizontalLayout_16->addWidget(lockin_EchoMode);


        gridLayout_4->addLayout(horizontalLayout_16, 5, 1, 1, 1);

        gridTabWidget->addTab(Lockintab, QString());

        gridLayout_5->addWidget(gridTabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        gridTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_16->setText(QApplication::translate("MainWindow", "Current photo count", 0));
        activateCounter->setText(QApplication::translate("MainWindow", "Activate Counter", 0));
        NameLabel->setText(QApplication::translate("MainWindow", "Scan name", 0));
        StartLabel->setText(QApplication::translate("MainWindow", "Start Position [cm-1]", 0));
        TargetLabel->setText(QApplication::translate("MainWindow", "Target Position [cm-1]", 0));
        AccurLabel->setText(QApplication::translate("MainWindow", "Accuracy", 0));
        PolarizerLabel->setText(QApplication::translate("MainWindow", "Polarizer settings", 0));
        dispXValue->setText(QApplication::translate("MainWindow", "X polarizer set", 0));
        dispYValue->setText(QApplication::translate("MainWindow", "Y polarizer set", 0));
        dispZValue->setText(QApplication::translate("MainWindow", "Z polarizer set", 0));
        newScan->setText(QApplication::translate("MainWindow", "New Scan", 0));
        scanButton->setText(QApplication::translate("MainWindow", "Start scan", 0));
        stopScan->setText(QApplication::translate("MainWindow", "Stop Scan", 0));
        saveSettingsButton->setText(QApplication::translate("MainWindow", "Save scan settings", 0));
        loadSettingsButton->setText(QApplication::translate("MainWindow", "Load scan settings", 0));
        loadGenericButton->setText(QApplication::translate("MainWindow", "Load old scan data", 0));
        saveScan->setText(QApplication::translate("MainWindow", "Save scan data", 0));
        ChooseScanLabel->setText(QApplication::translate("MainWindow", "Switch to next Scan", 0));
        LastScan->setText(QApplication::translate("MainWindow", "Backwards", 0));
        NextScan->setText(QApplication::translate("MainWindow", "Forward", 0));
        CalibButton->setText(QApplication::translate("MainWindow", "Start Calibration", 0));
        CalibFinished->setText(QApplication::translate("MainWindow", "Calibration finished", 0));
        CalibLabel->setText(QApplication::translate("MainWindow", "Calibration Data", 0));
        CalibLabel1->setText(QApplication::translate("MainWindow", "Point 1", 0));
        CalibReVal->setText(QApplication::translate("MainWindow", "Real value", 0));
        CalibMesVal->setText(QApplication::translate("MainWindow", "Measured value", 0));
        CalibLabel2->setText(QApplication::translate("MainWindow", "Point 2", 0));
        AddCalibration->setText(QApplication::translate("MainWindow", "Add new calibration data", 0));
        CalibConfirm->setText(QApplication::translate("MainWindow", "Confirm values", 0));
        selectScanLabel->setText(QApplication::translate("MainWindow", "Select Scan", 0));
        mouseLabel->setText(QApplication::translate("MainWindow", "Mouse position", 0));
        xPosLabel->setText(QApplication::translate("MainWindow", "x position", 0));
        yPosLabel->setText(QApplication::translate("MainWindow", "y position", 0));
        CalibratedBox->setText(QApplication::translate("MainWindow", "Calibrated?", 0));
        movingBox->setText(QApplication::translate("MainWindow", "Moving?", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(plotTab), QApplication::translate("MainWindow", "Plot", 0));
        label_4->setText(QApplication::translate("MainWindow", "Current Wavenumber", 0));
        label_18->setText(QApplication::translate("MainWindow", "Current Wavelength", 0));
        label_43->setText(QApplication::translate("MainWindow", "Enable automatic scan", 0));
        manual_automat->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "Central Wavelength", 0));
        label_20->setText(QApplication::translate("MainWindow", "Startwavelength", 0));
        label_21->setText(QApplication::translate("MainWindow", "Stopwavelength", 0));
        label_19->setText(QApplication::translate("MainWindow", "Number of steps", 0));
        label_26->setText(QApplication::translate("MainWindow", "Central Wavenumber", 0));
        label_27->setText(QApplication::translate("MainWindow", "Startwavenumber", 0));
        label_25->setText(QApplication::translate("MainWindow", "Stopwavenumber", 0));
        label_28->setText(QApplication::translate("MainWindow", "Delta WN", 0));
        label_23->setText(QApplication::translate("MainWindow", "Scan Name (not necessary):", 0));
        label_44->setText(QApplication::translate("MainWindow", "Number of aquisitions", 0));
        manual_StartMeasurement->setText(QApplication::translate("MainWindow", "Start measurement", 0));
        label_22->setText(QApplication::translate("MainWindow", "Current Value in mV", 0));
        manual_confirmValue->setText(QApplication::translate("MainWindow", "Confirm", 0));
        manual_CancelScan->setText(QApplication::translate("MainWindow", "Cancel Scan", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(manualScan), QApplication::translate("MainWindow", "Manual Scan", 0));
        mvButton_2->setText(QApplication::translate("MainWindow", "Move", 0));
        centerMono->setText(QApplication::translate("MainWindow", "Center", 0));
        stepBackMono->setText(QApplication::translate("MainWindow", "Back", 0));
        stepForwardMono->setText(QApplication::translate("MainWindow", "Forward", 0));
        label->setText(QApplication::translate("MainWindow", "Moving?", 0));
        movingBox2->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Position", 0));
        label_9->setText(QApplication::translate("MainWindow", "Wavelength", 0));
        execButton_2->setText(QApplication::translate("MainWindow", "Execute", 0));
        label_11->setText(QApplication::translate("MainWindow", "Wave number [cm-1]", 0));
        label_12->setText(QApplication::translate("MainWindow", "Current settings", 0));
        label_10->setText(QApplication::translate("MainWindow", "New settings", 0));
        label_47->setText(QApplication::translate("MainWindow", "Correct current position [cm-1]", 0));
        UpdateCurrentPosition->setText(QApplication::translate("MainWindow", "Update Position", 0));
        AddMovementLog->setText(QApplication::translate("MainWindow", "Add movement log file", 0));
        label_2->setText(QApplication::translate("MainWindow", "Filename", 0));
        label_3->setText(QApplication::translate("MainWindow", "Comment", 0));
        AddMovementCommentLog->setText(QApplication::translate("MainWindow", "Add Comment", 0));
        LoggingBox->setText(QApplication::translate("MainWindow", "Logging", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(scanTab), QApplication::translate("MainWindow", "Movement settings", 0));
#ifndef QT_NO_ACCESSIBILITY
        logTab->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label_14->setText(QApplication::translate("MainWindow", "Data for logfile", 0));
        label_5->setText(QApplication::translate("MainWindow", "Laser power [mW]", 0));
        label_6->setText(QApplication::translate("MainWindow", "Width of slits [mm]", 0));
        label_7->setText(QApplication::translate("MainWindow", "Sensitivity [counts/sec]", 0));
        label_8->setText(QApplication::translate("MainWindow", "counts", 0));
        label_15->setText(QApplication::translate("MainWindow", "Name for logfile", 0));
        logButton->setText(QApplication::translate("MainWindow", "Add log", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(logTab), QApplication::translate("MainWindow", "Logfile settings", 0));
        connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        MainTXcon->setText(QApplication::translate("MainWindow", "Connected?", 0));
        ipLabel->setText(QApplication::translate("MainWindow", "IP-Address", 0));
        portLabel->setText(QApplication::translate("MainWindow", "Port", 0));
        label_17->setText(QApplication::translate("MainWindow", "Main-TX connected?", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(RemoteTab), QApplication::translate("MainWindow", "Remote settings", 0));
        connect_serial->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_30->setText(QApplication::translate("MainWindow", "Serial port connected?", 0));
        serial_transmitt->setText(QApplication::translate("MainWindow", "Transmit data", 0));
        serialCheckbox->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        label_29->setText(QApplication::translate("MainWindow", "Serial Port", 0));
        label_31->setText(QApplication::translate("MainWindow", "Switch 8", 0));
        label_32->setText(QApplication::translate("MainWindow", "Switch 7", 0));
        lockin_2down->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "Switch 4", 0));
        label_33->setText(QApplication::translate("MainWindow", "Switch 6", 0));
        lockin_4down->setText(QString());
        label_37->setText(QApplication::translate("MainWindow", "Switch 3", 0));
        label_34->setText(QApplication::translate("MainWindow", "Switch 5", 0));
        lockin_7up->setText(QString());
        label_38->setText(QApplication::translate("MainWindow", "Switch 1", 0));
        lockin_1down->setText(QString());
        lockin_5up->setText(QString());
        lockin_8up->setText(QString());
        lockin_6down->setText(QString());
        lockin_5down->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "Switch 2", 0));
        lockin_1up->setText(QString());
        lockin_3up->setText(QString());
        lockin_2up->setText(QString());
        lockin_4up->setText(QString());
        lockin_6up->setText(QString());
        lockin_8down->setText(QString());
        lockin_7down->setText(QString());
        label_39->setText(QApplication::translate("MainWindow", "Up", 0));
        label_40->setText(QApplication::translate("MainWindow", "Down", 0));
        lockin_3down->setText(QString());
        label_41->setText(QApplication::translate("MainWindow", "Baudrate", 0));
        label_42->setText(QApplication::translate("MainWindow", "Stopbits", 0));
        label_45->setText(QApplication::translate("MainWindow", "Parity", 0));
        label_46->setText(QApplication::translate("MainWindow", "Echo mode", 0));
        gridTabWidget->setTabText(gridTabWidget->indexOf(Lockintab), QApplication::translate("MainWindow", "Lock-in settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
