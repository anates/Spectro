/****************************************************************************
** Meta object code from reading C++ file 'scanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Scanner_Worker_t {
    QByteArrayData data[14];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scanner_Worker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scanner_Worker_t qt_meta_stringdata_Scanner_Worker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Scanner_Worker"
QT_MOC_LITERAL(1, 15, 12), // "ScanFinished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "currentPosition"
QT_MOC_LITERAL(4, 45, 8), // "position"
QT_MOC_LITERAL(5, 54, 11), // "currentData"
QT_MOC_LITERAL(6, 66, 14), // "QPair<int,int>"
QT_MOC_LITERAL(7, 81, 8), // "moveStep"
QT_MOC_LITERAL(8, 90, 7), // "runScan"
QT_MOC_LITERAL(9, 98, 5), // "steps"
QT_MOC_LITERAL(10, 104, 8), // "accuracy"
QT_MOC_LITERAL(11, 113, 8), // "stopScan"
QT_MOC_LITERAL(12, 122, 13), // "currentCounts"
QT_MOC_LITERAL(13, 136, 6) // "counts"

    },
    "Scanner_Worker\0ScanFinished\0\0"
    "currentPosition\0position\0currentData\0"
    "QPair<int,int>\0moveStep\0runScan\0steps\0"
    "accuracy\0stopScan\0currentCounts\0counts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scanner_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   57,    2, 0x0a /* Public */,
      11,    0,   62,    2, 0x0a /* Public */,
      12,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Scanner_Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scanner_Worker *_t = static_cast<Scanner_Worker *>(_o);
        switch (_id) {
        case 0: _t->ScanFinished(); break;
        case 1: _t->currentPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 3: _t->moveStep(); break;
        case 4: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->stopScan(); break;
        case 6: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Scanner_Worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Worker::ScanFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (Scanner_Worker::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Worker::currentPosition)) {
                *result = 1;
            }
        }
        {
            typedef void (Scanner_Worker::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Worker::currentData)) {
                *result = 2;
            }
        }
        {
            typedef void (Scanner_Worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Worker::moveStep)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Scanner_Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scanner_Worker.data,
      qt_meta_data_Scanner_Worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scanner_Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scanner_Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scanner_Worker.stringdata))
        return static_cast<void*>(const_cast< Scanner_Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Scanner_Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Scanner_Worker::ScanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Scanner_Worker::currentPosition(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scanner_Worker::currentData(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Scanner_Worker::moveStep()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_Scanner_Master_t {
    QByteArrayData data[23];
    char stringdata[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scanner_Master_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scanner_Master_t qt_meta_stringdata_Scanner_Master = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Scanner_Master"
QT_MOC_LITERAL(1, 15, 13), // "runScanWorker"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "currentCountsToWorker"
QT_MOC_LITERAL(4, 52, 16), // "currentDataToExt"
QT_MOC_LITERAL(5, 69, 14), // "QPair<int,int>"
QT_MOC_LITERAL(6, 84, 19), // "moveStepperToTarget"
QT_MOC_LITERAL(7, 104, 12), // "scanFinished"
QT_MOC_LITERAL(8, 117, 15), // "scanInterrupted"
QT_MOC_LITERAL(9, 133, 19), // "scanCurrentPosition"
QT_MOC_LITERAL(10, 153, 8), // "position"
QT_MOC_LITERAL(11, 162, 11), // "currentData"
QT_MOC_LITERAL(12, 174, 4), // "data"
QT_MOC_LITERAL(13, 179, 8), // "moveStep"
QT_MOC_LITERAL(14, 188, 14), // "scanIsFinished"
QT_MOC_LITERAL(15, 203, 15), // "currentPosition"
QT_MOC_LITERAL(16, 219, 13), // "interruptScan"
QT_MOC_LITERAL(17, 233, 13), // "currentCounts"
QT_MOC_LITERAL(18, 247, 6), // "counts"
QT_MOC_LITERAL(19, 254, 7), // "runScan"
QT_MOC_LITERAL(20, 262, 5), // "start"
QT_MOC_LITERAL(21, 268, 4), // "stop"
QT_MOC_LITERAL(22, 273, 8) // "accuracy"

    },
    "Scanner_Master\0runScanWorker\0\0"
    "currentCountsToWorker\0currentDataToExt\0"
    "QPair<int,int>\0moveStepperToTarget\0"
    "scanFinished\0scanInterrupted\0"
    "scanCurrentPosition\0position\0currentData\0"
    "data\0moveStep\0scanIsFinished\0"
    "currentPosition\0interruptScan\0"
    "currentCounts\0counts\0runScan\0start\0"
    "stop\0accuracy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scanner_Master[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       3,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    2,   95,    2, 0x06 /* Public */,
       7,    0,  100,    2, 0x06 /* Public */,
       8,    0,  101,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  105,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x0a /* Public */,
      17,    1,  114,    2, 0x0a /* Public */,
      19,    3,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   20,   21,   22,

       0        // eod
};

void Scanner_Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scanner_Master *_t = static_cast<Scanner_Master *>(_o);
        switch (_id) {
        case 0: _t->runScanWorker((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->currentCountsToWorker((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->currentDataToExt((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 3: _t->moveStepperToTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->scanFinished(); break;
        case 5: _t->scanInterrupted(); break;
        case 6: _t->scanCurrentPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->currentData((*reinterpret_cast< QPair<int,int>(*)>(_a[1]))); break;
        case 8: _t->moveStep(); break;
        case 9: _t->scanIsFinished(); break;
        case 10: _t->currentPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->interruptScan(); break;
        case 12: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->runScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Scanner_Master::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::runScanWorker)) {
                *result = 0;
            }
        }
        {
            typedef void (Scanner_Master::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::currentCountsToWorker)) {
                *result = 1;
            }
        }
        {
            typedef void (Scanner_Master::*_t)(QPair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::currentDataToExt)) {
                *result = 2;
            }
        }
        {
            typedef void (Scanner_Master::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::moveStepperToTarget)) {
                *result = 3;
            }
        }
        {
            typedef void (Scanner_Master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::scanFinished)) {
                *result = 4;
            }
        }
        {
            typedef void (Scanner_Master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::scanInterrupted)) {
                *result = 5;
            }
        }
        {
            typedef void (Scanner_Master::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scanner_Master::scanCurrentPosition)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject Scanner_Master::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scanner_Master.data,
      qt_meta_data_Scanner_Master,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scanner_Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scanner_Master::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scanner_Master.stringdata))
        return static_cast<void*>(const_cast< Scanner_Master*>(this));
    return QObject::qt_metacast(_clname);
}

int Scanner_Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Scanner_Master::runScanWorker(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scanner_Master::currentCountsToWorker(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scanner_Master::currentDataToExt(QPair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Scanner_Master::moveStepperToTarget(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Scanner_Master::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Scanner_Master::scanInterrupted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Scanner_Master::scanCurrentPosition(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
