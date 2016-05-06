/****************************************************************************
** Meta object code from reading C++ file 'HitPoint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GamePlayScene/HitPoint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HitPoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HitPoint_t {
    QByteArrayData data[9];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HitPoint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HitPoint_t qt_meta_stringdata_HitPoint = {
    {
QT_MOC_LITERAL(0, 0, 8), // "HitPoint"
QT_MOC_LITERAL(1, 9, 8), // "setGrade"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "setAddScore"
QT_MOC_LITERAL(4, 31, 11), // "setAddCombo"
QT_MOC_LITERAL(5, 43, 11), // "setEndCombo"
QT_MOC_LITERAL(6, 55, 9), // "setHitted"
QT_MOC_LITERAL(7, 65, 14), // "checkCollision"
QT_MOC_LITERAL(8, 80, 4) // "type"

    },
    "HitPoint\0setGrade\0\0setAddScore\0"
    "setAddCombo\0setEndCombo\0setHitted\0"
    "checkCollision\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HitPoint[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       4,    0,   50,    2, 0x06 /* Public */,
       5,    0,   51,    2, 0x06 /* Public */,
       6,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void HitPoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HitPoint *_t = static_cast<HitPoint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGrade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setAddScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setAddCombo(); break;
        case 3: _t->setEndCombo(); break;
        case 4: _t->setHitted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->checkCollision((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HitPoint::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HitPoint::setGrade)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HitPoint::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HitPoint::setAddScore)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HitPoint::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HitPoint::setAddCombo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (HitPoint::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HitPoint::setEndCombo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (HitPoint::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HitPoint::setHitted)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject HitPoint::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HitPoint.data,
      qt_meta_data_HitPoint,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HitPoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HitPoint::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HitPoint.stringdata0))
        return static_cast<void*>(const_cast< HitPoint*>(this));
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(const_cast< HitPoint*>(this));
    return QObject::qt_metacast(_clname);
}

int HitPoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HitPoint::setGrade(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HitPoint::setAddScore(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HitPoint::setAddCombo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void HitPoint::setEndCombo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void HitPoint::setHitted(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
