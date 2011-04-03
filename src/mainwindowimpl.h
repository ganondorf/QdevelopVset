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
#include <stdlib.h>
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	Workspace vswork;//default workspace
	 QTreeWidgetItem *vel1Item;
private slots:
		void openSelect();
		void refreshTreeItems();
	    void openVel();
};
#endif




