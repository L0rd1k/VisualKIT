/****************************************************************************
** Meta object code from reading C++ file 'CalibrationExecutor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/CalibrationExecutor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalibrationExecutor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalibrationExecutor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   20,   20,   20, 0x08,
      68,   20,   20,   20, 0x08,
      91,   20,   20,   20, 0x08,
     123,   20,   20,   20, 0x08,
     137,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CalibrationExecutor[] = {
    "CalibrationExecutor\0\0imageReady(cv::Mat)\0"
    "selectCheckboxChessboard()\0"
    "selectCheckboxCircle()\0"
    "collectImagesFromSingleCamera()\0"
    "updateFrame()\0takeSnapShootFromVideo()\0"
};

void CalibrationExecutor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalibrationExecutor *_t = static_cast<CalibrationExecutor *>(_o);
        switch (_id) {
        case 0: _t->imageReady((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->selectCheckboxChessboard(); break;
        case 2: _t->selectCheckboxCircle(); break;
        case 3: _t->collectImagesFromSingleCamera(); break;
        case 4: _t->updateFrame(); break;
        case 5: _t->takeSnapShootFromVideo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CalibrationExecutor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalibrationExecutor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalibrationExecutor,
      qt_meta_data_CalibrationExecutor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalibrationExecutor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalibrationExecutor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalibrationExecutor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrationExecutor))
        return static_cast<void*>(const_cast< CalibrationExecutor*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalibrationExecutor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CalibrationExecutor::imageReady(cv::Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
