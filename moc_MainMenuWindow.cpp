/****************************************************************************
** Meta object code from reading C++ file 'MainMenuWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/MainMenuWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainMenuWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainMenuWindow[] = {

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
      16,   15,   15,   15, 0x08,
      38,   15,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainMenuWindow[] = {
    "MainMenuWindow\0\0regime_CalculateFoV()\0"
    "regime_CalculateSingleCalib()\0"
    "regime_CaptureStream()\0"
};

void MainMenuWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainMenuWindow *_t = static_cast<MainMenuWindow *>(_o);
        switch (_id) {
        case 0: _t->regime_CalculateFoV(); break;
        case 1: _t->regime_CalculateSingleCalib(); break;
        case 2: _t->regime_CaptureStream(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainMenuWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainMenuWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainMenuWindow,
      qt_meta_data_MainMenuWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainMenuWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainMenuWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainMenuWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuWindow))
        return static_cast<void*>(const_cast< MainMenuWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainMenuWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
