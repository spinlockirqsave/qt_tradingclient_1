/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cf16tradingclient_1_t {
    QByteArrayData data[7];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_cf16tradingclient_1_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_cf16tradingclient_1_t qt_meta_stringdata_cf16tradingclient_1 = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 17),
QT_MOC_LITERAL(4, 54, 23),
QT_MOC_LITERAL(5, 78, 24),
QT_MOC_LITERAL(6, 103, 26)
    },
    "cf16tradingclient_1\0connectClicked\0\0"
    "disconnectClicked\0actionReqMktDataClicked\0"
    "actionReqMktDepthClicked\0"
    "actionCointegrationClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cf16tradingclient_1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a,
       3,    0,   40,    2, 0x0a,
       4,    0,   41,    2, 0x0a,
       5,    0,   42,    2, 0x0a,
       6,    0,   43,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cf16tradingclient_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cf16tradingclient_1 *_t = static_cast<cf16tradingclient_1 *>(_o);
        switch (_id) {
        case 0: _t->connectClicked(); break;
        case 1: _t->disconnectClicked(); break;
        case 2: _t->actionReqMktDataClicked(); break;
        case 3: _t->actionReqMktDepthClicked(); break;
        case 4: _t->actionCointegrationClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cf16tradingclient_1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_cf16tradingclient_1.data,
      qt_meta_data_cf16tradingclient_1,  qt_static_metacall, 0, 0}
};


const QMetaObject *cf16tradingclient_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cf16tradingclient_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cf16tradingclient_1.stringdata))
        return static_cast<void*>(const_cast< cf16tradingclient_1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int cf16tradingclient_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
