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

      //connect the signal related to the top bars
      connect(actionOpen, SIGNAL(triggered()), this, SLOT(openSelect()));
      connect(actionOpen_2, SIGNAL(clicked()), this, SLOT(openSelect()));
      connect(actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
      connect(actionSave_1, SIGNAL(triggered()), this, SLOT(saveFile()));
      connect(actionSave_2, SIGNAL(clicked()), this, SLOT(saveFile()));
      connect(actionAnimator, SIGNAL(clicked()), this, SLOT(OpenAnimatorWindow()));
      connect(actionZoom_1, SIGNAL(clicked()), this, SLOT(doZoom()));
      connect(actionZoom, SIGNAL(triggered()), this, SLOT(doZoom()));
      connect(actionSlice, SIGNAL(triggered()), this, SLOT(doSlice()));
      connect(actionSlice_1, SIGNAL(clicked()), this, SLOT(doSlice()));
      connect(actionPan, SIGNAL(triggered()), this, SLOT(doPan()));
      connect(actionRotate, SIGNAL(triggered()), this, SLOT(doRotate()));

      //connect vel
      connect(treeWidget, SIGNAL(itemDoubleClicked ( QTreeWidgetItem*, int ) ), this, SLOT(openVel()));

      //vswork connect widgets to references
      vswork.setTree(treeWidget);

      //Initialize custom cursor pointers
      QBitmap zoomB("zoom.png");
      QBitmap rotateB("rotate.jpeg");
      QBitmap sliceB("slice.png");
      zoomCursor = QCursor(zoomB, -1, -1);
      rotateCursor = QCursor(rotateB, -1, -1);
      sliceCursor = QCursor(sliceB, -1, -1);

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

//Check for key events
void MainWindowImpl::keyPressEvent( QKeyEvent * event ){
    switch ( event->key() ){

        case Qt::Key_Escape:

            setCurrentPointer(-1);
            break;
        default:break;

    }
}

//Stop current action
void MainWindowImpl::stopAction(int action){

    switch(action){
    case Slice:
        break;
    case Zoom:
        break;
    case Pan:
        break;
    case Rotate:
        break;

    }
}

//Change current Cursor POinter according to the current action
void MainWindowImpl::setCurrentPointer(int nextAction){

    QCursor cursor = NULL;
    if(currentAction == nextAction){
        nextAction = -1;
        stopAction(currentAction);
    }
    switch(nextAction){
    case Slice:
        cursor = sliceCursor;
        break;
    case Zoom:
        cursor = zoomCursor;
        break;
    case Pan:
        cursor = Qt::OpenHandCursor;
        break;
    case Rotate:
        cursor = rotateCursor;
        break;
    default:
        cursor = Qt::ArrowCursor;
    }
    setCursor(cursor);
    currentAction = nextAction;
}

void MainWindowImpl::doSlice(){
    //Slicing calls here
    setCurrentPointer(Slice);
}

void MainWindowImpl::doZoom(){
    //Zoom calls here
    setCurrentPointer(Zoom);
}

void MainWindowImpl::doPan(){
    //Pan calls here
    setCurrentPointer(Pan);
}

void MainWindowImpl::doRotate(){
    //Rotate calls here
    setCurrentPointer(Rotate);
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
