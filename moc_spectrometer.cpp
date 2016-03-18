/****************************************************************************
** Meta object code from reading C++ file 'spectrometer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spectrometer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Spectrometer_t {
    QByteArrayData data[36];
    char stringdata[396];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spectrometer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spectrometer_t qt_meta_stringdata_Spectrometer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Spectrometer"
QT_MOC_LITERAL(1, 13, 15), // "switchPolarizer"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "Polarizer"
QT_MOC_LITERAL(4, 40, 19), // "moveStepperToTarget"
QT_MOC_LITERAL(5, 60, 7), // "scanNow"
QT_MOC_LITERAL(6, 68, 13), // "interruptScan"
QT_MOC_LITERAL(7, 82, 4), // "Data"
QT_MOC_LITERAL(8, 87, 14), // "QPair<int,int>"
QT_MOC_LITERAL(9, 102, 4), // "data"
QT_MOC_LITERAL(10, 107, 9), // "DPCCounts"
QT_MOC_LITERAL(11, 117, 6), // "counts"
QT_MOC_LITERAL(12, 124, 10), // "scanFinish"
QT_MOC_LITERAL(13, 135, 7), // "ScanPos"
QT_MOC_LITERAL(14, 143, 8), // "position"
QT_MOC_LITERAL(15, 152, 15), // "currentPosition"
QT_MOC_LITERAL(16, 168, 5), // "steps"
QT_MOC_LITERAL(17, 174, 3), // "dir"
QT_MOC_LITERAL(18, 178, 13), // "stepperMoving"
QT_MOC_LITERAL(19, 192, 20), // "currentStepperStatus"
QT_MOC_LITERAL(20, 213, 6), // "status"
QT_MOC_LITERAL(21, 220, 16), // "switchingSucceed"
QT_MOC_LITERAL(22, 237, 3), // "pol"
QT_MOC_LITERAL(23, 241, 16), // "switchingSuccess"
QT_MOC_LITERAL(24, 258, 12), // "stepperMoved"
QT_MOC_LITERAL(25, 271, 13), // "currentCounts"
QT_MOC_LITERAL(26, 285, 11), // "currentData"
QT_MOC_LITERAL(27, 297, 14), // "updatePosition"
QT_MOC_LITERAL(28, 312, 19), // "currentScanPosition"
QT_MOC_LITERAL(29, 332, 12), // "scanFinished"
QT_MOC_LITERAL(30, 345, 9), // "switchPol"
QT_MOC_LITERAL(31, 355, 12), // "moveToTarget"
QT_MOC_LITERAL(32, 368, 7), // "runScan"
QT_MOC_LITERAL(33, 376, 5), // "start"
QT_MOC_LITERAL(34, 382, 4), // "stop"
QT_MOC_LITERAL(35, 387, 8) // "accuracy"

    },
    "Spectrometer\0switchPolarizer\0\0Polarizer\0"
    "moveStepperToTarget\0scanNow\0interruptScan\0"
    "Data\0QPair<int,int>\0data\0DPCCounts\0"
    "counts\0scanFinish\0ScanPos\0position\0"
    "currentPosition\0steps\0dir\0stepperMoving\0"
    "currentStepperStatus\0status\0"
    "switchingSucceed\0pol\0switchingSuccess\0"
    "stepperMoved\0currentCounts\0currentData\0"
    "updatePosition\0currentScanPosition\0"
    "scanFinished\0switchPol\0moveToTarget\0"
    "runScan\0start\0stop\0accuracy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spectrometer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    2,  127,    2, 0x06 /* Public */,
       5,    3,  132,    2, 0x06 /* Public */,
       6,    0,  139,    2, 0x06 /* Public */,
       7,    1,  140,    2, 0x06 /* Public */,
      10,    1,  143,    2, 0x06 /* Public */,
      12,    0,  146,    2, 0x06 /* Public */,
      13,    1,  147,    2, 0x06 /* Public */,
      15,    2,  150,    2, 0x06 /* Public */,
      18,    0,  155,    2, 0x06 /* Public */,
      19,    1,  156,    2, 0x06 /* Public */,
      21,    1,  159,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  162,    2, 0x08 /* Private */,
      24,    2,  165,    2, 0x08 /* Private */,
      25,    1,  170,    2, 0x08 /* Private */,
      26,    1,  173,    2, 0x08 /* Private */,
      27,    2,  176,    2, 0x08 /* Private */,
      28,    1,  181,    2, 0x08 /* Private */,
      29,    0,  184,    2, 0x08 /* Private */,
      30,    1,  185,    2, 0x0a /* Public */,
      31,    2,  188,    2, 0x0a /* Public */,
      32,    3,  193,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 3,   22,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::QReal,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   33,   34,   35,

       0        // eod
};

void Spectrometer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spectrometer *_t = static_cast<Spectrometer *>(_o);
        switch (_id) {
        case 0: _t->switchPolarizer((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 1: _t->moveStepperToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->scanNow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->interruptScan(); break;
        case 4: _t->Data((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 5: _t->DPCCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->scanFinish(); break;
        case 7: _t->ScanPos((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 8: _t->currentPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->stepperMoving(); break;
        case 10: _t->currentStepperStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->switchingSucceed((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 12: _t->switchingSuccess((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 13: _t->stepperMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 16: _t->updatePosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 17: _t->currentScanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 18: _t->scanFinished(); break;
        case 19: _t->switchPol((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 20: _t->moveToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
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
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        case 19:
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
            typedef void (Spectrometer::*_t)(Polarizer );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::switchPolarizer)) {
                *result = 0;
            }
        }
        {
            typedef void (Spectrometer::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::moveStepperToTarget)) {
                *result = 1;
            }
        }
        {
            typedef void (Spectrometer::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::scanNow)) {
                *result = 2;
            }
        }
        {
            typedef void (Spectrometer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::interruptScan)) {
                *result = 3;
            }
        }
        {
            typedef void (Spectrometer::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::Data)) {
                *result = 4;
            }
        }
        {
            typedef void (Spectrometer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::DPCCounts)) {
                *result = 5;
            }
        }
        {
            typedef void (Spectrometer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::scanFinish)) {
                *result = 6;
            }
        }
        {
            typedef void (Spectrometer::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::ScanPos)) {
                *result = 7;
            }
        }
        {
            typedef void (Spectrometer::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::currentPosition)) {
                *result = 8;
            }
        }
        {
            typedef void (Spectrometer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::stepperMoving)) {
                *result = 9;
            }
        }
        {
            typedef void (Spectrometer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::currentStepperStatus)) {
                *result = 10;
            }
        }
        {
            typedef void (Spectrometer::*_t)(Polarizer );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::switchingSucceed)) {
                *result = 11;
            }
        }
    }
}

const QMetaObject Spectrometer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Spectrometer.data,
      qt_meta_data_Spectrometer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Spectrometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spectrometer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Spectrometer.stringdata))
        return static_cast<void*>(const_cast< Spectrometer*>(this));
    return QObject::qt_metacast(_clname);
}

int Spectrometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Spectrometer::switchPolarizer(Polarizer _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Spectrometer::moveStepperToTarget(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Spectrometer::scanNow(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Spectrometer::interruptScan()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Spectrometer::Data(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Spectrometer::DPCCounts(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Spectrometer::scanFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Spectrometer::ScanPos(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Spectrometer::currentPosition(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Spectrometer::stepperMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void Spectrometer::currentStepperStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Spectrometer::switchingSucceed(Polarizer _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
struct qt_meta_stringdata_Spectrometer_Control_t {
    QByteArrayData data[51];
    char stringdata[641];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spectrometer_Control_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spectrometer_Control_t qt_meta_stringdata_Spectrometer_Control = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Spectrometer_Control"
QT_MOC_LITERAL(1, 21, 15), // "switchPolarizer"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "Polarizer"
QT_MOC_LITERAL(4, 48, 3), // "pol"
QT_MOC_LITERAL(5, 52, 19), // "moveStepperToTarget"
QT_MOC_LITERAL(6, 72, 5), // "steps"
QT_MOC_LITERAL(7, 78, 3), // "dir"
QT_MOC_LITERAL(8, 82, 7), // "runScan"
QT_MOC_LITERAL(9, 90, 5), // "start"
QT_MOC_LITERAL(10, 96, 4), // "stop"
QT_MOC_LITERAL(11, 101, 8), // "accuracy"
QT_MOC_LITERAL(12, 110, 11), // "initMonoPos"
QT_MOC_LITERAL(13, 122, 7), // "MonoPos"
QT_MOC_LITERAL(14, 130, 20), // "shutSpectrometerDown"
QT_MOC_LITERAL(15, 151, 11), // "currentData"
QT_MOC_LITERAL(16, 163, 14), // "QPair<int,int>"
QT_MOC_LITERAL(17, 178, 4), // "data"
QT_MOC_LITERAL(18, 183, 12), // "scanFinished"
QT_MOC_LITERAL(19, 196, 16), // "stepperIsStopped"
QT_MOC_LITERAL(20, 213, 19), // "currentScanPosition"
QT_MOC_LITERAL(21, 233, 8), // "position"
QT_MOC_LITERAL(22, 242, 18), // "currentCounterData"
QT_MOC_LITERAL(23, 261, 6), // "counts"
QT_MOC_LITERAL(24, 268, 21), // "currentAquisitionData"
QT_MOC_LITERAL(25, 290, 13), // "currentStatus"
QT_MOC_LITERAL(26, 304, 15), // "positionChanged"
QT_MOC_LITERAL(27, 320, 13), // "stepperMoving"
QT_MOC_LITERAL(28, 334, 9), // "TX_status"
QT_MOC_LITERAL(29, 344, 6), // "status"
QT_MOC_LITERAL(30, 351, 17), // "SerialIsConnected"
QT_MOC_LITERAL(31, 369, 10), // "SerialData"
QT_MOC_LITERAL(32, 380, 16), // "QVector<QString>"
QT_MOC_LITERAL(33, 397, 8), // "scanData"
QT_MOC_LITERAL(34, 406, 13), // "currentCounts"
QT_MOC_LITERAL(35, 420, 21), // "updateCurrentPosition"
QT_MOC_LITERAL(36, 442, 15), // "stepperIsMoving"
QT_MOC_LITERAL(37, 458, 14), // "stepperStopped"
QT_MOC_LITERAL(38, 473, 20), // "currentStepperStatus"
QT_MOC_LITERAL(39, 494, 16), // "updatePolarizers"
QT_MOC_LITERAL(40, 511, 10), // "scanFinish"
QT_MOC_LITERAL(41, 522, 12), // "scanPosition"
QT_MOC_LITERAL(42, 535, 8), // "TXStatus"
QT_MOC_LITERAL(43, 544, 8), // "response"
QT_MOC_LITERAL(44, 553, 16), // "get_analog_value"
QT_MOC_LITERAL(45, 570, 12), // "lockin_value"
QT_MOC_LITERAL(46, 583, 5), // "value"
QT_MOC_LITERAL(47, 589, 10), // "firstValue"
QT_MOC_LITERAL(48, 600, 11), // "secondValue"
QT_MOC_LITERAL(49, 612, 23), // "set_serial_waiting_time"
QT_MOC_LITERAL(50, 636, 4) // "time"

    },
    "Spectrometer_Control\0switchPolarizer\0"
    "\0Polarizer\0pol\0moveStepperToTarget\0"
    "steps\0dir\0runScan\0start\0stop\0accuracy\0"
    "initMonoPos\0MonoPos\0shutSpectrometerDown\0"
    "currentData\0QPair<int,int>\0data\0"
    "scanFinished\0stepperIsStopped\0"
    "currentScanPosition\0position\0"
    "currentCounterData\0counts\0"
    "currentAquisitionData\0currentStatus\0"
    "positionChanged\0stepperMoving\0TX_status\0"
    "status\0SerialIsConnected\0SerialData\0"
    "QVector<QString>\0scanData\0currentCounts\0"
    "updateCurrentPosition\0stepperIsMoving\0"
    "stepperStopped\0currentStepperStatus\0"
    "updatePolarizers\0scanFinish\0scanPosition\0"
    "TXStatus\0response\0get_analog_value\0"
    "lockin_value\0value\0firstValue\0secondValue\0"
    "set_serial_waiting_time\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spectrometer_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,
       5,    2,  172,    2, 0x06 /* Public */,
       8,    3,  177,    2, 0x06 /* Public */,
      12,    1,  184,    2, 0x06 /* Public */,
      14,    0,  187,    2, 0x06 /* Public */,
      15,    1,  188,    2, 0x06 /* Public */,
      18,    0,  191,    2, 0x06 /* Public */,
      19,    0,  192,    2, 0x06 /* Public */,
      20,    1,  193,    2, 0x06 /* Public */,
      22,    1,  196,    2, 0x06 /* Public */,
      24,    1,  199,    2, 0x06 /* Public */,
      25,    1,  202,    2, 0x06 /* Public */,
      26,    0,  205,    2, 0x06 /* Public */,
      27,    0,  206,    2, 0x06 /* Public */,
      28,    1,  207,    2, 0x06 /* Public */,
      30,    1,  210,    2, 0x06 /* Public */,
      31,    1,  213,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      33,    1,  216,    2, 0x0a /* Public */,
      34,    1,  219,    2, 0x0a /* Public */,
      35,    2,  222,    2, 0x0a /* Public */,
      36,    0,  227,    2, 0x0a /* Public */,
      37,    0,  228,    2, 0x0a /* Public */,
      38,    1,  229,    2, 0x0a /* Public */,
      39,    1,  232,    2, 0x0a /* Public */,
      40,    0,  235,    2, 0x0a /* Public */,
      41,    1,  236,    2, 0x0a /* Public */,
      42,    1,  239,    2, 0x0a /* Public */,
      43,    1,  242,    2, 0x0a /* Public */,
      44,    0,  245,    2, 0x0a /* Public */,
      45,    3,  246,    2, 0x0a /* Public */,
      49,    1,  253,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, 0x80000000 | 32,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   21,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, 0x80000000 | 32,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   46,   47,   48,
    QMetaType::Void, QMetaType::Double,   50,

       0        // eod
};

void Spectrometer_Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spectrometer_Control *_t = static_cast<Spectrometer_Control *>(_o);
        switch (_id) {
        case 0: _t->switchPolarizer((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 1: _t->moveStepperToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->initMonoPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->shutSpectrometerDown(); break;
        case 5: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 6: _t->scanFinished(); break;
        case 7: _t->stepperIsStopped(); break;
        case 8: _t->currentScanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->currentCounterData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->currentAquisitionData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->currentStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->positionChanged(); break;
        case 13: _t->stepperMoving(); break;
        case 14: _t->TX_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->SerialIsConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->SerialData((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 17: _t->scanData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 18: _t->currentCounts((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->updateCurrentPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->stepperIsMoving(); break;
        case 21: _t->stepperStopped(); break;
        case 22: _t->currentStepperStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->updatePolarizers((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 24: _t->scanFinish(); break;
        case 25: _t->scanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 26: _t->TXStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->response((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 28: _t->get_analog_value(); break;
        case 29: _t->lockin_value((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 30: _t->set_serial_waiting_time((*reinterpret_cast< double(*)>(_a[1]))); break;
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
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Polarizer >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Spectrometer_Control::*_t)(Polarizer );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::switchPolarizer)) {
                *result = 0;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::moveStepperToTarget)) {
                *result = 1;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::runScan)) {
                *result = 2;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::initMonoPos)) {
                *result = 3;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::shutSpectrometerDown)) {
                *result = 4;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentData)) {
                *result = 5;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::scanFinished)) {
                *result = 6;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::stepperIsStopped)) {
                *result = 7;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentScanPosition)) {
                *result = 8;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentCounterData)) {
                *result = 9;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentAquisitionData)) {
                *result = 10;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentStatus)) {
                *result = 11;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::positionChanged)) {
                *result = 12;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::stepperMoving)) {
                *result = 13;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::TX_status)) {
                *result = 14;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::SerialIsConnected)) {
                *result = 15;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::SerialData)) {
                *result = 16;
            }
        }
    }
}

const QMetaObject Spectrometer_Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Spectrometer_Control.data,
      qt_meta_data_Spectrometer_Control,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Spectrometer_Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spectrometer_Control::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Spectrometer_Control.stringdata))
        return static_cast<void*>(const_cast< Spectrometer_Control*>(this));
    return QObject::qt_metacast(_clname);
}

int Spectrometer_Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void Spectrometer_Control::switchPolarizer(Polarizer _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Spectrometer_Control::moveStepperToTarget(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Spectrometer_Control::runScan(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Spectrometer_Control::initMonoPos(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Spectrometer_Control::shutSpectrometerDown()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Spectrometer_Control::currentData(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Spectrometer_Control::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Spectrometer_Control::stepperIsStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void Spectrometer_Control::currentScanPosition(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Spectrometer_Control::currentCounterData(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Spectrometer_Control::currentAquisitionData(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Spectrometer_Control::currentStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Spectrometer_Control::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void Spectrometer_Control::stepperMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void Spectrometer_Control::TX_status(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Spectrometer_Control::SerialIsConnected(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Spectrometer_Control::SerialData(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE
