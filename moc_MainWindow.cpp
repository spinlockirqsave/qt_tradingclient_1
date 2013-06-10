/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Mon Jun 10 09:42:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cf16tradingclient_1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      38,   20,   20,   20, 0x0a,
      58,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cf16tradingclient_1[] = {
    "cf16tradingclient_1\0\0connectClicked()\0"
    "disconnectClicked()\0actionReqMktDataClicked()\0"
};

void cf16tradingclient_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cf16tradingclient_1 *_t = static_cast<cf16tradingclient_1 *>(_o);
        switch (_id) {
        case 0: _t->connectClicked(); break;
        case 1: _t->disconnectClicked(); break;
        case 2: _t->actionReqMktDataClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData cf16tradingclient_1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cf16tradingclient_1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_cf16tradingclient_1,
      qt_meta_data_cf16tradingclient_1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cf16tradingclient_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cf16tradingclient_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cf16tradingclient_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cf16tradingclient_1))
        return static_cast<void*>(const_cast< cf16tradingclient_1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int cf16tradingclient_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
