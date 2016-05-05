/****************************************************************************
** Meta object code from reading C++ file 'Ka.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GamePlayScene/Ka.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ka.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ka_t {
    QByteArrayData data[3];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ka_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ka_t qt_meta_stringdata_Ka = {
    {
QT_MOC_LITERAL(0, 0, 2), // "Ka"
QT_MOC_LITERAL(1, 3, 4), // "move"
QT_MOC_LITERAL(2, 8, 0) // ""

    },
    "Ka\0move\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ka[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Ka::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ka *_t = static_cast<Ka *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Ka::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ka.data,
      qt_meta_data_Ka,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ka::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ka::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ka.stringdata0))
        return static_cast<void*>(const_cast< Ka*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Ka*>(this));
    return QObject::qt_metacast(_clname);
}

int Ka::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
