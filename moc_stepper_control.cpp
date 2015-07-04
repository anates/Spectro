/****************************************************************************
** Meta object code from reading C++ file 'stepper_control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stepper_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stepper_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Stepper_Control_Worker_t {
    QByteArrayData data[7];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Stepper_Control_Worker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Stepper_Control_Worker_t qt_meta_stringdata_Stepper_Control_Worker = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Stepper_Control_Worker"
QT_MOC_LITERAL(1, 23, 12), // "StepperMoved"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "currentStatus"
QT_MOC_LITERAL(4, 51, 11), // "moveStepper"
QT_MOC_LITERAL(5, 63, 5), // "steps"
QT_MOC_LITERAL(6, 69, 3) // "dir"

    },
    "Stepper_Control_Worker\0StepperMoved\0"
    "\0currentStatus\0moveStepper\0steps\0dir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stepper_Control_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       3,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    6,

       0        // eod
};

void Stepper_Control_Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stepper_Control_Worker *_t = static_cast<Stepper_Control_Worker *>(_o);
        switch (_id) {
        case 0: _t->StepperMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->currentStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->moveStepper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Stepper_Control_Worker::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stepper_Control_Worker::StepperMoved)) {
                *result = 0;
            }
        }
        {
            typedef void (Stepper_Control_Worker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stepper_Control_Worker::currentStatus)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Stepper_Control_Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Stepper_Control_Worker.data,
      qt_meta_data_Stepper_Control_Worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Stepper_Control_Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stepper_Control_Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Stepper_Control_Worker.stringdata))
        return static_cast<void*>(const_cast< Stepper_Control_Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Stepper_Control_Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Stepper_Control_Worker::StepperMoved(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Stepper_Control_Worker::currentStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Stepper_Control_Master_t {
    QByteArrayData data[11];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Stepper_Control_Master_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Stepper_Control_Master_t qt_meta_stringdata_Stepper_Control_Master = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Stepper_Control_Master"
QT_MOC_LITERAL(1, 23, 11), // "moveStepper"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "CurrentPosition"
QT_MOC_LITERAL(4, 52, 13), // "CurrentStatus"
QT_MOC_LITERAL(5, 66, 14), // "StepMotorMoved"
QT_MOC_LITERAL(6, 81, 5), // "steps"
QT_MOC_LITERAL(7, 87, 3), // "dir"
QT_MOC_LITERAL(8, 91, 6), // "Status"
QT_MOC_LITERAL(9, 98, 6), // "status"
QT_MOC_LITERAL(10, 105, 13) // "moveStepMotor"

    },
    "Stepper_Control_Master\0moveStepper\0\0"
    "CurrentPosition\0CurrentStatus\0"
    "StepMotorMoved\0steps\0dir\0Status\0status\0"
    "moveStepMotor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stepper_Control_Master[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       3,    2,   49,    2, 0x06 /* Public */,
       4,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   57,    2, 0x0a /* Public */,
       8,    1,   62,    2, 0x0a /* Public */,
      10,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,

       0        // eod
};

void Stepper_Control_Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stepper_Control_Master *_t = static_cast<Stepper_Control_Master *>(_o);
        switch (_id) {
        case 0: _t->moveStepper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->CurrentPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->CurrentStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->StepMotorMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->Status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->moveStepMotor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Stepper_Control_Master::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stepper_Control_Master::moveStepper)) {
                *result = 0;
            }
        }
        {
            typedef void (Stepper_Control_Master::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stepper_Control_Master::CurrentPosition)) {
                *result = 1;
            }
        }
        {
            typedef void (Stepper_Control_Master::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stepper_Control_Master::CurrentStatus)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Stepper_Control_Master::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Stepper_Control_Master.data,
      qt_meta_data_Stepper_Control_Master,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Stepper_Control_Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stepper_Control_Master::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Stepper_Control_Master.stringdata))
        return static_cast<void*>(const_cast< Stepper_Control_Master*>(this));
    return QObject::qt_metacast(_clname);
}

int Stepper_Control_Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Stepper_Control_Master::moveStepper(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Stepper_Control_Master::CurrentPosition(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Stepper_Control_Master::CurrentStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
