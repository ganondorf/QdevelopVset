/**
 * Cesar Chacon
 * Carlos Gonzalez
 * David Archer
 */

#include <QFileDialog>
#include <QtGui>
#include "mainwindowimpl.h"



//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	//initialize Experiment Manager
  treeWidget->setColumnCount(3);
  QStringList header;//EP Header
  header << "Name" << "Iteration" << "Step";
  treeWidget->setHeaderLabels(header);//assign headers

  //connect the signal that opens a new file
buttonActions dialogtouse;
dialogtouse = OpenDialog;
  connect(actionOpen, SIGNAL(triggered()), this, SLOT(doAction(1)));
  connect(actionOpen_2, SIGNAL(clicked()), this, SLOT(doAction(enum buttonActions::OpenDialog)));
  connect(actionSave, SIGNAL(triggered()), this, SLOT(doAction(enum buttonActions::SaveDialog)));
  connect(actionSave_1, SIGNAL(triggered()), this, SLOT(doAction(enum buttonActions::SaveDialog)));
  connect(actionSave_2, SIGNAL(clicked()), this, SLOT(doAction(enum buttonActions::SaveDialog)));
  connect(actionAnimator, SIGNAL(clicked()), this, SLOT(doAction(enum buttonActions::OpenAnimatorDialog)));
	
  //connect vel
  connect(treeWidget, SIGNAL(itemDoubleClicked ( QTreeWidgetItem*, int ) ), this, SLOT(openVel()));
 
  //vswork connect widgets to references
  vswork.setTree(treeWidget);
 }
//

//Opens the file dialog and
//gets a string to the XML file
void MainWindowImpl::openSelect()
{	
	//Open Select XML Dialog and filter the files
	//by extension
	QString fileName;
	fileName = QFileDialog::getOpenFileName(
        this,
        "Select XML to load Experiment",
        "/",
        tr("XML (*.xml);; All files (*.*)")
	);
	
	//add experiment to the vector of experiments in the manager
	//expMan.add(fileName.toStdString(), treeWidget);

	vswork.add_experiment(fileName.toStdString());
        refreshTreeItems();
}

/**
  Store Binary file name
**/
void MainWindowImpl::saveFile(){

    if(!getBINfile()){
        QString fileName = QFileDialog::getSaveFileName(
        this,
        "Save current Experiment",
        "/",
        tr("Binary (*.VSeT)")
        );

        setBINfile(fileName);
    }
}

/**
   Call appropriate action according to the Signal
**/
void MainWindowImpl::doAction(int currentAction){

    setCurrentPointer(currentAction);

    switch (currentAction){

    case OpenDialog:
        openSelect();
        break;
    case SaveDialog:
        saveFile();
        break;
    case OpenAnimatorDialog:
        OpenAnimatorWindow();
        break;
    default: break;

    }


}

//Change current Cursor POinter according to the current action
void MainWindowImpl::setCurrentPointer(int currentAction){

    QCursor cursor = NULL;
    switch(currentAction){
    case Slice:
        cursor = Qt::CrossCursor;
        break;
    case Zoom:
        cursor = Qt::CrossCursor;
        break;
    case Pan:
        cursor = Qt::CrossCursor;
        break;
    default:
        cursor = Qt::ArrowCursor;
    }
    setCursor(cursor);
}

void MainWindowImpl::OpenAnimatorWindow(){

    AnimatorWindow * win = new AnimatorWindow();
    win->show();
    win->activateWindow();
}

void MainWindowImpl::refreshTreeItems()
{
/**
    QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
     item->setText(0, tr("Potrillo"));
     
QTreeWidgetItem *covItem = new QTreeWidgetItem(item);
     covItem->setText(0, tr("Coverage"));
     
     
	QTreeWidgetItem *cov1Item = new QTreeWidgetItem(covItem);
	     cov1Item->setText(0, tr("Coverage"));
		  cov1Item->setText(1, tr("1"));
	     cov1Item->setText(2, tr("1"));
	     
	     	QTreeWidgetItem *cov2Item = new QTreeWidgetItem(covItem);
	     cov2Item->setText(0, tr("Coverage"));
		  cov2Item->setText(1, tr("1"));
	     cov2Item->setText(2, tr("2"));
	     
	     	QTreeWidgetItem *cov3Item = new QTreeWidgetItem(covItem);
	     cov3Item->setText(0, tr("Coverage"));
		  cov3Item->setText(1, tr("1"));
	     cov3Item->setText(2, tr("3"));
 
  QTreeWidgetItem *timeItem = new QTreeWidgetItem(item);
     timeItem->setText(0, tr("Time"));
     
     QTreeWidgetItem *time1Item = new QTreeWidgetItem(timeItem);
	     time1Item->setText(0, tr("Time"));
		  time1Item->setText(1, tr("1"));
	     time1Item->setText(2, tr("1"));
	     
	     	QTreeWidgetItem *time2Item = new QTreeWidgetItem(timeItem);
	     time2Item->setText(0, tr("Time"));
		  time2Item->setText(1, tr("1"));
	     time2Item->setText(2, tr("2"));
	     
	     	QTreeWidgetItem *time3Item = new QTreeWidgetItem(timeItem);
	     time3Item->setText(0, tr("Time"));
		  time3Item->setText(1, tr("1"));
	     time3Item->setText(2, tr("3"));
     
     	
     
     
  QTreeWidgetItem *tomoItem = new QTreeWidgetItem(item);
     tomoItem->setText(0, tr("Smoother 1")); 

      QTreeWidgetItem *tomo1Item = new QTreeWidgetItem(tomoItem);
	     tomo1Item->setText(0, tr("Tomo"));
		  tomo1Item->setText(1, tr("1"));
	     tomo1Item->setText(2, tr("1"));
	     
  
  QTreeWidgetItem *smItem = new QTreeWidgetItem(item);
     smItem->setText(0, tr("Smoother 2"));
     
           QTreeWidgetItem *sm1Item = new QTreeWidgetItem(smItem);
	     sm1Item->setText(0, tr("MVAF"));
		  sm1Item->setText(1, tr("1"));
	     sm1Item->setText(2, tr("1"));
     
     
      
   QTreeWidgetItem *duItem = new QTreeWidgetItem(item);
     duItem->setText(0, tr("Du"));   
     
      QTreeWidgetItem *du1Item = new QTreeWidgetItem(duItem);
	     du1Item->setText(0, tr("Du"));
		  du1Item->setText(1, tr("1"));
	     du1Item->setText(2, tr("1"));     
     
     
 QTreeWidgetItem *velItem = new QTreeWidgetItem(item);
     velItem->setText(0, tr("Velocity"));
     
           
           vel1Item = new QTreeWidgetItem(velItem);
	     vel1Item->setText(0, tr("Vel"));
		  vel1Item->setText(1, tr("1"));
	     vel1Item->setText(2, tr("1")); 
	     
	     
    
	     

QTreeWidgetItem *finalItem = new QTreeWidgetItem(item);
     finalItem->setText(0, tr("Final Models"));  
     
           QTreeWidgetItem *covfItem = new QTreeWidgetItem(finalItem);
	     covfItem->setText(0, tr("Coverage"));
		  
     
treeWidget->resizeColumnToContents(1);
treeWidget->resizeColumnToContents(2);
treeWidget->resizeColumnToContents(3);
*/
}


//temporary function
void MainWindowImpl::openVel()
{	
	//QMessageBox msgBox;
   //QString qstr = QString::fromStdString("cute VEl graphic!");
 //msgBox.setText(qstr);
 //msgBox.exec();

system("./Model");
}
