/****************************************************************************
** Meta object code from reading C++ file 'PlayEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GamePlayScene/PlayEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlayEngine_t {
    QByteArrayData data[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayEngine_t qt_meta_stringdata_PlayEngine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlayEngine"
QT_MOC_LITERAL(1, 11, 6), // "hitKey"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "doResult"
QT_MOC_LITERAL(4, 28, 11), // "spawnDongKa"
QT_MOC_LITERAL(5, 40, 4), // "type"
QT_MOC_LITERAL(6, 45, 10), // "spawnGrade"
QT_MOC_LITERAL(7, 56, 5), // "grade"
QT_MOC_LITERAL(8, 62, 14), // "moveTimerPause"
QT_MOC_LITERAL(9, 77, 15), // "moveTimerResume"
QT_MOC_LITERAL(10, 93, 7), // "endGame"
QT_MOC_LITERAL(11, 101, 10), // "disableEsc"
QT_MOC_LITERAL(12, 112, 9), // "playMusic"
QT_MOC_LITERAL(13, 122, 12) // "closeEscMenu"

    },
    "PlayEngine\0hitKey\0\0doResult\0spawnDongKa\0"
    "type\0spawnGrade\0grade\0moveTimerPause\0"
    "moveTimerResume\0endGame\0disableEsc\0"
    "playMusic\0closeEscMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   68,    2, 0x0a /* Public */,
       6,    1,   71,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    0,   76,    2, 0x0a /* Public */,
      11,    0,   77,    2, 0x0a /* Public */,
      12,    0,   78,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayEngine *_t = static_cast<PlayEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hitKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->doResult(); break;
        case 2: _t->spawnDongKa((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->spawnGrade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->moveTimerPause(); break;
        case 5: _t->moveTimerResume(); break;
        case 6: _t->endGame(); break;
        case 7: _t->disableEsc(); break;
        case 8: _t->playMusic(); break;
        case 9: _t->closeEscMenu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlayEngine::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayEngine::hitKey)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlayEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayEngine::doResult)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PlayEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlayEngine.data,
      qt_meta_data_PlayEngine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlayEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlayEngine.stringdata0))
        return static_cast<void*>(const_cast< PlayEngine*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< PlayEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int PlayEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PlayEngine::hitKey(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayEngine::doResult()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
