/**
 * Cesar Chacon
 * Carlos Gonzalez
 * David Archer
 */
#include <QApplication>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	//Creates the Main window
	MainWindowImpl win;
	//display the main window
	win.show(); 
	//connect the signal to close the window
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
