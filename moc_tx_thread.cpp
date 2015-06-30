/****************************************************************************
** Meta object code from reading C++ file 'tx_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../remoteController/tx_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tx_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TX_worker_t {
    QByteArrayData data[21];
    char stringdata[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TX_worker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TX_worker_t qt_meta_stringdata_TX_worker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TX_worker"
QT_MOC_LITERAL(1, 10, 10), // "gotNewData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 39), // "QPair<QString,QPair<QString,Q..."
QT_MOC_LITERAL(4, 62, 17), // "ClientIsConnected"
QT_MOC_LITERAL(5, 80, 20), // "ClientIsDisconnected"
QT_MOC_LITERAL(6, 101, 9), // "TXStopped"
QT_MOC_LITERAL(7, 111, 9), // "connectRX"
QT_MOC_LITERAL(8, 121, 6), // "ipAddr"
QT_MOC_LITERAL(9, 128, 4), // "port"
QT_MOC_LITERAL(10, 133, 7), // "killAll"
QT_MOC_LITERAL(11, 141, 11), // "sendNewData"
QT_MOC_LITERAL(12, 153, 8), // "noServer"
QT_MOC_LITERAL(13, 162, 7), // "gotData"
QT_MOC_LITERAL(14, 170, 4), // "data"
QT_MOC_LITERAL(15, 175, 13), // "connect_to_TX"
QT_MOC_LITERAL(16, 189, 13), // "noServerFound"
QT_MOC_LITERAL(17, 203, 11), // "isConnected"
QT_MOC_LITERAL(18, 215, 6), // "status"
QT_MOC_LITERAL(19, 222, 14), // "isDisconnected"
QT_MOC_LITERAL(20, 237, 6) // "killTX"

    },
    "TX_worker\0gotNewData\0\0"
    "QPair<QString,QPair<QString,QVariant> >\0"
    "ClientIsConnected\0ClientIsDisconnected\0"
    "TXStopped\0connectRX\0ipAddr\0port\0killAll\0"
    "sendNewData\0noServer\0gotData\0data\0"
    "connect_to_TX\0noServerFound\0isConnected\0"
    "status\0isDisconnected\0killTX"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TX_worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    2,   94,    2, 0x06 /* Public */,
      10,    0,   99,    2, 0x06 /* Public */,
      11,    1,  100,    2, 0x06 /* Public */,
      12,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  104,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,
      19,    1,  112,    2, 0x0a /* Public */,
      20,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,

       0        // eod
};

void TX_worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TX_worker *_t = static_cast<TX_worker *>(_o);
        switch (_id) {
        case 0: _t->gotNewData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 1: _t->ClientIsConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ClientIsDisconnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->TXStopped(); break;
        case 4: _t->connectRX((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 5: _t->killAll(); break;
        case 6: _t->sendNewData((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 7: _t->noServer(); break;
        case 8: _t->gotData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 9: _t->connect_to_TX(); break;
        case 10: _t->noServerFound(); break;
        case 11: _t->isConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->isDisconnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->killTX(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TX_worker::*_t)(QPair<QString,QPair<QString,QVariant> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::gotNewData)) {
                *result = 0;
            }
        }
        {
            typedef void (TX_worker::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::ClientIsConnected)) {
                *result = 1;
            }
        }
        {
            typedef void (TX_worker::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::ClientIsDisconnected)) {
                *result = 2;
            }
        }
        {
            typedef void (TX_worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::TXStopped)) {
                *result = 3;
            }
        }
        {
            typedef void (TX_worker::*_t)(QString , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::connectRX)) {
                *result = 4;
            }
        }
        {
            typedef void (TX_worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::killAll)) {
                *result = 5;
            }
        }
        {
            typedef void (TX_worker::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::sendNewData)) {
                *result = 6;
            }
        }
        {
            typedef void (TX_worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_worker::noServer)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject TX_worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TX_worker.data,
      qt_meta_data_TX_worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TX_worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TX_worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TX_worker.stringdata))
        return static_cast<void*>(const_cast< TX_worker*>(this));
    return QObject::qt_metacast(_clname);
}

int TX_worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TX_worker::gotNewData(QPair<QString,QPair<QString,QVariant> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TX_worker::ClientIsConnected(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TX_worker::ClientIsDisconnected(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TX_worker::TXStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TX_worker::connectRX(QString _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TX_worker::killAll()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void TX_worker::sendNewData(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TX_worker::noServer()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
struct qt_meta_stringdata_TX_master_t {
    QByteArrayData data[13];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TX_master_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TX_master_t qt_meta_stringdata_TX_master = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TX_master"
QT_MOC_LITERAL(1, 10, 13), // "connect_to_TX"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "ClientStatus"
QT_MOC_LITERAL(4, 38, 10), // "gotNewData"
QT_MOC_LITERAL(5, 49, 39), // "QPair<QString,QPair<QString,Q..."
QT_MOC_LITERAL(6, 89, 7), // "wrongIP"
QT_MOC_LITERAL(7, 97, 7), // "newData"
QT_MOC_LITERAL(8, 105, 4), // "data"
QT_MOC_LITERAL(9, 110, 8), // "noServer"
QT_MOC_LITERAL(10, 119, 18), // "changeClientStatus"
QT_MOC_LITERAL(11, 138, 6), // "status"
QT_MOC_LITERAL(12, 145, 9) // "connectTX"

    },
    "TX_master\0connect_to_TX\0\0ClientStatus\0"
    "gotNewData\0QPair<QString,QPair<QString,QVariant> >\0"
    "wrongIP\0newData\0data\0noServer\0"
    "changeClientStatus\0status\0connectTX"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TX_master[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       4,    1,   58,    2, 0x06 /* Public */,
       6,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   62,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,

       0        // eod
};

void TX_master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TX_master *_t = static_cast<TX_master *>(_o);
        switch (_id) {
        case 0: _t->connect_to_TX(); break;
        case 1: _t->ClientStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->gotNewData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 3: _t->wrongIP(); break;
        case 4: _t->newData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 5: _t->noServer(); break;
        case 6: _t->changeClientStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->connectTX(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TX_master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_master::connect_to_TX)) {
                *result = 0;
            }
        }
        {
            typedef void (TX_master::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_master::ClientStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (TX_master::*_t)(QPair<QString,QPair<QString,QVariant> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_master::gotNewData)) {
                *result = 2;
            }
        }
        {
            typedef void (TX_master::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TX_master::wrongIP)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject TX_master::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TX_master.data,
      qt_meta_data_TX_master,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TX_master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TX_master::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TX_master.stringdata))
        return static_cast<void*>(const_cast< TX_master*>(this));
    return QObject::qt_metacast(_clname);
}

int TX_master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TX_master::connect_to_TX()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TX_master::ClientStatus(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TX_master::gotNewData(QPair<QString,QPair<QString,QVariant> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TX_master::wrongIP()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
