/********************************************************************************
** Form generated from reading UI file 'animatorwindow.ui'
**
** Created: Mon Apr 11 20:08:30 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATORWINDOW_H
#define UI_ANIMATORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimatorWindow
{
public:
    QWidget *dockWidgetContents;
    QComboBox *comboBox;
    QFrame *frame;
    QToolButton *toolButton;
    QToolButton *actionStop;
    QToolButton *actionFFW;
    QToolButton *actionPlay;
    QToolButton *actionRew;
    QLabel *label;
    QPushButton *actionSave;
    QPushButton *actionAnimation;
    QFrame *frame_2;
    QRadioButton *actionSpeedAnimation;
    QRadioButton *actionSpeedAnimation_1;
    QRadioButton *actionSpeedAnimation_2;
    QRadioButton *actionSpeedAnimation_3;
    QLabel *label_2;
    QListView *listView;
    QScrollBar *verticalScrollBar;

    void setupUi(QDockWidget *AnimatorWindow)
    {
        if (AnimatorWindow->objectName().isEmpty())
            AnimatorWindow->setObjectName(QString::fromUtf8("AnimatorWindow"));
        AnimatorWindow->setWindowModality(Qt::NonModal);
        AnimatorWindow->resize(436, 462);
        AnimatorWindow->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        comboBox = new QComboBox(dockWidgetContents);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 30, 85, 27));
        frame = new QFrame(dockWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 70, 141, 101));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(dockWidgetContents);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(340, 180, 24, 25));
        actionStop = new QToolButton(dockWidgetContents);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setGeometry(QRect(310, 180, 24, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../ui/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon);
        actionFFW = new QToolButton(dockWidgetContents);
        actionFFW->setObjectName(QString::fromUtf8("actionFFW"));
        actionFFW->setGeometry(QRect(280, 180, 24, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../ui/stepfw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFFW->setIcon(icon1);
        actionPlay = new QToolButton(dockWidgetContents);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionPlay->setGeometry(QRect(250, 180, 24, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../ui/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        actionRew = new QToolButton(dockWidgetContents);
        actionRew->setObjectName(QString::fromUtf8("actionRew"));
        actionRew->setGeometry(QRect(220, 180, 24, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../ui/stepbw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRew->setIcon(icon3);
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 67, 17));
        actionSave = new QPushButton(dockWidgetContents);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setGeometry(QRect(310, 400, 98, 27));
        actionAnimation = new QPushButton(dockWidgetContents);
        actionAnimation->setObjectName(QString::fromUtf8("actionAnimation"));
        actionAnimation->setGeometry(QRect(20, 400, 141, 27));
        frame_2 = new QFrame(dockWidgetContents);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 290, 131, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        actionSpeedAnimation = new QRadioButton(dockWidgetContents);
        actionSpeedAnimation->setObjectName(QString::fromUtf8("actionSpeedAnimation"));
        actionSpeedAnimation->setGeometry(QRect(180, 262, 71, 20));
        actionSpeedAnimation_1 = new QRadioButton(dockWidgetContents);
        actionSpeedAnimation_1->setObjectName(QString::fromUtf8("actionSpeedAnimation_1"));
        actionSpeedAnimation_1->setGeometry(QRect(280, 260, 101, 16));
        actionSpeedAnimation_2 = new QRadioButton(dockWidgetContents);
        actionSpeedAnimation_2->setObjectName(QString::fromUtf8("actionSpeedAnimation_2"));
        actionSpeedAnimation_2->setGeometry(QRect(180, 290, 81, 16));
        actionSpeedAnimation_3 = new QRadioButton(dockWidgetContents);
        actionSpeedAnimation_3->setObjectName(QString::fromUtf8("actionSpeedAnimation_3"));
        actionSpeedAnimation_3->setGeometry(QRect(290, 290, 71, 22));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 240, 281, 21));
        listView = new QListView(dockWidgetContents);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(0, 70, 141, 161));
        verticalScrollBar = new QScrollBar(dockWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(130, 70, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        AnimatorWindow->setWidget(dockWidgetContents);

        retranslateUi(AnimatorWindow);

        QMetaObject::connectSlotsByName(AnimatorWindow);
    } // setupUi

    void retranslateUi(QDockWidget *AnimatorWindow)
    {
#ifndef QT_NO_ACCESSIBILITY
        AnimatorWindow->setAccessibleName(QApplication::translate("AnimatorWindow", "VSeT - Animator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        AnimatorWindow->setWindowTitle(QApplication::translate("AnimatorWindow", "VSeT - Animator", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("AnimatorWindow", "...", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("AnimatorWindow", "...", 0, QApplication::UnicodeUTF8));
        actionFFW->setText(QApplication::translate("AnimatorWindow", "...", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("AnimatorWindow", "...", 0, QApplication::UnicodeUTF8));
        actionRew->setText(QApplication::translate("AnimatorWindow", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AnimatorWindow", "Filter by", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("AnimatorWindow", "Save as", 0, QApplication::UnicodeUTF8));
        actionAnimation->setText(QApplication::translate("AnimatorWindow", "Generate Animation", 0, QApplication::UnicodeUTF8));
        actionSpeedAnimation->setText(QApplication::translate("AnimatorWindow", "Fast(3)", 0, QApplication::UnicodeUTF8));
        actionSpeedAnimation_1->setText(QApplication::translate("AnimatorWindow", "Medium(6)", 0, QApplication::UnicodeUTF8));
        actionSpeedAnimation_2->setText(QApplication::translate("AnimatorWindow", "Slow(9)", 0, QApplication::UnicodeUTF8));
        actionSpeedAnimation_3->setText(QApplication::translate("AnimatorWindow", "Other", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AnimatorWindow", "Speed of Animation ( Seconds per Model)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnimatorWindow: public Ui_AnimatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATORWINDOW_H
