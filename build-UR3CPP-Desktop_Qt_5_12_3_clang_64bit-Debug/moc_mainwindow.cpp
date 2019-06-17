/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Desktop/UR3TestApp/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "moduleChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "object"
QT_MOC_LITERAL(4, 33, 21), // "OnConnectedDialogInfo"
QT_MOC_LITERAL(5, 55, 2), // "ip"
QT_MOC_LITERAL(6, 58, 4), // "port"
QT_MOC_LITERAL(7, 63, 7), // "OnMoveJ"
QT_MOC_LITERAL(8, 71, 8), // "OnSpeedJ"
QT_MOC_LITERAL(9, 80, 7), // "OnMoveL"
QT_MOC_LITERAL(10, 88, 12), // "OnSamuraiCut"
QT_MOC_LITERAL(11, 101, 18), // "OnActionConnection"
QT_MOC_LITERAL(12, 120, 4), // "Home"
QT_MOC_LITERAL(13, 125, 13), // "OnNewJointPos"
QT_MOC_LITERAL(14, 139, 15), // "QVector<double>"
QT_MOC_LITERAL(15, 155, 4), // "pose"
QT_MOC_LITERAL(16, 160, 8), // "OnNewTCP"
QT_MOC_LITERAL(17, 169, 4), // "data"
QT_MOC_LITERAL(18, 174, 1), // "c"
QT_MOC_LITERAL(19, 176, 15), // "ConnectedToInfo"
QT_MOC_LITERAL(20, 192, 5), // "char*"
QT_MOC_LITERAL(21, 198, 2), // "Ip"
QT_MOC_LITERAL(22, 201, 8), // "Achieved"
QT_MOC_LITERAL(23, 210, 12) // "showSettings"

    },
    "MainWindow\0moduleChanged\0\0object\0"
    "OnConnectedDialogInfo\0ip\0port\0OnMoveJ\0"
    "OnSpeedJ\0OnMoveL\0OnSamuraiCut\0"
    "OnActionConnection\0Home\0OnNewJointPos\0"
    "QVector<double>\0pose\0OnNewTCP\0data\0c\0"
    "ConnectedToInfo\0char*\0Ip\0Achieved\0"
    "showSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   77,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      16,    2,   91,    2, 0x0a /* Public */,
      19,    2,   96,    2, 0x0a /* Public */,
      23,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Char,   17,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Bool,   21,   22,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moduleChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->OnConnectedDialogInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->OnMoveJ(); break;
        case 3: _t->OnSpeedJ(); break;
        case 4: _t->OnMoveL(); break;
        case 5: _t->OnSamuraiCut(); break;
        case 6: _t->OnActionConnection(); break;
        case 7: _t->Home(); break;
        case 8: _t->OnNewJointPos((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 9: _t->OnNewTCP((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2]))); break;
        case 10: _t->ConnectedToInfo((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->showSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
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
            using _t = void (MainWindow::*)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::moduleChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::moduleChanged(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
