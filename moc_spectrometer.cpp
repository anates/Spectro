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
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Spectrometer_t {
    QByteArrayData data[34];
    char stringdata[368];
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
QT_MOC_LITERAL(19, 192, 16), // "switchingSucceed"
QT_MOC_LITERAL(20, 209, 3), // "pol"
QT_MOC_LITERAL(21, 213, 16), // "switchingSuccess"
QT_MOC_LITERAL(22, 230, 12), // "stepperMoved"
QT_MOC_LITERAL(23, 243, 13), // "currentCounts"
QT_MOC_LITERAL(24, 257, 11), // "currentData"
QT_MOC_LITERAL(25, 269, 14), // "updatePosition"
QT_MOC_LITERAL(26, 284, 19), // "currentScanPosition"
QT_MOC_LITERAL(27, 304, 12), // "scanFinished"
QT_MOC_LITERAL(28, 317, 9), // "switchPol"
QT_MOC_LITERAL(29, 327, 12), // "moveToTarget"
QT_MOC_LITERAL(30, 340, 7), // "runScan"
QT_MOC_LITERAL(31, 348, 5), // "start"
QT_MOC_LITERAL(32, 354, 4), // "stop"
QT_MOC_LITERAL(33, 359, 8) // "accuracy"

    },
    "Spectrometer\0switchPolarizer\0\0Polarizer\0"
    "moveStepperToTarget\0scanNow\0interruptScan\0"
    "Data\0QPair<int,int>\0data\0DPCCounts\0"
    "counts\0scanFinish\0ScanPos\0position\0"
    "currentPosition\0steps\0dir\0stepperMoving\0"
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
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    2,  122,    2, 0x06 /* Public */,
       5,    3,  127,    2, 0x06 /* Public */,
       6,    0,  134,    2, 0x06 /* Public */,
       7,    1,  135,    2, 0x06 /* Public */,
      10,    1,  138,    2, 0x06 /* Public */,
      12,    0,  141,    2, 0x06 /* Public */,
      13,    1,  142,    2, 0x06 /* Public */,
      15,    2,  145,    2, 0x06 /* Public */,
      18,    0,  150,    2, 0x06 /* Public */,
      19,    1,  151,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  154,    2, 0x08 /* Private */,
      22,    2,  157,    2, 0x08 /* Private */,
      23,    1,  162,    2, 0x08 /* Private */,
      24,    1,  165,    2, 0x08 /* Private */,
      25,    2,  168,    2, 0x08 /* Private */,
      26,    1,  173,    2, 0x08 /* Private */,
      27,    0,  176,    2, 0x08 /* Private */,
      28,    1,  177,    2, 0x0a /* Public */,
      29,    2,  180,    2, 0x0a /* Public */,
      30,    3,  185,    2, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 3,   20,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::QReal,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,

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
        case 10: _t->switchingSucceed((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 11: _t->switchingSuccess((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 12: _t->stepperMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 15: _t->updatePosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->currentScanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 17: _t->scanFinished(); break;
        case 18: _t->switchPol((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 19: _t->moveToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
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
        case 10:
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
        case 18:
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
            typedef void (Spectrometer::*_t)(Polarizer );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer::switchingSucceed)) {
                *result = 10;
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
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
void Spectrometer::switchingSucceed(Polarizer _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
struct qt_meta_stringdata_Spectrometer_Control_t {
    QByteArrayData data[34];
    char stringdata[388];
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
QT_MOC_LITERAL(14, 130, 11), // "currentData"
QT_MOC_LITERAL(15, 142, 14), // "QPair<int,int>"
QT_MOC_LITERAL(16, 157, 4), // "data"
QT_MOC_LITERAL(17, 162, 12), // "scanFinished"
QT_MOC_LITERAL(18, 175, 19), // "currentScanPosition"
QT_MOC_LITERAL(19, 195, 8), // "position"
QT_MOC_LITERAL(20, 204, 18), // "currentCounterData"
QT_MOC_LITERAL(21, 223, 6), // "counts"
QT_MOC_LITERAL(22, 230, 15), // "positionChanged"
QT_MOC_LITERAL(23, 246, 13), // "stepperMoving"
QT_MOC_LITERAL(24, 260, 9), // "TX_status"
QT_MOC_LITERAL(25, 270, 6), // "status"
QT_MOC_LITERAL(26, 277, 8), // "scanData"
QT_MOC_LITERAL(27, 286, 13), // "currentCounts"
QT_MOC_LITERAL(28, 300, 21), // "updateCurrentPosition"
QT_MOC_LITERAL(29, 322, 15), // "stepperIsMoving"
QT_MOC_LITERAL(30, 338, 16), // "updatePolarizers"
QT_MOC_LITERAL(31, 355, 10), // "scanFinish"
QT_MOC_LITERAL(32, 366, 12), // "scanPosition"
QT_MOC_LITERAL(33, 379, 8) // "TXStatus"

    },
    "Spectrometer_Control\0switchPolarizer\0"
    "\0Polarizer\0pol\0moveStepperToTarget\0"
    "steps\0dir\0runScan\0start\0stop\0accuracy\0"
    "initMonoPos\0MonoPos\0currentData\0"
    "QPair<int,int>\0data\0scanFinished\0"
    "currentScanPosition\0position\0"
    "currentCounterData\0counts\0positionChanged\0"
    "stepperMoving\0TX_status\0status\0scanData\0"
    "currentCounts\0updateCurrentPosition\0"
    "stepperIsMoving\0updatePolarizers\0"
    "scanFinish\0scanPosition\0TXStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spectrometer_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       5,    2,  112,    2, 0x06 /* Public */,
       8,    3,  117,    2, 0x06 /* Public */,
      12,    1,  124,    2, 0x06 /* Public */,
      14,    1,  127,    2, 0x06 /* Public */,
      17,    0,  130,    2, 0x06 /* Public */,
      18,    1,  131,    2, 0x06 /* Public */,
      20,    1,  134,    2, 0x06 /* Public */,
      22,    0,  137,    2, 0x06 /* Public */,
      23,    0,  138,    2, 0x06 /* Public */,
      24,    1,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    1,  142,    2, 0x0a /* Public */,
      27,    1,  145,    2, 0x0a /* Public */,
      28,    2,  148,    2, 0x0a /* Public */,
      29,    0,  153,    2, 0x0a /* Public */,
      30,    1,  154,    2, 0x0a /* Public */,
      31,    0,  157,    2, 0x0a /* Public */,
      32,    1,  158,    2, 0x0a /* Public */,
      33,    1,  161,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   19,
    QMetaType::Void, QMetaType::Bool,   25,

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
        case 4: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 5: _t->scanFinished(); break;
        case 6: _t->currentScanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->currentCounterData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->positionChanged(); break;
        case 9: _t->stepperMoving(); break;
        case 10: _t->TX_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->scanData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 12: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateCurrentPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->stepperIsMoving(); break;
        case 15: _t->updatePolarizers((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 16: _t->scanFinish(); break;
        case 17: _t->scanPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 18: _t->TXStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
        case 15:
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
            typedef void (Spectrometer_Control::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentData)) {
                *result = 4;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::scanFinished)) {
                *result = 5;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentScanPosition)) {
                *result = 6;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::currentCounterData)) {
                *result = 7;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::positionChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::stepperMoving)) {
                *result = 9;
            }
        }
        {
            typedef void (Spectrometer_Control::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrometer_Control::TX_status)) {
                *result = 10;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
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
void Spectrometer_Control::currentData(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Spectrometer_Control::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Spectrometer_Control::currentScanPosition(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Spectrometer_Control::currentCounterData(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Spectrometer_Control::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void Spectrometer_Control::stepperMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void Spectrometer_Control::TX_status(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
