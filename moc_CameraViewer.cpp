/****************************************************************************
** Meta object code from reading C++ file 'CameraViewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/Cameras/CameraViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraViewer[] = {

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
      20,   14,   13,   13, 0x0a,
      38,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CameraViewer[] = {
    "CameraViewer\0\0image\0setFrame(cv::Mat)\0"
    "VideoStreaming()\0"
};

void CameraViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraViewer *_t = static_cast<CameraViewer *>(_o);
        switch (_id) {
        case 0: _t->setFrame((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->VideoStreaming(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CameraViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CameraViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraViewer,
      qt_meta_data_CameraViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraViewer))
        return static_cast<void*>(const_cast< CameraViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int CameraViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
