/**
 * Cesar Chacon
 */
#include "ExperimentManager.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>

 ExperimentManager::ExperimentManager()
{
    	
   	}
   	
//Add experiment to the list
void ExperimentManager::add(string expStr) {
 unsigned int i;
  vector<Model> models;

 Experiment new_experiment = Experiment(expStr);
 //list_of_experiments_.push_back(&new_experiment);

  models= new_experiment.getModels();
 //DEBUGGING LOOP
   for(i=0;i<models.size();i++){
   cout<<"model "<<i<<" name"<<models[i].getName()<<endl;
   	
     }

 //create the root node    
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    QString projectName = QString::fromStdString(new_experiment.getprojectName());
    root->setText(0, projectName);
    
    //subfolder items
    QTreeWidgetItem *covItem = new QTreeWidgetItem(root);
     covItem->setText(0, QObject::tr("Coverage"));
     
    QTreeWidgetItem *timeItem = new QTreeWidgetItem(root);
     timeItem->setText(0, QObject::tr("Time"));
     
    QTreeWidgetItem *tomoItem = new QTreeWidgetItem(root);
     tomoItem->setText(0, QObject::tr("Smoother 1"));
     
    QTreeWidgetItem *smItem = new QTreeWidgetItem(root);
     smItem->setText(0, QObject::tr("Smoother 2"));
     
    QTreeWidgetItem *duItem = new QTreeWidgetItem(root);
     duItem->setText(0, QObject::tr("Du"));   
  
    QTreeWidgetItem *finalItem = new QTreeWidgetItem(root);
     finalItem->setText(0, QObject::tr("Final Models")); 
     
     //loop to add all the models in the list
     //and add all the nodes to the subfolders
    string iter, stp;
     for(i=0;i<models.size();i++){
     	
     	if(models[i].getName()=="icov"){
     	 QTreeWidgetItem *covchild = new QTreeWidgetItem(covItem);
	     covchild->setText(0, QObject::tr("Coverage"));
	     iter = models[i].getIteration();
		 covchild->setText(1, QObject::tr(iter));
		 stp= (char)models[i].getStep()
	     covchild->setText(2, QObject::tr());
     		     		
    	}else if(models[i].getName()=="vel"){
    		
    		
   		}else if(models[i].getName()=="time"){
   			
  		}else if(models[i].getName()=="dusum"){
  			
 			}
     	
    	}
     
     


 
   //for(i=0;i<models.size();i++){
        //printf("%s", models[i].getName());
   	
        //}
treeWidget->resizeColumnToContents(1);
treeWidget->resizeColumnToContents(2);
treeWidget->resizeColumnToContents(3);

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

