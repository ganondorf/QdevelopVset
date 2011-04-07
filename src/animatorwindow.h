
#ifndef ANIMATORWINDOW_H
#define ANIMATORWINDOW_H

#include <QDockWidget>
#include "ui_animatorwindow.h"

class AnimatorWindow : public QDockWidget, public Ui::AnimatorWindow
{
    Q_OBJECT

public:
    explicit AnimatorWindow(QWidget *parent = 0);
    ~AnimatorWindow();

private:
    Ui::AnimatorWindow *ui;
};

#endif // ANIMATORWINDOW_H
