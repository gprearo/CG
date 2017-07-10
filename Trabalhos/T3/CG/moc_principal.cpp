/****************************************************************************
** Meta object code from reading C++ file 'principal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "principal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'principal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Principal_t {
    QByteArrayData data[13];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Principal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Principal_t qt_meta_stringdata_Principal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Principal"
QT_MOC_LITERAL(1, 10, 31), // "on_actionCor_da_linha_triggered"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 31), // "on_actionCor_de_fundo_triggered"
QT_MOC_LITERAL(4, 75, 25), // "on_checkBox_Phong_toggled"
QT_MOC_LITERAL(5, 101, 7), // "checked"
QT_MOC_LITERAL(6, 109, 34), // "on_horizontalSlider_a_valueCh..."
QT_MOC_LITERAL(7, 144, 5), // "value"
QT_MOC_LITERAL(8, 150, 34), // "on_horizontalSlider_b_valueCh..."
QT_MOC_LITERAL(9, 185, 34), // "on_horizontalSlider_c_valueCh..."
QT_MOC_LITERAL(10, 220, 26), // "on_radioButton_CMY_toggled"
QT_MOC_LITERAL(11, 247, 26), // "on_radioButton_RGB_toggled"
QT_MOC_LITERAL(12, 274, 26) // "on_radioButton_HSV_toggled"

    },
    "Principal\0on_actionCor_da_linha_triggered\0"
    "\0on_actionCor_de_fundo_triggered\0"
    "on_checkBox_Phong_toggled\0checked\0"
    "on_horizontalSlider_a_valueChanged\0"
    "value\0on_horizontalSlider_b_valueChanged\0"
    "on_horizontalSlider_c_valueChanged\0"
    "on_radioButton_CMY_toggled\0"
    "on_radioButton_RGB_toggled\0"
    "on_radioButton_HSV_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Principal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       6,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void Principal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Principal *_t = static_cast<Principal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionCor_da_linha_triggered(); break;
        case 1: _t->on_actionCor_de_fundo_triggered(); break;
        case 2: _t->on_checkBox_Phong_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_a_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_horizontalSlider_b_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_horizontalSlider_c_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_radioButton_CMY_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_radioButton_RGB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_radioButton_HSV_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Principal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Principal.data,
      qt_meta_data_Principal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Principal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Principal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Principal.stringdata0))
        return static_cast<void*>(const_cast< Principal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Principal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
