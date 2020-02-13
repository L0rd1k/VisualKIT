/****************************************************************************
** Meta object code from reading C++ file 'FieldOfViewWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/FieldOfViewWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FieldOfViewWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FieldOfViewWindow[] = {

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
      50,   24,   19,   18, 0x08,
     104,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FieldOfViewWindow[] = {
    "FieldOfViewWindow\0\0bool\0"
    "matrix,distortion,imgSize\0"
    "openFolderWithIntrinsics(cv::Mat&,cv::Mat&,cv::Size&)\0"
    "calculateFieldOfView()\0"
};

void FieldOfViewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FieldOfViewWindow *_t = static_cast<FieldOfViewWindow *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->openFolderWithIntrinsics((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Size(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->calculateFieldOfView(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FieldOfViewWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FieldOfViewWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FieldOfViewWindow,
      qt_meta_data_FieldOfViewWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FieldOfViewWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FieldOfViewWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FieldOfViewWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FieldOfViewWindow))
        return static_cast<void*>(const_cast< FieldOfViewWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int FieldOfViewWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
