/****************************************************************************
** Meta object code from reading C++ file 'ThreadableObject.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/Calibration/ThreadableObject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadableObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadableObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      31,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   43,   17,   17, 0x0a,
      79,   17,   17,   17, 0x0a,
      89,   17,   17,   17, 0x0a,
      96,   17,   17,   17, 0x0a,
     117,   17,  108,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ThreadableObject[] = {
    "ThreadableObject\0\0Destroying()\0"
    "Destroyed()\0_thread\0ConnectWithThread(QThread*)\0"
    "Destroy()\0Init()\0OnDestroy()\0QThread*\0"
    "GetThread()\0"
};

void ThreadableObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadableObject *_t = static_cast<ThreadableObject *>(_o);
        switch (_id) {
        case 0: _t->Destroying(); break;
        case 1: _t->Destroyed(); break;
        case 2: _t->ConnectWithThread((*reinterpret_cast< QThread*(*)>(_a[1]))); break;
        case 3: _t->Destroy(); break;
        case 4: _t->Init(); break;
        case 5: _t->OnDestroy(); break;
        case 6: { QThread* _r = _t->GetThread();
            if (_a[0]) *reinterpret_cast< QThread**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadableObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadableObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadableObject,
      qt_meta_data_ThreadableObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadableObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadableObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadableObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadableObject))
        return static_cast<void*>(const_cast< ThreadableObject*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadableObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ThreadableObject::Destroying()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ThreadableObject::Destroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
