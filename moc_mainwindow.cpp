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
    QByteArrayData data[139];
    char stringdata[2770];
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
QT_MOC_LITERAL(15, 179, 13), // "continue_scan"
QT_MOC_LITERAL(16, 193, 6), // "counts"
QT_MOC_LITERAL(17, 200, 9), // "calibrate"
QT_MOC_LITERAL(18, 210, 14), // "oncurrentCount"
QT_MOC_LITERAL(19, 225, 19), // "onCurrentAquisition"
QT_MOC_LITERAL(20, 245, 16), // "closeProgressBar"
QT_MOC_LITERAL(21, 262, 11), // "addNewValue"
QT_MOC_LITERAL(22, 274, 7), // "wNumber"
QT_MOC_LITERAL(23, 282, 17), // "scanIsInterrupted"
QT_MOC_LITERAL(24, 300, 17), // "CurrentScanStatus"
QT_MOC_LITERAL(25, 318, 6), // "status"
QT_MOC_LITERAL(26, 325, 12), // "incomingData"
QT_MOC_LITERAL(27, 338, 14), // "QPair<int,int>"
QT_MOC_LITERAL(28, 353, 4), // "data"
QT_MOC_LITERAL(29, 358, 14), // "scanIsFinished"
QT_MOC_LITERAL(30, 373, 15), // "PositionChanged"
QT_MOC_LITERAL(31, 389, 13), // "StepperMoving"
QT_MOC_LITERAL(32, 403, 16), // "newStepperStatus"
QT_MOC_LITERAL(33, 420, 10), // "mousePoint"
QT_MOC_LITERAL(34, 431, 5), // "point"
QT_MOC_LITERAL(35, 437, 13), // "connectStatus"
QT_MOC_LITERAL(36, 451, 13), // "calibrateScan"
QT_MOC_LITERAL(37, 465, 9), // "ScanData&"
QT_MOC_LITERAL(38, 475, 7), // "newScan"
QT_MOC_LITERAL(39, 483, 10), // "sortPoints"
QT_MOC_LITERAL(40, 494, 16), // "getNearestPoints"
QT_MOC_LITERAL(41, 511, 37), // "QPair<QPair<int,int>,QPair<in..."
QT_MOC_LITERAL(42, 549, 4), // "xVal"
QT_MOC_LITERAL(43, 554, 14), // "calculateValue"
QT_MOC_LITERAL(44, 569, 23), // "std::tuple<int,int,int>"
QT_MOC_LITERAL(45, 593, 11), // "targetTuple"
QT_MOC_LITERAL(46, 605, 10), // "firstPoint"
QT_MOC_LITERAL(47, 616, 11), // "secondPoint"
QT_MOC_LITERAL(48, 628, 17), // "calculateInvValue"
QT_MOC_LITERAL(49, 646, 11), // "targetPoint"
QT_MOC_LITERAL(50, 658, 20), // "serialConnectionUsed"
QT_MOC_LITERAL(51, 679, 5), // "set_1"
QT_MOC_LITERAL(52, 685, 5), // "set_2"
QT_MOC_LITERAL(53, 691, 5), // "set_3"
QT_MOC_LITERAL(54, 697, 5), // "set_4"
QT_MOC_LITERAL(55, 703, 5), // "set_5"
QT_MOC_LITERAL(56, 709, 5), // "set_6"
QT_MOC_LITERAL(57, 715, 5), // "set_7"
QT_MOC_LITERAL(58, 721, 5), // "set_8"
QT_MOC_LITERAL(59, 727, 18), // "continue_this_scan"
QT_MOC_LITERAL(60, 746, 28), // "on_loadGenericButton_clicked"
QT_MOC_LITERAL(61, 775, 4), // "open"
QT_MOC_LITERAL(62, 780, 11), // "openGeneric"
QT_MOC_LITERAL(63, 792, 4), // "save"
QT_MOC_LITERAL(64, 797, 11), // "saveGeneric"
QT_MOC_LITERAL(65, 809, 19), // "saveGenericAllPlots"
QT_MOC_LITERAL(66, 829, 21), // "on_dispXValue_toggled"
QT_MOC_LITERAL(67, 851, 7), // "checked"
QT_MOC_LITERAL(68, 859, 21), // "on_dispYValue_toggled"
QT_MOC_LITERAL(69, 881, 21), // "on_dispZValue_toggled"
QT_MOC_LITERAL(70, 903, 21), // "on_scanButton_clicked"
QT_MOC_LITERAL(71, 925, 19), // "on_LastScan_clicked"
QT_MOC_LITERAL(72, 945, 19), // "on_NextScan_clicked"
QT_MOC_LITERAL(73, 965, 36), // "on_selectScanBox_currentIndex..."
QT_MOC_LITERAL(74, 1002, 5), // "index"
QT_MOC_LITERAL(75, 1008, 19), // "on_saveScan_clicked"
QT_MOC_LITERAL(76, 1028, 11), // "reload_data"
QT_MOC_LITERAL(77, 1040, 14), // "stepperStopped"
QT_MOC_LITERAL(78, 1055, 23), // "on_stepBackMono_clicked"
QT_MOC_LITERAL(79, 1079, 26), // "on_stepForwardMono_clicked"
QT_MOC_LITERAL(80, 1106, 21), // "on_mvButton_2_clicked"
QT_MOC_LITERAL(81, 1128, 20), // "on_logButton_clicked"
QT_MOC_LITERAL(82, 1149, 13), // "createLogData"
QT_MOC_LITERAL(83, 1163, 10), // "loadConfig"
QT_MOC_LITERAL(84, 1174, 11), // "writeConfig"
QT_MOC_LITERAL(85, 1186, 23), // "on_execButton_2_clicked"
QT_MOC_LITERAL(86, 1210, 31), // "on_gridTabWidget_currentChanged"
QT_MOC_LITERAL(87, 1242, 18), // "on_newScan_clicked"
QT_MOC_LITERAL(88, 1261, 19), // "on_stopScan_clicked"
QT_MOC_LITERAL(89, 1281, 29), // "on_saveSettingsButton_clicked"
QT_MOC_LITERAL(90, 1311, 29), // "on_loadSettingsButton_clicked"
QT_MOC_LITERAL(91, 1341, 21), // "on_centerMono_clicked"
QT_MOC_LITERAL(92, 1363, 18), // "on_connect_clicked"
QT_MOC_LITERAL(93, 1382, 22), // "on_CalibButton_clicked"
QT_MOC_LITERAL(94, 1405, 24), // "on_CalibFinished_clicked"
QT_MOC_LITERAL(95, 1430, 23), // "on_CalibConfirm_clicked"
QT_MOC_LITERAL(96, 1454, 25), // "on_AddMovementLog_clicked"
QT_MOC_LITERAL(97, 1480, 32), // "on_AddMovementCommentLog_clicked"
QT_MOC_LITERAL(98, 1513, 34), // "on_manual_StartMeasurement_cl..."
QT_MOC_LITERAL(99, 1548, 30), // "on_manual_confirmValue_clicked"
QT_MOC_LITERAL(100, 1579, 30), // "on_manual_centralWL_textEdited"
QT_MOC_LITERAL(101, 1610, 4), // "arg1"
QT_MOC_LITERAL(102, 1615, 28), // "on_manual_StartWL_textEdited"
QT_MOC_LITERAL(103, 1644, 27), // "on_manual_StopWL_textEdited"
QT_MOC_LITERAL(104, 1672, 30), // "on_manual_CentralWN_textEdited"
QT_MOC_LITERAL(105, 1703, 28), // "on_manual_StartWN_textEdited"
QT_MOC_LITERAL(106, 1732, 27), // "on_manual_StopWN_textEdited"
QT_MOC_LITERAL(107, 1760, 33), // "on_manual_currWaveNum_textCha..."
QT_MOC_LITERAL(108, 1794, 31), // "on_manual_CentralWN_textChanged"
QT_MOC_LITERAL(109, 1826, 25), // "on_connect_serial_clicked"
QT_MOC_LITERAL(110, 1852, 27), // "on_serial_transmitt_clicked"
QT_MOC_LITERAL(111, 1880, 26), // "on_lockin_1up_stateChanged"
QT_MOC_LITERAL(112, 1907, 26), // "on_lockin_2up_stateChanged"
QT_MOC_LITERAL(113, 1934, 26), // "on_lockin_3up_stateChanged"
QT_MOC_LITERAL(114, 1961, 26), // "on_lockin_4up_stateChanged"
QT_MOC_LITERAL(115, 1988, 26), // "on_lockin_5up_stateChanged"
QT_MOC_LITERAL(116, 2015, 26), // "on_lockin_6up_stateChanged"
QT_MOC_LITERAL(117, 2042, 26), // "on_lockin_7up_stateChanged"
QT_MOC_LITERAL(118, 2069, 26), // "on_lockin_8up_stateChanged"
QT_MOC_LITERAL(119, 2096, 28), // "on_lockin_1down_stateChanged"
QT_MOC_LITERAL(120, 2125, 28), // "on_lockin_2down_stateChanged"
QT_MOC_LITERAL(121, 2154, 28), // "on_lockin_3down_stateChanged"
QT_MOC_LITERAL(122, 2183, 28), // "on_lockin_4down_stateChanged"
QT_MOC_LITERAL(123, 2212, 28), // "on_lockin_5down_stateChanged"
QT_MOC_LITERAL(124, 2241, 28), // "on_lockin_6down_stateChanged"
QT_MOC_LITERAL(125, 2270, 28), // "on_lockin_7down_stateChanged"
QT_MOC_LITERAL(126, 2299, 28), // "on_lockin_8down_stateChanged"
QT_MOC_LITERAL(127, 2328, 40), // "on_lockin_baud_combo_currentI..."
QT_MOC_LITERAL(128, 2369, 40), // "on_lockin_stop_combo_currentI..."
QT_MOC_LITERAL(129, 2410, 36), // "on_lockin_Parity_currentIndex..."
QT_MOC_LITERAL(130, 2447, 38), // "on_lockin_EchoMode_currentInd..."
QT_MOC_LITERAL(131, 2486, 32), // "on_UpdateCurrentPosition_clicked"
QT_MOC_LITERAL(132, 2519, 28), // "on_manual_CancelScan_clicked"
QT_MOC_LITERAL(133, 2548, 35), // "on_change_Xvals_currentIndexC..."
QT_MOC_LITERAL(134, 2584, 25), // "on_lockin_SetTime_clicked"
QT_MOC_LITERAL(135, 2610, 38), // "on_setTimeConstant_currentInd..."
QT_MOC_LITERAL(136, 2649, 25), // "on_lockin_getTime_clicked"
QT_MOC_LITERAL(137, 2675, 45), // "on_setInterpolationMethod_cur..."
QT_MOC_LITERAL(138, 2721, 48) // "on_setInterpolationVariables_..."

    },
    "MainWindow\0xPolarizerMoved\0\0Polarizer\0"
    "yPolarizerMoved\0zPolarizerMoved\0"
    "MoveStepUp\0MoveStepDown\0MoveToTarget\0"
    "stopCounting\0stopControlling\0stopScan\0"
    "startScan\0killScanner\0initScanner\0"
    "continue_scan\0counts\0calibrate\0"
    "oncurrentCount\0onCurrentAquisition\0"
    "closeProgressBar\0addNewValue\0wNumber\0"
    "scanIsInterrupted\0CurrentScanStatus\0"
    "status\0incomingData\0QPair<int,int>\0"
    "data\0scanIsFinished\0PositionChanged\0"
    "StepperMoving\0newStepperStatus\0"
    "mousePoint\0point\0connectStatus\0"
    "calibrateScan\0ScanData&\0newScan\0"
    "sortPoints\0getNearestPoints\0"
    "QPair<QPair<int,int>,QPair<int,int> >\0"
    "xVal\0calculateValue\0std::tuple<int,int,int>\0"
    "targetTuple\0firstPoint\0secondPoint\0"
    "calculateInvValue\0targetPoint\0"
    "serialConnectionUsed\0set_1\0set_2\0set_3\0"
    "set_4\0set_5\0set_6\0set_7\0set_8\0"
    "continue_this_scan\0on_loadGenericButton_clicked\0"
    "open\0openGeneric\0save\0saveGeneric\0"
    "saveGenericAllPlots\0on_dispXValue_toggled\0"
    "checked\0on_dispYValue_toggled\0"
    "on_dispZValue_toggled\0on_scanButton_clicked\0"
    "on_LastScan_clicked\0on_NextScan_clicked\0"
    "on_selectScanBox_currentIndexChanged\0"
    "index\0on_saveScan_clicked\0reload_data\0"
    "stepperStopped\0on_stepBackMono_clicked\0"
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
    "on_AddMovementCommentLog_clicked\0"
    "on_manual_StartMeasurement_clicked\0"
    "on_manual_confirmValue_clicked\0"
    "on_manual_centralWL_textEdited\0arg1\0"
    "on_manual_StartWL_textEdited\0"
    "on_manual_StopWL_textEdited\0"
    "on_manual_CentralWN_textEdited\0"
    "on_manual_StartWN_textEdited\0"
    "on_manual_StopWN_textEdited\0"
    "on_manual_currWaveNum_textChanged\0"
    "on_manual_CentralWN_textChanged\0"
    "on_connect_serial_clicked\0"
    "on_serial_transmitt_clicked\0"
    "on_lockin_1up_stateChanged\0"
    "on_lockin_2up_stateChanged\0"
    "on_lockin_3up_stateChanged\0"
    "on_lockin_4up_stateChanged\0"
    "on_lockin_5up_stateChanged\0"
    "on_lockin_6up_stateChanged\0"
    "on_lockin_7up_stateChanged\0"
    "on_lockin_8up_stateChanged\0"
    "on_lockin_1down_stateChanged\0"
    "on_lockin_2down_stateChanged\0"
    "on_lockin_3down_stateChanged\0"
    "on_lockin_4down_stateChanged\0"
    "on_lockin_5down_stateChanged\0"
    "on_lockin_6down_stateChanged\0"
    "on_lockin_7down_stateChanged\0"
    "on_lockin_8down_stateChanged\0"
    "on_lockin_baud_combo_currentIndexChanged\0"
    "on_lockin_stop_combo_currentIndexChanged\0"
    "on_lockin_Parity_currentIndexChanged\0"
    "on_lockin_EchoMode_currentIndexChanged\0"
    "on_UpdateCurrentPosition_clicked\0"
    "on_manual_CancelScan_clicked\0"
    "on_change_Xvals_currentIndexChanged\0"
    "on_lockin_SetTime_clicked\0"
    "on_setTimeConstant_currentIndexChanged\0"
    "on_lockin_getTime_clicked\0"
    "on_setInterpolationMethod_currentIndexChanged\0"
    "on_setInterpolationVariables_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     118,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  604,    2, 0x06 /* Public */,
       4,    2,  609,    2, 0x06 /* Public */,
       5,    2,  614,    2, 0x06 /* Public */,
       6,    2,  619,    2, 0x06 /* Public */,
       7,    2,  624,    2, 0x06 /* Public */,
       8,    2,  629,    2, 0x06 /* Public */,
       9,    0,  634,    2, 0x06 /* Public */,
      10,    0,  635,    2, 0x06 /* Public */,
      11,    0,  636,    2, 0x06 /* Public */,
      12,    0,  637,    2, 0x06 /* Public */,
      13,    0,  638,    2, 0x06 /* Public */,
      14,    5,  639,    2, 0x06 /* Public */,
      15,    1,  650,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  653,    2, 0x0a /* Public */,
      18,    1,  654,    2, 0x0a /* Public */,
      19,    1,  657,    2, 0x0a /* Public */,
      20,    0,  660,    2, 0x0a /* Public */,
      21,    2,  661,    2, 0x0a /* Public */,
      23,    0,  666,    2, 0x0a /* Public */,
      24,    1,  667,    2, 0x0a /* Public */,
      26,    1,  670,    2, 0x0a /* Public */,
      29,    0,  673,    2, 0x0a /* Public */,
      30,    0,  674,    2, 0x0a /* Public */,
      31,    0,  675,    2, 0x0a /* Public */,
      32,    1,  676,    2, 0x0a /* Public */,
      33,    1,  679,    2, 0x0a /* Public */,
      35,    1,  682,    2, 0x0a /* Public */,
      36,    1,  685,    2, 0x0a /* Public */,
      39,    0,  688,    2, 0x0a /* Public */,
      40,    1,  689,    2, 0x0a /* Public */,
      43,    3,  692,    2, 0x0a /* Public */,
      48,    3,  699,    2, 0x0a /* Public */,
      50,    1,  706,    2, 0x0a /* Public */,
      51,    1,  709,    2, 0x0a /* Public */,
      52,    1,  712,    2, 0x0a /* Public */,
      53,    1,  715,    2, 0x0a /* Public */,
      54,    1,  718,    2, 0x0a /* Public */,
      55,    1,  721,    2, 0x0a /* Public */,
      56,    1,  724,    2, 0x0a /* Public */,
      57,    1,  727,    2, 0x0a /* Public */,
      58,    1,  730,    2, 0x0a /* Public */,
      59,    1,  733,    2, 0x0a /* Public */,
      60,    0,  736,    2, 0x08 /* Private */,
      61,    0,  737,    2, 0x08 /* Private */,
      62,    0,  738,    2, 0x08 /* Private */,
      63,    0,  739,    2, 0x08 /* Private */,
      64,    0,  740,    2, 0x08 /* Private */,
      65,    0,  741,    2, 0x08 /* Private */,
      66,    1,  742,    2, 0x08 /* Private */,
      68,    1,  745,    2, 0x08 /* Private */,
      69,    1,  748,    2, 0x08 /* Private */,
      70,    0,  751,    2, 0x08 /* Private */,
      71,    0,  752,    2, 0x08 /* Private */,
      72,    0,  753,    2, 0x08 /* Private */,
      73,    1,  754,    2, 0x08 /* Private */,
      75,    0,  757,    2, 0x08 /* Private */,
      76,    0,  758,    2, 0x08 /* Private */,
      77,    0,  759,    2, 0x08 /* Private */,
      78,    0,  760,    2, 0x08 /* Private */,
      79,    0,  761,    2, 0x08 /* Private */,
      80,    0,  762,    2, 0x08 /* Private */,
      81,    0,  763,    2, 0x08 /* Private */,
      82,    0,  764,    2, 0x08 /* Private */,
      83,    0,  765,    2, 0x08 /* Private */,
      84,    0,  766,    2, 0x08 /* Private */,
      85,    0,  767,    2, 0x08 /* Private */,
      86,    1,  768,    2, 0x08 /* Private */,
      87,    0,  771,    2, 0x08 /* Private */,
      88,    0,  772,    2, 0x08 /* Private */,
      89,    0,  773,    2, 0x08 /* Private */,
      90,    0,  774,    2, 0x08 /* Private */,
      91,    0,  775,    2, 0x08 /* Private */,
      92,    0,  776,    2, 0x08 /* Private */,
      93,    0,  777,    2, 0x08 /* Private */,
      94,    0,  778,    2, 0x08 /* Private */,
      95,    0,  779,    2, 0x08 /* Private */,
      96,    0,  780,    2, 0x08 /* Private */,
      97,    0,  781,    2, 0x08 /* Private */,
      98,    0,  782,    2, 0x08 /* Private */,
      99,    0,  783,    2, 0x08 /* Private */,
     100,    1,  784,    2, 0x08 /* Private */,
     102,    1,  787,    2, 0x08 /* Private */,
     103,    1,  790,    2, 0x08 /* Private */,
     104,    1,  793,    2, 0x08 /* Private */,
     105,    1,  796,    2, 0x08 /* Private */,
     106,    1,  799,    2, 0x08 /* Private */,
     107,    1,  802,    2, 0x08 /* Private */,
     108,    1,  805,    2, 0x08 /* Private */,
     109,    0,  808,    2, 0x08 /* Private */,
     110,    0,  809,    2, 0x08 /* Private */,
     111,    1,  810,    2, 0x08 /* Private */,
     112,    1,  813,    2, 0x08 /* Private */,
     113,    1,  816,    2, 0x08 /* Private */,
     114,    1,  819,    2, 0x08 /* Private */,
     115,    1,  822,    2, 0x08 /* Private */,
     116,    1,  825,    2, 0x08 /* Private */,
     117,    1,  828,    2, 0x08 /* Private */,
     118,    1,  831,    2, 0x08 /* Private */,
     119,    1,  834,    2, 0x08 /* Private */,
     120,    1,  837,    2, 0x08 /* Private */,
     121,    1,  840,    2, 0x08 /* Private */,
     122,    1,  843,    2, 0x08 /* Private */,
     123,    1,  846,    2, 0x08 /* Private */,
     124,    1,  849,    2, 0x08 /* Private */,
     125,    1,  852,    2, 0x08 /* Private */,
     126,    1,  855,    2, 0x08 /* Private */,
     127,    1,  858,    2, 0x08 /* Private */,
     128,    1,  861,    2, 0x08 /* Private */,
     129,    1,  864,    2, 0x08 /* Private */,
     130,    1,  867,    2, 0x08 /* Private */,
     131,    0,  870,    2, 0x08 /* Private */,
     132,    0,  871,    2, 0x08 /* Private */,
     133,    1,  872,    2, 0x08 /* Private */,
     134,    0,  875,    2, 0x08 /* Private */,
     135,    1,  876,    2, 0x08 /* Private */,
     136,    0,  879,    2, 0x08 /* Private */,
     137,    1,  880,    2, 0x08 /* Private */,
     138,    1,  883,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Double,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   22,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QPointF,   34,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void,
    0x80000000 | 41, QMetaType::Int,   42,
    QMetaType::Int, 0x80000000 | 44, 0x80000000 | 27, 0x80000000 | 27,   45,   46,   47,
    QMetaType::Int, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27,   49,   46,   47,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   67,
    QMetaType::Void, QMetaType::Bool,   67,
    QMetaType::Void, QMetaType::Bool,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   74,
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
    QMetaType::Void, QMetaType::Int,   74,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  101,
    QMetaType::Void, QMetaType::QString,  101,

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
        case 12: _t->continue_scan((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->calibrate(); break;
        case 14: _t->oncurrentCount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->onCurrentAquisition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->closeProgressBar(); break;
        case 17: _t->addNewValue((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 18: _t->scanIsInterrupted(); break;
        case 19: _t->CurrentScanStatus((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 20: _t->incomingData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 21: _t->scanIsFinished(); break;
        case 22: _t->PositionChanged(); break;
        case 23: _t->StepperMoving(); break;
        case 24: _t->newStepperStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->mousePoint((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 26: _t->connectStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->calibrateScan((*reinterpret_cast< ScanData(*)>(_a[1]))); break;
        case 28: _t->sortPoints(); break;
        case 29: { QPair<QPair<int,int>,QPair<int,int> > _r = _t->getNearestPoints((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPair<QPair<int,int>,QPair<int,int> >*>(_a[0]) = _r; }  break;
        case 30: { int _r = _t->calculateValue((*reinterpret_cast< std::tuple<int,int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 31: { int _r = _t->calculateInvValue((*reinterpret_cast< QPair<int,int>(*)>(_a[1])),(*reinterpret_cast< QPair<int,int>(*)>(_a[2])),(*reinterpret_cast< QPair<int,int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 32: _t->serialConnectionUsed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->set_1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->set_2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->set_3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->set_4((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->set_5((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->set_6((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->set_7((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->set_8((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->continue_this_scan((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 42: _t->on_loadGenericButton_clicked(); break;
        case 43: _t->open(); break;
        case 44: _t->openGeneric(); break;
        case 45: _t->save(); break;
        case 46: _t->saveGeneric(); break;
        case 47: _t->saveGenericAllPlots(); break;
        case 48: _t->on_dispXValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_dispYValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->on_dispZValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_scanButton_clicked(); break;
        case 52: _t->on_LastScan_clicked(); break;
        case 53: _t->on_NextScan_clicked(); break;
        case 54: _t->on_selectScanBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->on_saveScan_clicked(); break;
        case 56: _t->reload_data(); break;
        case 57: _t->stepperStopped(); break;
        case 58: _t->on_stepBackMono_clicked(); break;
        case 59: _t->on_stepForwardMono_clicked(); break;
        case 60: _t->on_mvButton_2_clicked(); break;
        case 61: _t->on_logButton_clicked(); break;
        case 62: _t->createLogData(); break;
        case 63: _t->loadConfig(); break;
        case 64: _t->writeConfig(); break;
        case 65: _t->on_execButton_2_clicked(); break;
        case 66: _t->on_gridTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->on_newScan_clicked(); break;
        case 68: _t->on_stopScan_clicked(); break;
        case 69: _t->on_saveSettingsButton_clicked(); break;
        case 70: _t->on_loadSettingsButton_clicked(); break;
        case 71: _t->on_centerMono_clicked(); break;
        case 72: _t->on_connect_clicked(); break;
        case 73: _t->on_CalibButton_clicked(); break;
        case 74: _t->on_CalibFinished_clicked(); break;
        case 75: _t->on_CalibConfirm_clicked(); break;
        case 76: _t->on_AddMovementLog_clicked(); break;
        case 77: _t->on_AddMovementCommentLog_clicked(); break;
        case 78: _t->on_manual_StartMeasurement_clicked(); break;
        case 79: _t->on_manual_confirmValue_clicked(); break;
        case 80: _t->on_manual_centralWL_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 81: _t->on_manual_StartWL_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 82: _t->on_manual_StopWL_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 83: _t->on_manual_CentralWN_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 84: _t->on_manual_StartWN_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 85: _t->on_manual_StopWN_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 86: _t->on_manual_currWaveNum_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 87: _t->on_manual_CentralWN_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 88: _t->on_connect_serial_clicked(); break;
        case 89: _t->on_serial_transmitt_clicked(); break;
        case 90: _t->on_lockin_1up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 91: _t->on_lockin_2up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 92: _t->on_lockin_3up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 93: _t->on_lockin_4up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 94: _t->on_lockin_5up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: _t->on_lockin_6up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 96: _t->on_lockin_7up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 97: _t->on_lockin_8up_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 98: _t->on_lockin_1down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->on_lockin_2down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->on_lockin_3down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 101: _t->on_lockin_4down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: _t->on_lockin_5down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: _t->on_lockin_6down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 104: _t->on_lockin_7down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 105: _t->on_lockin_8down_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 106: _t->on_lockin_baud_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 107: _t->on_lockin_stop_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 108: _t->on_lockin_Parity_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 109: _t->on_lockin_EchoMode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 110: _t->on_UpdateCurrentPosition_clicked(); break;
        case 111: _t->on_manual_CancelScan_clicked(); break;
        case 112: _t->on_change_Xvals_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 113: _t->on_lockin_SetTime_clicked(); break;
        case 114: _t->on_setTimeConstant_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 115: _t->on_lockin_getTime_clicked(); break;
        case 116: _t->on_setInterpolationMethod_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 117: _t->on_setInterpolationVariables_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        {
            typedef void (MainWindow::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::continue_scan)) {
                *result = 12;
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
        if (_id < 118)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 118;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 118)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 118;
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

// SIGNAL 12
void MainWindow::continue_scan(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
