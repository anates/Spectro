/****************************************************************************
** Meta object code from reading C++ file 'dpc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dpc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dpc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DPC_Worker_t {
    QByteArrayData data[5];
    char stringdata[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DPC_Worker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DPC_Worker_t qt_meta_stringdata_DPC_Worker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DPC_Worker"
QT_MOC_LITERAL(1, 11, 13), // "currentCounts"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "stopAquisition"
QT_MOC_LITERAL(4, 41, 12) // "aquireCounts"

    },
    "DPC_Worker\0currentCounts\0\0stopAquisition\0"
    "aquireCounts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DPC_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   32,    2, 0x0a /* Public */,
       4,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DPC_Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DPC_Worker *_t = static_cast<DPC_Worker *>(_o);
        switch (_id) {
        case 0: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->stopAquisition(); break;
        case 2: _t->aquireCounts(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DPC_Worker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DPC_Worker::currentCounts)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DPC_Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DPC_Worker.data,
      qt_meta_data_DPC_Worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DPC_Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DPC_Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DPC_Worker.stringdata))
        return static_cast<void*>(const_cast< DPC_Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int DPC_Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DPC_Worker::currentCounts(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DPC_Master_t {
    QByteArrayData data[7];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DPC_Master_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DPC_Master_t qt_meta_stringdata_DPC_Master = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DPC_Master"
QT_MOC_LITERAL(1, 11, 14), // "stopAquisition"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "startAquisition"
QT_MOC_LITERAL(4, 43, 12), // "currentCount"
QT_MOC_LITERAL(5, 56, 13), // "currentCounts"
QT_MOC_LITERAL(6, 70, 6) // "counts"

    },
    "DPC_Master\0stopAquisition\0\0startAquisition\0"
    "currentCount\0currentCounts\0counts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DPC_Master[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void DPC_Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DPC_Master *_t = static_cast<DPC_Master *>(_o);
        switch (_id) {
        case 0: _t->stopAquisition(); break;
        case 1: _t->startAquisition(); break;
        case 2: _t->currentCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->currentCounts((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DPC_Master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DPC_Master::stopAquisition)) {
                *result = 0;
            }
        }
        {
            typedef void (DPC_Master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DPC_Master::startAquisition)) {
                *result = 1;
            }
        }
        {
            typedef void (DPC_Master::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DPC_Master::currentCount)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DPC_Master::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DPC_Master.data,
      qt_meta_data_DPC_Master,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DPC_Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DPC_Master::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DPC_Master.stringdata))
        return static_cast<void*>(const_cast< DPC_Master*>(this));
    return QObject::qt_metacast(_clname);
}

int DPC_Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DPC_Master::stopAquisition()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DPC_Master::startAquisition()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DPC_Master::currentCount(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
