/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 7 12:55:35 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_3;
    QToolButton *toolButton_5;
    QToolButton *toolButton_8;
    QToolButton *toolButton_6;
    QToolButton *toolButton_9;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuSubwindows;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Video-Icon6-150x150.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon);

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_7 = new QToolButton(centralwidget);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon1);

        horizontalLayout_4->addWidget(toolButton_7);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("snap.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);

        horizontalLayout_4->addWidget(toolButton_3);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("slice.gif"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon3);

        horizontalLayout_4->addWidget(toolButton_5);

        toolButton_8 = new QToolButton(centralwidget);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("help.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon4);

        horizontalLayout_4->addWidget(toolButton_8);

        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("rl.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);

        horizontalLayout_4->addWidget(toolButton_6);

        toolButton_9 = new QToolButton(centralwidget);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("rr.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon6);

        horizontalLayout_4->addWidget(toolButton_9);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);

        horizontalLayout_4->addWidget(toolButton);

        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon8);

        horizontalLayout_4->addWidget(toolButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_4->setStretch(9, 1);

        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalFrame = new QFrame(centralwidget);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(verticalFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setMinimumSize(QSize(0, 309));
        treeWidget = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 171, 309));
        treeWidget->setAutoExpandDelay(-1);

        verticalLayout->addWidget(frame);


        verticalLayout_3->addWidget(verticalFrame);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 10);
        verticalLayout_3->setStretch(3, 2);
        verticalLayout_3->setStretch(4, 3);

        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAutoFillBackground(false);

        verticalLayout_2->addWidget(label_2);

        frame1 = new QFrame(centralwidget);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setAutoFillBackground(false);
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        progressBar_2 = new QProgressBar(centralwidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);

        horizontalLayout->addWidget(progressBar_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 12);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuSubwindows = new QMenu(menubar);
        menuSubwindows->setObjectName(QString::fromUtf8("menuSubwindows"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuSubwindows->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VSeT Cluster App Software Engineering 4311", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("MainWindow", "Animate", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("MainWindow", "snapshot", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("MainWindow", "Slice", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("MainWindow", "Rotateleft", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("MainWindow", "Rotateright", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "open", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MainWindow", "save", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "ExperimentsWindow", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Filter By: ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Visualize", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "XML info", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Visualization Area", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuSubwindows->setTitle(QApplication::translate("MainWindow", "Subwindows", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
