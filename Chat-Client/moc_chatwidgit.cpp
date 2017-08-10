/****************************************************************************
** Meta object code from reading C++ file 'chatwidgit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chatwidgit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwidgit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatWidgit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      52,   11,   11,   11, 0x05,
      71,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      97,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     207,  186,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatWidgit[] = {
    "ChatWidgit\0\0,\0sendMessagesFromChat(QString,QString)\0"
    "closeChat(QString)\0sendFile(QString,QString)\0"
    "on_textHistory_clicked()\0on_textSave_clicked()\0"
    "on_textBin_clicked()\0on_btnSend_clicked()\0"
    "address,first,second\0"
    "setMessage(QString,QString,QString)\0"
    "on_btnClose_clicked()\0"
};

void ChatWidgit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChatWidgit *_t = static_cast<ChatWidgit *>(_o);
        switch (_id) {
        case 0: _t->sendMessagesFromChat((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->closeChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_textHistory_clicked(); break;
        case 4: _t->on_textSave_clicked(); break;
        case 5: _t->on_textBin_clicked(); break;
        case 6: _t->on_btnSend_clicked(); break;
        case 7: _t->setMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->on_btnClose_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChatWidgit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChatWidgit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWidgit,
      qt_meta_data_ChatWidgit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatWidgit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatWidgit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatWidgit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWidgit))
        return static_cast<void*>(const_cast< ChatWidgit*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChatWidgit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ChatWidgit::sendMessagesFromChat(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatWidgit::closeChat(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatWidgit::sendFile(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
