/****************************************************************************
** Meta object code from reading C++ file 'serial_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serial_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_serial_controller_worker_t {
    QByteArrayData data[10];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serial_controller_worker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serial_controller_worker_t qt_meta_stringdata_serial_controller_worker = {
    {
QT_MOC_LITERAL(0, 0, 24), // "serial_controller_worker"
QT_MOC_LITERAL(1, 25, 8), // "response"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 1), // "s"
QT_MOC_LITERAL(4, 37, 5), // "error"
QT_MOC_LITERAL(5, 43, 7), // "timeout"
QT_MOC_LITERAL(6, 51, 11), // "transaction"
QT_MOC_LITERAL(7, 63, 7), // "request"
QT_MOC_LITERAL(8, 71, 5), // "delay"
QT_MOC_LITERAL(9, 77, 9) // "read_data"

    },
    "serial_controller_worker\0response\0\0s\0"
    "error\0timeout\0transaction\0request\0"
    "delay\0read_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial_controller_worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   48,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void serial_controller_worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serial_controller_worker *_t = static_cast<serial_controller_worker *>(_o);
        switch (_id) {
        case 0: _t->response((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->timeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->transaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->read_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (serial_controller_worker::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller_worker::response)) {
                *result = 0;
            }
        }
        {
            typedef void (serial_controller_worker::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller_worker::error)) {
                *result = 1;
            }
        }
        {
            typedef void (serial_controller_worker::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller_worker::timeout)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject serial_controller_worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_serial_controller_worker.data,
      qt_meta_data_serial_controller_worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *serial_controller_worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial_controller_worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_serial_controller_worker.stringdata))
        return static_cast<void*>(const_cast< serial_controller_worker*>(this));
    return QObject::qt_metacast(_clname);
}

int serial_controller_worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void serial_controller_worker::response(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void serial_controller_worker::error(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void serial_controller_worker::timeout(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_updater_t {
    QByteArrayData data[1];
    char stringdata[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_updater_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_updater_t qt_meta_stringdata_updater = {
    {
QT_MOC_LITERAL(0, 0, 7) // "updater"

    },
    "updater"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_updater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void updater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject updater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_updater.data,
      qt_meta_data_updater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *updater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *updater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_updater.stringdata))
        return static_cast<void*>(const_cast< updater*>(this));
    return QObject::qt_metacast(_clname);
}

int updater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_serial_controller_t {
    QByteArrayData data[15];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serial_controller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serial_controller_t qt_meta_stringdata_serial_controller = {
    {
QT_MOC_LITERAL(0, 0, 17), // "serial_controller"
QT_MOC_LITERAL(1, 18, 14), // "newTransaction"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "request"
QT_MOC_LITERAL(4, 42, 5), // "delay"
QT_MOC_LITERAL(5, 48, 8), // "response"
QT_MOC_LITERAL(6, 57, 16), // "QVector<QString>"
QT_MOC_LITERAL(7, 74, 1), // "s"
QT_MOC_LITERAL(8, 76, 5), // "error"
QT_MOC_LITERAL(9, 82, 7), // "timeout"
QT_MOC_LITERAL(10, 90, 10), // "CountValue"
QT_MOC_LITERAL(11, 101, 3), // "val"
QT_MOC_LITERAL(12, 105, 11), // "transaction"
QT_MOC_LITERAL(13, 117, 13), // "response_slot"
QT_MOC_LITERAL(14, 131, 9) // "read_data"

    },
    "serial_controller\0newTransaction\0\0"
    "request\0delay\0response\0QVector<QString>\0"
    "s\0error\0timeout\0CountValue\0val\0"
    "transaction\0response_slot\0read_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       8,    1,   62,    2, 0x06 /* Public */,
       9,    1,   65,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   71,    2, 0x0a /* Public */,
      13,    1,   76,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Double,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void serial_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serial_controller *_t = static_cast<serial_controller *>(_o);
        switch (_id) {
        case 0: _t->newTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->response((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->timeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->CountValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->transaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->response_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->read_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (serial_controller::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller::newTransaction)) {
                *result = 0;
            }
        }
        {
            typedef void (serial_controller::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller::response)) {
                *result = 1;
            }
        }
        {
            typedef void (serial_controller::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller::error)) {
                *result = 2;
            }
        }
        {
            typedef void (serial_controller::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller::timeout)) {
                *result = 3;
            }
        }
        {
            typedef void (serial_controller::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial_controller::CountValue)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject serial_controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_serial_controller.data,
      qt_meta_data_serial_controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *serial_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_serial_controller.stringdata))
        return static_cast<void*>(const_cast< serial_controller*>(this));
    return QObject::qt_metacast(_clname);
}

int serial_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void serial_controller::newTransaction(const QString & _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void serial_controller::response(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void serial_controller::error(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void serial_controller::timeout(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void serial_controller::CountValue(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
