/****************************************************************************
** Meta object code from reading C++ file 'filesend.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filesend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_filesend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,    9,    9,    9, 0x08,
      75,    9,    9,    9, 0x08,
      98,   89,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_filesend[] = {
    "filesend\0\0fileName,addr\0"
    "sendFileName(QString,QString)\0"
    "on_btnQuit_clicked()\0sendMessage()\0"
    "numBytes\0updateClientProgress(qint64)\0"
};

void filesend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        filesend *_t = static_cast<filesend *>(_o);
        switch (_id) {
        case 0: _t->sendFileName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_btnQuit_clicked(); break;
        case 2: _t->sendMessage(); break;
        case 3: _t->updateClientProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData filesend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject filesend::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_filesend,
      qt_meta_data_filesend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &filesend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *filesend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *filesend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_filesend))
        return static_cast<void*>(const_cast< filesend*>(this));
    return QDialog::qt_metacast(_clname);
}

int filesend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void filesend::sendFileName(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
