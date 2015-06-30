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
    QByteArrayData data[82];
    char stringdata[1323];
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
QT_MOC_LITERAL(30, 369, 10), // "mousePoint"
QT_MOC_LITERAL(31, 380, 5), // "point"
QT_MOC_LITERAL(32, 386, 13), // "connectStatus"
QT_MOC_LITERAL(33, 400, 13), // "calibrateScan"
QT_MOC_LITERAL(34, 414, 9), // "ScanData&"
QT_MOC_LITERAL(35, 424, 7), // "newScan"
QT_MOC_LITERAL(36, 432, 10), // "sortPoints"
QT_MOC_LITERAL(37, 443, 16), // "getNearestPoints"
QT_MOC_LITERAL(38, 460, 37), // "QPair<QPair<int,int>,QPair<in..."
QT_MOC_LITERAL(39, 498, 4), // "xVal"
QT_MOC_LITERAL(40, 503, 14), // "calculateValue"
QT_MOC_LITERAL(41, 518, 11), // "targetPoint"
QT_MOC_LITERAL(42, 530, 10), // "firstPoint"
QT_MOC_LITERAL(43, 541, 11), // "secondPoint"
QT_MOC_LITERAL(44, 553, 17), // "calculateInvValue"
QT_MOC_LITERAL(45, 571, 28), // "on_loadGenericButton_clicked"
QT_MOC_LITERAL(46, 600, 4), // "open"
QT_MOC_LITERAL(47, 605, 11), // "openGeneric"
QT_MOC_LITERAL(48, 617, 4), // "save"
QT_MOC_LITERAL(49, 622, 11), // "saveGeneric"
QT_MOC_LITERAL(50, 634, 19), // "saveGenericAllPlots"
QT_MOC_LITERAL(51, 654, 21), // "on_dispXValue_toggled"
QT_MOC_LITERAL(52, 676, 7), // "checked"
QT_MOC_LITERAL(53, 684, 21), // "on_dispYValue_toggled"
QT_MOC_LITERAL(54, 706, 21), // "on_dispZValue_toggled"
QT_MOC_LITERAL(55, 728, 21), // "on_scanButton_clicked"
QT_MOC_LITERAL(56, 750, 19), // "on_LastScan_clicked"
QT_MOC_LITERAL(57, 770, 19), // "on_NextScan_clicked"
QT_MOC_LITERAL(58, 790, 36), // "on_selectScanBox_currentIndex..."
QT_MOC_LITERAL(59, 827, 5), // "index"
QT_MOC_LITERAL(60, 833, 19), // "on_saveScan_clicked"
QT_MOC_LITERAL(61, 853, 11), // "reload_data"
QT_MOC_LITERAL(62, 865, 23), // "on_stepBackMono_clicked"
QT_MOC_LITERAL(63, 889, 26), // "on_stepForwardMono_clicked"
QT_MOC_LITERAL(64, 916, 21), // "on_mvButton_2_clicked"
QT_MOC_LITERAL(65, 938, 20), // "on_logButton_clicked"
QT_MOC_LITERAL(66, 959, 13), // "createLogData"
QT_MOC_LITERAL(67, 973, 10), // "loadConfig"
QT_MOC_LITERAL(68, 984, 11), // "writeConfig"
QT_MOC_LITERAL(69, 996, 23), // "on_execButton_2_clicked"
QT_MOC_LITERAL(70, 1020, 31), // "on_gridTabWidget_currentChanged"
QT_MOC_LITERAL(71, 1052, 18), // "on_newScan_clicked"
QT_MOC_LITERAL(72, 1071, 19), // "on_stopScan_clicked"
QT_MOC_LITERAL(73, 1091, 29), // "on_saveSettingsButton_clicked"
QT_MOC_LITERAL(74, 1121, 29), // "on_loadSettingsButton_clicked"
QT_MOC_LITERAL(75, 1151, 21), // "on_centerMono_clicked"
QT_MOC_LITERAL(76, 1173, 18), // "on_connect_clicked"
QT_MOC_LITERAL(77, 1192, 22), // "on_CalibButton_clicked"
QT_MOC_LITERAL(78, 1215, 24), // "on_CalibFinished_clicked"
QT_MOC_LITERAL(79, 1240, 23), // "on_CalibConfirm_clicked"
QT_MOC_LITERAL(80, 1264, 25), // "on_AddMovementLog_clicked"
QT_MOC_LITERAL(81, 1290, 32) // "on_AddMovementCommentLog_clicked"

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
    "StepperMoving\0mousePoint\0point\0"
    "connectStatus\0calibrateScan\0ScanData&\0"
    "newScan\0sortPoints\0getNearestPoints\0"
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
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  334,    2, 0x06 /* Public */,
       4,    2,  339,    2, 0x06 /* Public */,
       5,    2,  344,    2, 0x06 /* Public */,
       6,    2,  349,    2, 0x06 /* Public */,
       7,    2,  354,    2, 0x06 /* Public */,
       8,    2,  359,    2, 0x06 /* Public */,
       9,    0,  364,    2, 0x06 /* Public */,
      10,    0,  365,    2, 0x06 /* Public */,
      11,    0,  366,    2, 0x06 /* Public */,
      12,    0,  367,    2, 0x06 /* Public */,
      13,    0,  368,    2, 0x06 /* Public */,
      14,    5,  369,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  380,    2, 0x0a /* Public */,
      16,    1,  381,    2, 0x0a /* Public */,
      18,    0,  384,    2, 0x0a /* Public */,
      19,    2,  385,    2, 0x0a /* Public */,
      21,    0,  390,    2, 0x0a /* Public */,
      22,    1,  391,    2, 0x0a /* Public */,
      24,    1,  394,    2, 0x0a /* Public */,
      27,    0,  397,    2, 0x0a /* Public */,
      28,    0,  398,    2, 0x0a /* Public */,
      29,    0,  399,    2, 0x0a /* Public */,
      30,    1,  400,    2, 0x0a /* Public */,
      32,    1,  403,    2, 0x0a /* Public */,
      33,    1,  406,    2, 0x0a /* Public */,
      36,    0,  409,    2, 0x0a /* Public */,
      37,    1,  410,    2, 0x0a /* Public */,
      40,    3,  413,    2, 0x0a /* Public */,
      44,    3,  420,    2, 0x0a /* Public */,
      45,    0,  427,    2, 0x08 /* Private */,
      46,    0,  428,    2, 0x08 /* Private */,
      47,    0,  429,    2, 0x08 /* Private */,
      48,    0,  430,    2, 0x08 /* Private */,
      49,    0,  431,    2, 0x08 /* Private */,
      50,    0,  432,    2, 0x08 /* Private */,
      51,    1,  433,    2, 0x08 /* Private */,
      53,    1,  436,    2, 0x08 /* Private */,
      54,    1,  439,    2, 0x08 /* Private */,
      55,    0,  442,    2, 0x08 /* Private */,
      56,    0,  443,    2, 0x08 /* Private */,
      57,    0,  444,    2, 0x08 /* Private */,
      58,    1,  445,    2, 0x08 /* Private */,
      60,    0,  448,    2, 0x08 /* Private */,
      61,    0,  449,    2, 0x08 /* Private */,
      62,    0,  450,    2, 0x08 /* Private */,
      63,    0,  451,    2, 0x08 /* Private */,
      64,    0,  452,    2, 0x08 /* Private */,
      65,    0,  453,    2, 0x08 /* Private */,
      66,    0,  454,    2, 0x08 /* Private */,
      67,    0,  455,    2, 0x08 /* Private */,
      68,    0,  456,    2, 0x08 /* Private */,
      69,    0,  457,    2, 0x08 /* Private */,
      70,    1,  458,    2, 0x08 /* Private */,
      71,    0,  461,    2, 0x08 /* Private */,
      72,    0,  462,    2, 0x08 /* Private */,
      73,    0,  463,    2, 0x08 /* Private */,
      74,    0,  464,    2, 0x08 /* Private */,
      75,    0,  465,    2, 0x08 /* Private */,
      76,    0,  466,    2, 0x08 /* Private */,
      77,    0,  467,    2, 0x08 /* Private */,
      78,    0,  468,    2, 0x08 /* Private */,
      79,    0,  469,    2, 0x08 /* Private */,
      80,    0,  470,    2, 0x08 /* Private */,
      81,    0,  471,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QPointF,   31,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    0x80000000 | 38, QMetaType::Int,   39,
    QMetaType::Int, 0x80000000 | 25, 0x80000000 | 25, 0x80000000 | 25,   41,   42,   43,
    QMetaType::Int, 0x80000000 | 25, 0x80000000 | 25, 0x80000000 | 25,   41,   42,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
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
    QMetaType::Void, QMetaType::Int,   59,
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
        case 22: _t->mousePoint((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 23: _t->connectStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->calibrateScan((*reinterpret_cast< ScanData(*)>(_a[1]))); break;
        case 25: _t->sortPoints(); break;
        case 26: { QPair<QPair<int,int>,QPair<int,int> > _r = _t->getNearestPoints((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPair<QPair<int,int>,QPair<int,int> >*>(_a[0]) = _r; }  break;
        case 27: { int _r = _t->calculateValue((*reinterpret_cast< QPair<int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->calculateInvValue((*reinterpret_cast< QPair<int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: _t->on_loadGenericButton_clicked(); break;
        case 30: _t->open(); break;
        case 31: _t->openGeneric(); break;
        case 32: _t->save(); break;
        case 33: _t->saveGeneric(); break;
        case 34: _t->saveGenericAllPlots(); break;
        case 35: _t->on_dispXValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_dispYValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_dispZValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_scanButton_clicked(); break;
        case 39: _t->on_LastScan_clicked(); break;
        case 40: _t->on_NextScan_clicked(); break;
        case 41: _t->on_selectScanBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_saveScan_clicked(); break;
        case 43: _t->reload_data(); break;
        case 44: _t->on_stepBackMono_clicked(); break;
        case 45: _t->on_stepForwardMono_clicked(); break;
        case 46: _t->on_mvButton_2_clicked(); break;
        case 47: _t->on_logButton_clicked(); break;
        case 48: _t->createLogData(); break;
        case 49: _t->loadConfig(); break;
        case 50: _t->writeConfig(); break;
        case 51: _t->on_execButton_2_clicked(); break;
        case 52: _t->on_gridTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->on_newScan_clicked(); break;
        case 54: _t->on_stopScan_clicked(); break;
        case 55: _t->on_saveSettingsButton_clicked(); break;
        case 56: _t->on_loadSettingsButton_clicked(); break;
        case 57: _t->on_centerMono_clicked(); break;
        case 58: _t->on_connect_clicked(); break;
        case 59: _t->on_CalibButton_clicked(); break;
        case 60: _t->on_CalibFinished_clicked(); break;
        case 61: _t->on_CalibConfirm_clicked(); break;
        case 62: _t->on_AddMovementLog_clicked(); break;
        case 63: _t->on_AddMovementCommentLog_clicked(); break;
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
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
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
