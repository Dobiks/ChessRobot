/****************************************************************************
** Meta object code from reading C++ file 'UR3Intermediator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Desktop/UR3TestApp/UR3Intermediator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UR3Intermediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UR3Intermediator_t {
    QByteArrayData data[15];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UR3Intermediator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UR3Intermediator_t qt_meta_stringdata_UR3Intermediator = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UR3Intermediator"
QT_MOC_LITERAL(1, 17, 10), // "newPoseTCP"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 45, 1), // "x"
QT_MOC_LITERAL(5, 47, 4), // "flag"
QT_MOC_LITERAL(6, 52, 16), // "ConnectionAction"
QT_MOC_LITERAL(7, 69, 5), // "char*"
QT_MOC_LITERAL(8, 75, 2), // "Ip"
QT_MOC_LITERAL(9, 78, 6), // "Result"
QT_MOC_LITERAL(10, 85, 12), // "disconnected"
QT_MOC_LITERAL(11, 98, 12), // "OnTcpChanged"
QT_MOC_LITERAL(12, 111, 23), // "OnSocketNewBytesWritten"
QT_MOC_LITERAL(13, 135, 4), // "Port"
QT_MOC_LITERAL(14, 140, 9) // "IpAddress"

    },
    "UR3Intermediator\0newPoseTCP\0\0"
    "QVector<double>\0x\0flag\0ConnectionAction\0"
    "char*\0Ip\0Result\0disconnected\0OnTcpChanged\0"
    "OnSocketNewBytesWritten\0Port\0IpAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UR3Intermediator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   49,    2, 0x08 /* Private */,
      11,    0,   50,    2, 0x0a /* Public */,
      12,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Char,    4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00195103,
      14, QMetaType::QString, 0x00195103,

       0        // eod
};

void UR3Intermediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UR3Intermediator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPoseTCP((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2]))); break;
        case 1: _t->ConnectionAction((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->disconnected(); break;
        case 3: _t->OnTcpChanged(); break;
        case 4: _t->OnSocketNewBytesWritten(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UR3Intermediator::*)(QVector<double> , char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UR3Intermediator::newPoseTCP)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UR3Intermediator::*)(char * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UR3Intermediator::ConnectionAction)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UR3Intermediator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getPort(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getIpAddress(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UR3Intermediator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPort(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setIpAddress(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UR3Intermediator::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_UR3Intermediator.data,
    qt_meta_data_UR3Intermediator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UR3Intermediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UR3Intermediator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UR3Intermediator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UR3Intermediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UR3Intermediator::newPoseTCP(QVector<double> _t1, char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UR3Intermediator::ConnectionAction(char * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
