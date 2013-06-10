/****************************************************************************
** Meta object code from reading C++ file 'reqMktDataGUI.h'
**
** Created: Mon Jun 10 09:42:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "reqMktDataGUI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reqMktDataGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_reqMktDataGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_reqMktDataGUI[] = {
    "reqMktDataGUI\0\0requestClicked()\0"
    "cancelClicked()\0"
};

void reqMktDataGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        reqMktDataGUI *_t = static_cast<reqMktDataGUI *>(_o);
        switch (_id) {
        case 0: _t->requestClicked(); break;
        case 1: _t->cancelClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData reqMktDataGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject reqMktDataGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_reqMktDataGUI,
      qt_meta_data_reqMktDataGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &reqMktDataGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *reqMktDataGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *reqMktDataGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_reqMktDataGUI))
        return static_cast<void*>(const_cast< reqMktDataGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int reqMktDataGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
