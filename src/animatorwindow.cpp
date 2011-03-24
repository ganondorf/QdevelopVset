#include "animatorwindow.h"

AnimatorWindow::AnimatorWindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::AnimatorWindow)
{
    ui->setupUi(this);
}

AnimatorWindow::~AnimatorWindow()
{
    delete ui;
}
