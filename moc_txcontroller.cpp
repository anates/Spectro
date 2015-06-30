/****************************************************************************
** Meta object code from reading C++ file 'txcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "txcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'txcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TXcontroller_t {
    QByteArrayData data[37];
    char stringdata[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TXcontroller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TXcontroller_t qt_meta_stringdata_TXcontroller = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TXcontroller"
QT_MOC_LITERAL(1, 13, 11), // "connectMain"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "connectFile"
QT_MOC_LITERAL(4, 38, 6), // "TXdata"
QT_MOC_LITERAL(5, 45, 39), // "QPair<QString,QPair<QString,Q..."
QT_MOC_LITERAL(6, 85, 4), // "data"
QT_MOC_LITERAL(7, 90, 4), // "Data"
QT_MOC_LITERAL(8, 95, 14), // "QPair<int,int>"
QT_MOC_LITERAL(9, 110, 9), // "DPCCounts"
QT_MOC_LITERAL(10, 120, 6), // "counts"
QT_MOC_LITERAL(11, 127, 10), // "scanFinish"
QT_MOC_LITERAL(12, 138, 7), // "ScanPos"
QT_MOC_LITERAL(13, 146, 8), // "position"
QT_MOC_LITERAL(14, 155, 14), // "MainClientStat"
QT_MOC_LITERAL(15, 170, 14), // "DataClientStat"
QT_MOC_LITERAL(16, 185, 15), // "currentPosition"
QT_MOC_LITERAL(17, 201, 5), // "steps"
QT_MOC_LITERAL(18, 207, 3), // "dir"
QT_MOC_LITERAL(19, 211, 13), // "stepperMoving"
QT_MOC_LITERAL(20, 225, 16), // "switchingSucceed"
QT_MOC_LITERAL(21, 242, 9), // "Polarizer"
QT_MOC_LITERAL(22, 252, 3), // "pol"
QT_MOC_LITERAL(23, 256, 13), // "gotConnection"
QT_MOC_LITERAL(24, 270, 10), // "gotNewFile"
QT_MOC_LITERAL(25, 281, 11), // "gotDataMain"
QT_MOC_LITERAL(26, 293, 12), // "ClientStatus"
QT_MOC_LITERAL(27, 306, 6), // "status"
QT_MOC_LITERAL(28, 313, 11), // "gotDataFile"
QT_MOC_LITERAL(29, 325, 16), // "DataClientStatus"
QT_MOC_LITERAL(30, 342, 16), // "gotNewConnection"
QT_MOC_LITERAL(31, 359, 15), // "SwitchPolarizer"
QT_MOC_LITERAL(32, 375, 12), // "moveToTarget"
QT_MOC_LITERAL(33, 388, 7), // "runScan"
QT_MOC_LITERAL(34, 396, 5), // "start"
QT_MOC_LITERAL(35, 402, 4), // "stop"
QT_MOC_LITERAL(36, 407, 8) // "accuracy"

    },
    "TXcontroller\0connectMain\0\0connectFile\0"
    "TXdata\0QPair<QString,QPair<QString,QVariant> >\0"
    "data\0Data\0QPair<int,int>\0DPCCounts\0"
    "counts\0scanFinish\0ScanPos\0position\0"
    "MainClientStat\0DataClientStat\0"
    "currentPosition\0steps\0dir\0stepperMoving\0"
    "switchingSucceed\0Polarizer\0pol\0"
    "gotConnection\0gotNewFile\0gotDataMain\0"
    "ClientStatus\0status\0gotDataFile\0"
    "DataClientStatus\0gotNewConnection\0"
    "SwitchPolarizer\0moveToTarget\0runScan\0"
    "start\0stop\0accuracy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TXcontroller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    0,  125,    2, 0x06 /* Public */,
       4,    1,  126,    2, 0x06 /* Public */,
       7,    1,  129,    2, 0x06 /* Public */,
       9,    1,  132,    2, 0x06 /* Public */,
      11,    0,  135,    2, 0x06 /* Public */,
      12,    1,  136,    2, 0x06 /* Public */,
      14,    1,  139,    2, 0x06 /* Public */,
      15,    1,  142,    2, 0x06 /* Public */,
      16,    2,  145,    2, 0x06 /* Public */,
      19,    0,  150,    2, 0x06 /* Public */,
      20,    1,  151,    2, 0x06 /* Public */,
      23,    0,  154,    2, 0x06 /* Public */,
      24,    0,  155,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,  156,    2, 0x0a /* Public */,
      26,    1,  159,    2, 0x0a /* Public */,
      28,    1,  162,    2, 0x0a /* Public */,
      29,    1,  165,    2, 0x0a /* Public */,
      30,    1,  168,    2, 0x0a /* Public */,
      31,    1,  171,    2, 0x0a /* Public */,
      32,    2,  174,    2, 0x0a /* Public */,
      33,    3,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   13,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::QVariant,    6,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   34,   35,   36,

       0        // eod
};

void TXcontroller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TXcontroller *_t = static_cast<TXcontroller *>(_o);
        switch (_id) {
        case 0: _t->connectMain(); break;
        case 1: _t->connectFile(); break;
        case 2: _t->TXdata((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 3: _t->Data((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 4: _t->DPCCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->scanFinish(); break;
        case 6: _t->ScanPos((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->MainClientStat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->DataClientStat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->currentPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->stepperMoving(); break;
        case 11: _t->switchingSucceed((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 12: _t->gotConnection(); break;
        case 13: _t->gotNewFile(); break;
        case 14: _t->gotDataMain((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 15: _t->ClientStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->gotDataFile((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 17: _t->DataClientStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->gotNewConnection((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 19: _t->SwitchPolarizer((*reinterpret_cast< Polarizer(*)>(_a[1]))); break;
        case 20: _t->moveToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
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
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::connectMain)) {
                *result = 0;
            }
        }
        {
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::connectFile)) {
                *result = 1;
            }
        }
        {
            typedef void (TXcontroller::*_t)(QPair<QString,QPair<QString,QVariant> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::TXdata)) {
                *result = 2;
            }
        }
        {
            typedef void (TXcontroller::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::Data)) {
                *result = 3;
            }
        }
        {
            typedef void (TXcontroller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::DPCCounts)) {
                *result = 4;
            }
        }
        {
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::scanFinish)) {
                *result = 5;
            }
        }
        {
            typedef void (TXcontroller::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::ScanPos)) {
                *result = 6;
            }
        }
        {
            typedef void (TXcontroller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::MainClientStat)) {
                *result = 7;
            }
        }
        {
            typedef void (TXcontroller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::DataClientStat)) {
                *result = 8;
            }
        }
        {
            typedef void (TXcontroller::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::currentPosition)) {
                *result = 9;
            }
        }
        {
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::stepperMoving)) {
                *result = 10;
            }
        }
        {
            typedef void (TXcontroller::*_t)(Polarizer );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::switchingSucceed)) {
                *result = 11;
            }
        }
        {
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::gotConnection)) {
                *result = 12;
            }
        }
        {
            typedef void (TXcontroller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TXcontroller::gotNewFile)) {
                *result = 13;
            }
        }
    }
}

const QMetaObject TXcontroller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TXcontroller.data,
      qt_meta_data_TXcontroller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TXcontroller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TXcontroller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TXcontroller.stringdata))
        return static_cast<void*>(const_cast< TXcontroller*>(this));
    return QObject::qt_metacast(_clname);
}

int TXcontroller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TXcontroller::connectMain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TXcontroller::connectFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TXcontroller::TXdata(QPair<QString,QPair<QString,QVariant> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TXcontroller::Data(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TXcontroller::DPCCounts(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TXcontroller::scanFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void TXcontroller::ScanPos(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TXcontroller::MainClientStat(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TXcontroller::DataClientStat(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TXcontroller::currentPosition(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TXcontroller::stepperMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void TXcontroller::switchingSucceed(Polarizer _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void TXcontroller::gotConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void TXcontroller::gotNewFile()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
