/****************************************************************************
** Meta object code from reading C++ file 'ReqMktDataGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ReqMktDataGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReqMktDataGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReqMktDataGUI_t {
    QByteArrayData data[11];
    char stringdata[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ReqMktDataGUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ReqMktDataGUI_t qt_meta_stringdata_ReqMktDataGUI = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 10),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 10),
QT_MOC_LITERAL(6, 54, 14),
QT_MOC_LITERAL(7, 69, 13),
QT_MOC_LITERAL(8, 83, 17),
QT_MOC_LITERAL(9, 101, 11),
QT_MOC_LITERAL(10, 113, 19)
    },
    "ReqMktDataGUI\0newMktData\0\0tickerId\0"
    "rec_ptr\0record_ptr\0requestClicked\0"
    "cancelClicked\0guiRequestClicked\0"
    "displayData\0myTickSizeGUIupdate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReqMktDataGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a,
       7,    0,   50,    2, 0x0a,
       8,    0,   51,    2, 0x0a,
       9,    2,   52,    2, 0x0a,
      10,    2,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void ReqMktDataGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReqMktDataGUI *_t = static_cast<ReqMktDataGUI *>(_o);
        switch (_id) {
        case 0: _t->newMktData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 1: _t->requestClicked(); break;
        case 2: _t->cancelClicked(); break;
        case 3: _t->guiRequestClicked(); break;
        case 4: _t->displayData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        case 5: _t->myTickSizeGUIupdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< rec_ptr(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReqMktDataGUI::*_t)(int , rec_ptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReqMktDataGUI::newMktData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ReqMktDataGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReqMktDataGUI.data,
      qt_meta_data_ReqMktDataGUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *ReqMktDataGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReqMktDataGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReqMktDataGUI.stringdata))
        return static_cast<void*>(const_cast< ReqMktDataGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int ReqMktDataGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ReqMktDataGUI::newMktData(int _t1, rec_ptr _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
