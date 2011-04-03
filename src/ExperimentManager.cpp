/**
 * Cesar Chacon
 */
#include "ExperimentManager.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QTreeWidget>

 ExperimentManager::ExperimentManager()
{
    	
   	}
   	
//Add experiment to the list
void ExperimentManager::add(string expStr) {

 Experiment new_experiment = Experiment(expStr);
 //list_of_experiments_.push_back(&new_experiment);
/* 
 //create the root node    
    QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
    // item->setText(0, tr("Potrillo"));
    QString projectName = QString::fromStdString(new_experiment.getprojectName());
    item->setText(0, projectName);
  */  
    
  // models =  new_experiment.getModels();
   //unsigned int i;
   //for(i=0;i<models.size();i++){
   	//printf("%s", models[i].getName());
   	
  	//}
//debugging selected file String URL 
/*
 QMessageBox msgBox;
 QString qstr = QString::fromStdString(new_experiment.getprojectName());
 msgBox.setText(qstr);
 msgBox.exec();
 */
 
/**
  *     
    Experiment *temp;
    temp = new Experiment(expStr);
         
    models =temp->getModels();
	int i ;  
    for(i=0;i<models.size();i++){
    	printf("%s",models[i].getName());
    	
    	
   	}
   	
**/
}

 

//Set the Treewidget reference
void ExperimentManager::setTreeWidget(QTreeWidget *TreeWidget){
	treeWidget = TreeWidget;
	
}


//Print list of experiments for debugging purposes
void ExperimentManager::print_list_of_experiments()
{
	for(int i = 0; i < list_of_experiments_.size(); i++)
	{
		cout << "Experiment at index [" << i << "]: " << (*list_of_experiments_[i]).getprojectName() << endl;
	}
}

//Remove an experiment from the workspace
//The pointer to the experiment to be removed must be specified
void ExperimentManager::remove_experiment(Experiment* to_be_removed)
{
	//get index of experiment
	int index = -1;
	for(int i = 0; i < list_of_experiments_.size(); i++)
	{
		if(list_of_experiments_[i] == to_be_removed)
		{
			index = i;
			break;
		}
	}
	list_of_experiments_.erase(list_of_experiments_.begin() + index);
}
//Remove an experiment from the workspace
//The index of the experiment to be removed must be specified
void ExperimentManager::remove_experiment(int index)
{
	list_of_experiments_.erase(list_of_experiments_.begin() + index);
}


//Return the list of experiments added to the workspace
vector<Experiment*> ExperimentManager::getList_of_experiments() const
{
    return list_of_experiments_;
}


//destructor
ExperimentManager::~ExperimentManager() {

}

