/****************************************************************************
** Meta object code from reading C++ file 'widgt.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widgt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,    7,    6,    6, 0x05,
      82,   67,    6,    6, 0x05,
     146,  108,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     200,    6,    6,    6, 0x08,
     226,  220,    6,    6, 0x08,
     270,    6,    6,    6, 0x08,
     292,    6,    6,    6, 0x08,
     301,    6,    6,    6, 0x08,
     319,    6,    6,    6, 0x08,
     331,    6,    6,    6, 0x08,
     342,    6,    6,    6, 0x08,
     367,  365,    6,    6, 0x08,
     403,    6,    6,    6, 0x08,
     429,  365,    6,    6, 0x08,
     459,  365,    6,    6, 0x08,
     495,  490,    6,    6, 0x08,
     513,  490,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widgt[] = {
    "Widgt\0\0address,first,second\0"
    "sendMessagesZ(QString,QString,QString)\0"
    "ipaddress,name\0senddata(QString,QString)\0"
    "username,realname,sex,phone,registime\0"
    "senduserinfo(QString,QString,QString,QString,QString)\0"
    "on_btnAll_clicked()\0index\0"
    "on_tableWidget_2_doubleClicked(QModelIndex)\0"
    "sendMessageToFriend()\0addfri()\0"
    "userinformation()\0deletefri()\0synclist()\0"
    "closeFromChat(QString)\0,\0"
    "sendMessagesToMain(QString,QString)\0"
    "processPendingDatagrams()\0"
    "sentFileName(QString,QString)\0"
    "hasFileToSend(QString,QString)\0data\0"
    "recvdata(QString)\0recvkeydata(QString)\0"
};

void Widgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widgt *_t = static_cast<Widgt *>(_o);
        switch (_id) {
        case 0: _t->sendMessagesZ((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->senddata((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->senduserinfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 3: _t->on_btnAll_clicked(); break;
        case 4: _t->on_tableWidget_2_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->sendMessageToFriend(); break;
        case 6: _t->addfri(); break;
        case 7: _t->userinformation(); break;
        case 8: _t->deletefri(); break;
        case 9: _t->synclist(); break;
        case 10: _t->closeFromChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sendMessagesToMain((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->processPendingDatagrams(); break;
        case 13: _t->sentFileName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->hasFileToSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->recvdata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->recvkeydata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widgt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widgt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widgt,
      qt_meta_data_Widgt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widgt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widgt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widgt))
        return static_cast<void*>(const_cast< Widgt*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Widgt::sendMessagesZ(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widgt::senddata(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widgt::senduserinfo(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
