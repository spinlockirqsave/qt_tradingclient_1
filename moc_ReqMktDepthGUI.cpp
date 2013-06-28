/****************************************************************************
** Meta object code from reading C++ file 'ReqMktDepthGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ReqMktDepthGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReqMktDepthGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReqMktDepthGUI_t {
    QByteArrayData data[13];
    char stringdata[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ReqMktDepthGUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ReqMktDepthGUI_t qt_meta_stringdata_ReqMktDepthGUI = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 11),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 8),
QT_MOC_LITERAL(4, 37, 7),
QT_MOC_LITERAL(5, 45, 10),
QT_MOC_LITERAL(6, 56, 14),
QT_MOC_LITERAL(7, 71, 13),
QT_MOC_LITERAL(8, 85, 17),
QT_MOC_LITERAL(9, 103, 11),
QT_MOC_LITERAL(10, 115, 19),
QT_MOC_LITERAL(11, 135, 20),
QT_MOC_LITERAL(12, 156, 21)
    },
    "ReqMktDepthGUI\0newMktDepth\0\0tickerId\0"
    "rec_ptr\0record_ptr\0requestClicked\0"
    "cancelClicked\0guiRequestClicked\0"
    "displayData\0myTickSizeGUIUpdate\0"
    "myTickPriceGUIUpdate\0myTickStringGUIUpdate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReqMktDepthGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x0a,
       7,    0,   60,    2, 0x0a,
       8,    0,   61,    2, 0x0a,
       9,    2,   62,    2, 0x0a,
      10,    2,   67,    2, 0x0a,
      11,    2,   72,    2, 0x0a,
      12,    2,   77,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void ReqMktDepthGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReqMktDepthGUI *_t = static_cast<ReqMktDepthGUI *>(_o);
        switch (_id) {
        case 0: _t->newMktDepth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 1: _t->requestClicked(); break;
        case 2: _t->cancelClicked(); break;
        case 3: _t->guiRequestClicked(); break;
        case 4: _t->displayData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 5: _t->myTickSizeGUIUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 6: _t->myTickPriceGUIUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 7: _t->myTickStringGUIUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReqMktDepthGUI::*_t)(int , rec_ptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReqMktDepthGUI::newMktDepth)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ReqMktDepthGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReqMktDepthGUI.data,
      qt_meta_data_ReqMktDepthGUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *ReqMktDepthGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReqMktDepthGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReqMktDepthGUI.stringdata))
        return static_cast<void*>(const_cast< ReqMktDepthGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int ReqMktDepthGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ReqMktDepthGUI::newMktDepth(int _t1, rec_ptr _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
