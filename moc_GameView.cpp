/****************************************************************************
** Meta object code from reading C++ file 'GameView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameView_t {
    QByteArrayData data[14];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameView_t qt_meta_stringdata_GameView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameView"
QT_MOC_LITERAL(1, 9, 11), // "setMainMenu"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "backToMainMenu"
QT_MOC_LITERAL(4, 37, 11), // "setSongMenu"
QT_MOC_LITERAL(5, 49, 14), // "setResultScene"
QT_MOC_LITERAL(6, 64, 14), // "GamePlayResult"
QT_MOC_LITERAL(7, 79, 14), // "gamePlayResult"
QT_MOC_LITERAL(8, 94, 12), // "setPlayScene"
QT_MOC_LITERAL(9, 107, 6), // "string"
QT_MOC_LITERAL(10, 114, 7), // "oveName"
QT_MOC_LITERAL(11, 122, 13), // "setLastPlayed"
QT_MOC_LITERAL(12, 136, 10), // "exitResult"
QT_MOC_LITERAL(13, 147, 8) // "exitPlay"

    },
    "GameView\0setMainMenu\0\0backToMainMenu\0"
    "setSongMenu\0setResultScene\0GamePlayResult\0"
    "gamePlayResult\0setPlayScene\0string\0"
    "oveName\0setLastPlayed\0exitResult\0"
    "exitPlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,
      12,    0,   66,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameView *_t = static_cast<GameView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setMainMenu(); break;
        case 1: _t->backToMainMenu(); break;
        case 2: _t->setSongMenu(); break;
        case 3: _t->setResultScene((*reinterpret_cast< GamePlayResult(*)>(_a[1]))); break;
        case 4: _t->setPlayScene((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 5: _t->setLastPlayed((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 6: _t->exitResult(); break;
        case 7: _t->exitPlay(); break;
        default: ;
        }
    }
}

const QMetaObject GameView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GameView.data,
      qt_meta_data_GameView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameView.stringdata0))
        return static_cast<void*>(const_cast< GameView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
