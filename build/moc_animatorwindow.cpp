/****************************************************************************
** Meta object code from reading C++ file 'animatorwindow.h'
**
** Created: Sat Apr 9 16:06:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/animatorwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animatorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnimatorWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_AnimatorWindow[] = {
    "AnimatorWindow\0"
};

const QMetaObject AnimatorWindow::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_AnimatorWindow,
      qt_meta_data_AnimatorWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnimatorWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnimatorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnimatorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimatorWindow))
        return static_cast<void*>(const_cast< AnimatorWindow*>(this));
    if (!strcmp(_clname, "Ui::AnimatorWindow"))
        return static_cast< Ui::AnimatorWindow*>(const_cast< AnimatorWindow*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int AnimatorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
