/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcp_client_test/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[17];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 7), // "gotData"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 39), // "QPair<QString,QPair<QString,Q..."
QT_MOC_LITERAL(4, 56, 12), // "noConnection"
QT_MOC_LITERAL(5, 69, 16), // "connectionResult"
QT_MOC_LITERAL(6, 86, 12), // "isDisconnect"
QT_MOC_LITERAL(7, 99, 12), // "displayError"
QT_MOC_LITERAL(8, 112, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 141, 11), // "socketError"
QT_MOC_LITERAL(10, 153, 13), // "sessionOpened"
QT_MOC_LITERAL(11, 167, 7), // "getInfo"
QT_MOC_LITERAL(12, 175, 8), // "readData"
QT_MOC_LITERAL(13, 184, 15), // "connectToServer"
QT_MOC_LITERAL(14, 200, 6), // "ipAddr"
QT_MOC_LITERAL(15, 207, 4), // "port"
QT_MOC_LITERAL(16, 212, 20) // "disconnectFromServer"

    },
    "Client\0gotData\0\0QPair<QString,QPair<QString,QVariant> >\0"
    "noConnection\0connectionResult\0"
    "isDisconnect\0displayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "sessionOpened\0getInfo\0readData\0"
    "connectToServer\0ipAddr\0port\0"
    "disconnectFromServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   74,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    2,   80,    2, 0x0a /* Public */,
      16,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,   14,   15,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->gotData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 1: _t->noConnection(); break;
        case 2: _t->connectionResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->isDisconnect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->sessionOpened(); break;
        case 6: _t->getInfo(); break;
        case 7: _t->readData(); break;
        case 8: _t->connectToServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 9: _t->disconnectFromServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)(QPair<QString,QPair<QString,QVariant> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::gotData)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::noConnection)) {
                *result = 1;
            }
        }
        {
            typedef void (Client::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::connectionResult)) {
                *result = 2;
            }
        }
        {
            typedef void (Client::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::isDisconnect)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Client::gotData(QPair<QString,QPair<QString,QVariant> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::noConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Client::connectionResult(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::isDisconnect(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
