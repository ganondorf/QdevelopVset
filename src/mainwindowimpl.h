/**
 * Cesar Chacon
 * Carlos Gonzalez
 * David Archer
 */
#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QTreeWidgetItem>
#include "ui_mainwindow.h"
#include "Workspace.h"
#include "animatorwindow.h"
#include "ui_animatorwindow.h"
#include <stdlib.h>
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	Workspace vswork;//default workspace
	QTreeWidgetItem *vel1Item;
        enum buttonActions{OpenDialog, SaveDialog, OpenAnimatorDialog, Slice, Zoom, Pan};
	void setCurrentPointer(int currentAction);
        void setBINfile(QString currentFile){binFile = currentFile;}//set the name of the bin file to save
        bool getBINfile(){return (binFile!= NULL);}//Check if the current project is saved
        int getEnumVal(buttonActions action);

private:
        QString binFile;

private slots:
	void openSelect();
        void saveFile();
        void OpenAnimatorWindow();
	void refreshTreeItems();
        void openVel(QTreeWidgetItem*);
        void doSlice();
        void doZoom();
        void doPan();
	
};
#endif




