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
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(openSelect()));
	
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
        cursor = Qt::CrossCursor;
    }
    setCursor(cursor);
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
