/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcp_client_test/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[16];
    char stringdata[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 16), // "gotNewConnection"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "sessionOpened"
QT_MOC_LITERAL(4, 39, 11), // "sendFortune"
QT_MOC_LITERAL(5, 51, 11), // "textFortune"
QT_MOC_LITERAL(6, 63, 12), // "spamFortunes"
QT_MOC_LITERAL(7, 76, 8), // "sendData"
QT_MOC_LITERAL(8, 85, 39), // "QPair<QString,QPair<QString,Q..."
QT_MOC_LITERAL(9, 125, 4), // "data"
QT_MOC_LITERAL(10, 130, 8), // "sendFile"
QT_MOC_LITERAL(11, 139, 8), // "fileName"
QT_MOC_LITERAL(12, 148, 16), // "disconnectServer"
QT_MOC_LITERAL(13, 165, 17), // "openNewConnection"
QT_MOC_LITERAL(14, 183, 16), // "QPairToByteArray"
QT_MOC_LITERAL(15, 200, 8) // "textData"

    },
    "Server\0gotNewConnection\0\0sessionOpened\0"
    "sendFortune\0textFortune\0spamFortunes\0"
    "sendData\0QPair<QString,QPair<QString,QVariant> >\0"
    "data\0sendFile\0fileName\0disconnectServer\0"
    "openNewConnection\0QPairToByteArray\0"
    "textData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   72,    2, 0x0a /* Public */,
       4,    0,   73,    2, 0x0a /* Public */,
       5,    0,   74,    2, 0x0a /* Public */,
       6,    0,   75,    2, 0x0a /* Public */,
       7,    1,   76,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    0,   83,    2, 0x0a /* Public */,
      14,    1,   84,    2, 0x0a /* Public */,
      15,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QVariant,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QByteArray, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->gotNewConnection((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->sessionOpened(); break;
        case 2: _t->sendFortune(); break;
        case 3: _t->textFortune(); break;
        case 4: _t->spamFortunes(); break;
        case 5: _t->sendData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 6: _t->sendFile((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 7: _t->disconnectServer(); break;
        case 8: _t->openNewConnection(); break;
        case 9: { QByteArray _r = _t->QPairToByteArray((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 10: _t->textData((*reinterpret_cast< QPair<QString,QPair<QString,QVariant> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Server::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::gotNewConnection)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata))
        return static_cast<void*>(const_cast< Server*>(this));
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Server::gotNewConnection(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
