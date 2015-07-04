/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[83];
    char stringdata[1340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "xPolarizerMoved"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "Polarizer"
QT_MOC_LITERAL(4, 38, 15), // "yPolarizerMoved"
QT_MOC_LITERAL(5, 54, 15), // "zPolarizerMoved"
QT_MOC_LITERAL(6, 70, 10), // "MoveStepUp"
QT_MOC_LITERAL(7, 81, 12), // "MoveStepDown"
QT_MOC_LITERAL(8, 94, 12), // "MoveToTarget"
QT_MOC_LITERAL(9, 107, 12), // "stopCounting"
QT_MOC_LITERAL(10, 120, 15), // "stopControlling"
QT_MOC_LITERAL(11, 136, 8), // "stopScan"
QT_MOC_LITERAL(12, 145, 9), // "startScan"
QT_MOC_LITERAL(13, 155, 11), // "killScanner"
QT_MOC_LITERAL(14, 167, 11), // "initScanner"
QT_MOC_LITERAL(15, 179, 9), // "calibrate"
QT_MOC_LITERAL(16, 189, 14), // "oncurrentCount"
QT_MOC_LITERAL(17, 204, 6), // "counts"
QT_MOC_LITERAL(18, 211, 16), // "closeProgressBar"
QT_MOC_LITERAL(19, 228, 11), // "addNewValue"
QT_MOC_LITERAL(20, 240, 7), // "wNumber"
QT_MOC_LITERAL(21, 248, 17), // "scanIsInterrupted"
QT_MOC_LITERAL(22, 266, 17), // "CurrentScanStatus"
QT_MOC_LITERAL(23, 284, 6), // "status"
QT_MOC_LITERAL(24, 291, 12), // "incomingData"
QT_MOC_LITERAL(25, 304, 14), // "QPair<int,int>"
QT_MOC_LITERAL(26, 319, 4), // "data"
QT_MOC_LITERAL(27, 324, 14), // "scanIsFinished"
QT_MOC_LITERAL(28, 339, 15), // "PositionChanged"
QT_MOC_LITERAL(29, 355, 13), // "StepperMoving"
QT_MOC_LITERAL(30, 369, 16), // "newStepperStatus"
QT_MOC_LITERAL(31, 386, 10), // "mousePoint"
QT_MOC_LITERAL(32, 397, 5), // "point"
QT_MOC_LITERAL(33, 403, 13), // "connectStatus"
QT_MOC_LITERAL(34, 417, 13), // "calibrateScan"
QT_MOC_LITERAL(35, 431, 9), // "ScanData&"
QT_MOC_LITERAL(36, 441, 7), // "newScan"
QT_MOC_LITERAL(37, 449, 10), // "sortPoints"
QT_MOC_LITERAL(38, 460, 16), // "getNearestPoints"
QT_MOC_LITERAL(39, 477, 37), // "QPair<QPair<int,int>,QPair<in..."
QT_MOC_LITERAL(40, 515, 4), // "xVal"
QT_MOC_LITERAL(41, 520, 14), // "calculateValue"
QT_MOC_LITERAL(42, 535, 11), // "targetPoint"
QT_MOC_LITERAL(43, 547, 10), // "firstPoint"
QT_MOC_LITERAL(44, 558, 11), // "secondPoint"
QT_MOC_LITERAL(45, 570, 17), // "calculateInvValue"
QT_MOC_LITERAL(46, 588, 28), // "on_loadGenericButton_clicked"
QT_MOC_LITERAL(47, 617, 4), // "open"
QT_MOC_LITERAL(48, 622, 11), // "openGeneric"
QT_MOC_LITERAL(49, 634, 4), // "save"
QT_MOC_LITERAL(50, 639, 11), // "saveGeneric"
QT_MOC_LITERAL(51, 651, 19), // "saveGenericAllPlots"
QT_MOC_LITERAL(52, 671, 21), // "on_dispXValue_toggled"
QT_MOC_LITERAL(53, 693, 7), // "checked"
QT_MOC_LITERAL(54, 701, 21), // "on_dispYValue_toggled"
QT_MOC_LITERAL(55, 723, 21), // "on_dispZValue_toggled"
QT_MOC_LITERAL(56, 745, 21), // "on_scanButton_clicked"
QT_MOC_LITERAL(57, 767, 19), // "on_LastScan_clicked"
QT_MOC_LITERAL(58, 787, 19), // "on_NextScan_clicked"
QT_MOC_LITERAL(59, 807, 36), // "on_selectScanBox_currentIndex..."
QT_MOC_LITERAL(60, 844, 5), // "index"
QT_MOC_LITERAL(61, 850, 19), // "on_saveScan_clicked"
QT_MOC_LITERAL(62, 870, 11), // "reload_data"
QT_MOC_LITERAL(63, 882, 23), // "on_stepBackMono_clicked"
QT_MOC_LITERAL(64, 906, 26), // "on_stepForwardMono_clicked"
QT_MOC_LITERAL(65, 933, 21), // "on_mvButton_2_clicked"
QT_MOC_LITERAL(66, 955, 20), // "on_logButton_clicked"
QT_MOC_LITERAL(67, 976, 13), // "createLogData"
QT_MOC_LITERAL(68, 990, 10), // "loadConfig"
QT_MOC_LITERAL(69, 1001, 11), // "writeConfig"
QT_MOC_LITERAL(70, 1013, 23), // "on_execButton_2_clicked"
QT_MOC_LITERAL(71, 1037, 31), // "on_gridTabWidget_currentChanged"
QT_MOC_LITERAL(72, 1069, 18), // "on_newScan_clicked"
QT_MOC_LITERAL(73, 1088, 19), // "on_stopScan_clicked"
QT_MOC_LITERAL(74, 1108, 29), // "on_saveSettingsButton_clicked"
QT_MOC_LITERAL(75, 1138, 29), // "on_loadSettingsButton_clicked"
QT_MOC_LITERAL(76, 1168, 21), // "on_centerMono_clicked"
QT_MOC_LITERAL(77, 1190, 18), // "on_connect_clicked"
QT_MOC_LITERAL(78, 1209, 22), // "on_CalibButton_clicked"
QT_MOC_LITERAL(79, 1232, 24), // "on_CalibFinished_clicked"
QT_MOC_LITERAL(80, 1257, 23), // "on_CalibConfirm_clicked"
QT_MOC_LITERAL(81, 1281, 25), // "on_AddMovementLog_clicked"
QT_MOC_LITERAL(82, 1307, 32) // "on_AddMovementCommentLog_clicked"

    },
    "MainWindow\0xPolarizerMoved\0\0Polarizer\0"
    "yPolarizerMoved\0zPolarizerMoved\0"
    "MoveStepUp\0MoveStepDown\0MoveToTarget\0"
    "stopCounting\0stopControlling\0stopScan\0"
    "startScan\0killScanner\0initScanner\0"
    "calibrate\0oncurrentCount\0counts\0"
    "closeProgressBar\0addNewValue\0wNumber\0"
    "scanIsInterrupted\0CurrentScanStatus\0"
    "status\0incomingData\0QPair<int,int>\0"
    "data\0scanIsFinished\0PositionChanged\0"
    "StepperMoving\0newStepperStatus\0"
    "mousePoint\0point\0connectStatus\0"
    "calibrateScan\0ScanData&\0newScan\0"
    "sortPoints\0getNearestPoints\0"
    "QPair<QPair<int,int>,QPair<int,int> >\0"
    "xVal\0calculateValue\0targetPoint\0"
    "firstPoint\0secondPoint\0calculateInvValue\0"
    "on_loadGenericButton_clicked\0open\0"
    "openGeneric\0save\0saveGeneric\0"
    "saveGenericAllPlots\0on_dispXValue_toggled\0"
    "checked\0on_dispYValue_toggled\0"
    "on_dispZValue_toggled\0on_scanButton_clicked\0"
    "on_LastScan_clicked\0on_NextScan_clicked\0"
    "on_selectScanBox_currentIndexChanged\0"
    "index\0on_saveScan_clicked\0reload_data\0"
    "on_stepBackMono_clicked\0"
    "on_stepForwardMono_clicked\0"
    "on_mvButton_2_clicked\0on_logButton_clicked\0"
    "createLogData\0loadConfig\0writeConfig\0"
    "on_execButton_2_clicked\0"
    "on_gridTabWidget_currentChanged\0"
    "on_newScan_clicked\0on_stopScan_clicked\0"
    "on_saveSettingsButton_clicked\0"
    "on_loadSettingsButton_clicked\0"
    "on_centerMono_clicked\0on_connect_clicked\0"
    "on_CalibButton_clicked\0on_CalibFinished_clicked\0"
    "on_CalibConfirm_clicked\0"
    "on_AddMovementLog_clicked\0"
    "on_AddMovementCommentLog_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  339,    2, 0x06 /* Public */,
       4,    2,  344,    2, 0x06 /* Public */,
       5,    2,  349,    2, 0x06 /* Public */,
       6,    2,  354,    2, 0x06 /* Public */,
       7,    2,  359,    2, 0x06 /* Public */,
       8,    2,  364,    2, 0x06 /* Public */,
       9,    0,  369,    2, 0x06 /* Public */,
      10,    0,  370,    2, 0x06 /* Public */,
      11,    0,  371,    2, 0x06 /* Public */,
      12,    0,  372,    2, 0x06 /* Public */,
      13,    0,  373,    2, 0x06 /* Public */,
      14,    5,  374,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  385,    2, 0x0a /* Public */,
      16,    1,  386,    2, 0x0a /* Public */,
      18,    0,  389,    2, 0x0a /* Public */,
      19,    2,  390,    2, 0x0a /* Public */,
      21,    0,  395,    2, 0x0a /* Public */,
      22,    1,  396,    2, 0x0a /* Public */,
      24,    1,  399,    2, 0x0a /* Public */,
      27,    0,  402,    2, 0x0a /* Public */,
      28,    0,  403,    2, 0x0a /* Public */,
      29,    0,  404,    2, 0x0a /* Public */,
      30,    1,  405,    2, 0x0a /* Public */,
      31,    1,  408,    2, 0x0a /* Public */,
      33,    1,  411,    2, 0x0a /* Public */,
      34,    1,  414,    2, 0x0a /* Public */,
      37,    0,  417,    2, 0x0a /* Public */,
      38,    1,  418,    2, 0x0a /* Public */,
      41,    3,  421,    2, 0x0a /* Public */,
      45,    3,  428,    2, 0x0a /* Public */,
      46,    0,  435,    2, 0x08 /* Private */,
      47,    0,  436,    2, 0x08 /* Private */,
      48,    0,  437,    2, 0x08 /* Private */,
      49,    0,  438,    2, 0x08 /* Private */,
      50,    0,  439,    2, 0x08 /* Private */,
      51,    0,  440,    2, 0x08 /* Private */,
      52,    1,  441,    2, 0x08 /* Private */,
      54,    1,  444,    2, 0x08 /* Private */,
      55,    1,  447,    2, 0x08 /* Private */,
      56,    0,  450,    2, 0x08 /* Private */,
      57,    0,  451,    2, 0x08 /* Private */,
      58,    0,  452,    2, 0x08 /* Private */,
      59,    1,  453,    2, 0x08 /* Private */,
      61,    0,  456,    2, 0x08 /* Private */,
      62,    0,  457,    2, 0x08 /* Private */,
      63,    0,  458,    2, 0x08 /* Private */,
      64,    0,  459,    2, 0x08 /* Private */,
      65,    0,  460,    2, 0x08 /* Private */,
      66,    0,  461,    2, 0x08 /* Private */,
      67,    0,  462,    2, 0x08 /* Private */,
      68,    0,  463,    2, 0x08 /* Private */,
      69,    0,  464,    2, 0x08 /* Private */,
      70,    0,  465,    2, 0x08 /* Private */,
      71,    1,  466,    2, 0x08 /* Private */,
      72,    0,  469,    2, 0x08 /* Private */,
      73,    0,  470,    2, 0x08 /* Private */,
      74,    0,  471,    2, 0x08 /* Private */,
      75,    0,  472,    2, 0x08 /* Private */,
      76,    0,  473,    2, 0x08 /* Private */,
      77,    0,  474,    2, 0x08 /* Private */,
      78,    0,  475,    2, 0x08 /* Private */,
      79,    0,  476,    2, 0x08 /* Private */,
      80,    0,  477,    2, 0x08 /* Private */,
      81,    0,  478,    2, 0x08 /* Private */,
      82,    0,  479,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   20,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QPointF,   32,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    0x80000000 | 39, QMetaType::Int,   40,
    QMetaType::Int, 0x80000000 | 25, 0x80000000 | 25, 0x80000000 | 25,   42,   43,   44,
    QMetaType::Int, 0x80000000 | 25, 0x80000000 | 25, 0x80000000 | 25,   42,   43,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   53,
    QMetaType::Void, QMetaType::Bool,   53,
    QMetaType::Void, QMetaType::Bool,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->xPolarizerMoved((*reinterpret_cast< Polarizer(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->yPolarizerMoved((*reinterpret_cast< Polarizer(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->zPolarizerMoved((*reinterpret_cast< Polarizer(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->MoveStepUp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->MoveStepDown((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->MoveToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->stopCounting(); break;
        case 7: _t->stopControlling(); break;
        case 8: _t->stopScan(); break;
        case 9: _t->startScan(); break;
        case 10: _t->killScanner(); break;
        case 11: _t->initScanner((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 12: _t->calibrate(); break;
        case 13: _t->oncurrentCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->closeProgressBar(); break;
        case 15: _t->addNewValue((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 16: _t->scanIsInterrupted(); break;
        case 17: _t->CurrentScanStatus((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 18: _t->incomingData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 19: _t->scanIsFinished(); break;
        case 20: _t->PositionChanged(); break;
        case 21: _t->StepperMoving(); break;
        case 22: _t->newStepperStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->mousePoint((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 24: _t->connectStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->calibrateScan((*reinterpret_cast< ScanData(*)>(_a[1]))); break;
        case 26: _t->sortPoints(); break;
        case 27: { QPair<QPair<int,int>,QPair<int,int> > _r = _t->getNearestPoints((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPair<QPair<int,int>,QPair<int,int> >*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->calculateValue((*reinterpret_cast< QPair<int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { int _r = _t->calculateInvValue((*reinterpret_cast< QPair<int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 30: _t->on_loadGenericButton_clicked(); break;
        case 31: _t->open(); break;
        case 32: _t->openGeneric(); break;
        case 33: _t->save(); break;
        case 34: _t->saveGeneric(); break;
        case 35: _t->saveGenericAllPlots(); break;
        case 36: _t->on_dispXValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_dispYValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_dispZValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_scanButton_clicked(); break;
        case 40: _t->on_LastScan_clicked(); break;
        case 41: _t->on_NextScan_clicked(); break;
        case 42: _t->on_selectScanBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_saveScan_clicked(); break;
        case 44: _t->reload_data(); break;
        case 45: _t->on_stepBackMono_clicked(); break;
        case 46: _t->on_stepForwardMono_clicked(); break;
        case 47: _t->on_mvButton_2_clicked(); break;
        case 48: _t->on_logButton_clicked(); break;
        case 49: _t->createLogData(); break;
        case 50: _t->loadConfig(); break;
        case 51: _t->writeConfig(); break;
        case 52: _t->on_execButton_2_clicked(); break;
        case 53: _t->on_gridTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->on_newScan_clicked(); break;
        case 55: _t->on_stopScan_clicked(); break;
        case 56: _t->on_saveSettingsButton_clicked(); break;
        case 57: _t->on_loadSettingsButton_clicked(); break;
        case 58: _t->on_centerMono_clicked(); break;
        case 59: _t->on_connect_clicked(); break;
        case 60: _t->on_CalibButton_clicked(); break;
        case 61: _t->on_CalibFinished_clicked(); break;
        case 62: _t->on_CalibConfirm_clicked(); break;
        case 63: _t->on_AddMovementLog_clicked(); break;
        case 64: _t->on_AddMovementCommentLog_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Polarizer , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::xPolarizerMoved)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(Polarizer , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::yPolarizerMoved)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)(Polarizer , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::zPolarizerMoved)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MoveStepUp)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MoveStepDown)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MoveToTarget)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::stopCounting)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::stopControlling)) {
                *result = 7;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::stopScan)) {
                *result = 8;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startScan)) {
                *result = 9;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::killScanner)) {
                *result = 10;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , int , int , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::initScanner)) {
                *result = 11;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::xPolarizerMoved(Polarizer _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::yPolarizerMoved(Polarizer _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::zPolarizerMoved(Polarizer _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::MoveStepUp(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::MoveStepDown(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::MoveToTarget(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::stopCounting()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MainWindow::stopControlling()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MainWindow::stopScan()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void MainWindow::startScan()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void MainWindow::killScanner()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MainWindow::initScanner(int _t1, int _t2, int _t3, int _t4, bool _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
