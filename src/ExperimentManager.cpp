/**
* Cesar Chacon
*/
#include "ExperimentManager.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QTreeWidget>
#include <algorithm>

ExperimentManager::ExperimentManager(){

}

//Add experiment to the list
void ExperimentManager::add(string expStr) {
  unsigned int i;
  vector<Model> models;

  Experiment new_experiment = Experiment(expStr);
  list_of_experiments_.push_back(&new_experiment);

  models = new_experiment.getModels();


 //DEBUGGING LOOP
  for(i=0;i<models.size();i++) {
    cout<<"model "<<i<<" name "<<models[i].getName()<<models[i].getStep() <<endl;

  }

 //create the root node    
  QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
  QString projectName = QString::fromStdString(new_experiment.getprojectName());
  root->setText(0, projectName);

    //subfolder items
  QTreeWidgetItem *covItem = new QTreeWidgetItem(root);
  covItem->setText(0, QObject::tr("Ray Coverage"));

  QTreeWidgetItem *timeItem = new QTreeWidgetItem(root);
  timeItem->setText(0, QObject::tr("Time"));

   // QTreeWidgetItem *finalItem = new QTreeWidgetItem(root);
    // finalItem->setText(0, QObject::tr("Velocity"));

  QTreeWidgetItem *duItem = new QTreeWidgetItem(root);
  duItem->setText(0, QObject::tr("Vel Perturbation"));   

  QTreeWidgetItem *s1Item = new QTreeWidgetItem(root);
  s1Item->setText(0, QObject::tr("Smoother 1"));

  QTreeWidgetItem *s2Item = new QTreeWidgetItem(root);
  s2Item->setText(0, QObject::tr("Smoother 2"));



     //loop to add all the models in the list
     //and add all the nodes to the subfolders
  QString iter, stp;

  for(i=0;i<models.size();i++){

    if(models[i].getName()=="icov") {
      QTreeWidgetItem *covchild = new QTreeWidgetItem(covItem);
      covchild->setText(0, QObject::tr("Coverage"));
      iter =QString::fromStdString(convertInt(models[i].getIteration()));
      covchild->setText(1, iter);
      stp= QString::fromStdString(convertInt(models[i].getStep()));
      covchild->setText(2, stp);
    } else if(models[i].getName()=="time") {
      QTreeWidgetItem *timechild = new QTreeWidgetItem(timeItem);
      timechild->setText(0, QObject::tr("Time"));
      iter =QString::fromStdString(convertInt(models[i].getIteration()));
      timechild->setText(1, iter);
      stp= QString::fromStdString(convertInt(models[i].getStep()));
      timechild->setText(2, stp);
    } else if(models[i].getName()=="dusum") {
      QTreeWidgetItem *duchild = new QTreeWidgetItem(duItem);
      duchild->setText(0, QObject::tr("Vel Perturbation"));
      iter =QString::fromStdString(convertInt(models[i].getIteration()));
      duchild->setText(1, iter);
      stp= QString::fromStdString(convertInt(models[i].getStep()));
      duchild->setText(2, stp);

    } else if(models[i].getName()=="velaa") {
      QTreeWidgetItem *s1child = new QTreeWidgetItem(s1Item);
      s1child->setText(0, QObject::tr("Smoother 1"));
      iter =QString::fromStdString(convertInt(models[i].getIteration()));
      s1child->setText(1, iter);
      stp= QString::fromStdString(convertInt(models[i].getStep()));
      s1child->setText(2, stp);
    } else if(models[i].getName()=="dvaa") {
      QTreeWidgetItem *s2child = new QTreeWidgetItem(s2Item);
      s2child->setText(0, QObject::tr("Smoother 2"));
      iter =QString::fromStdString(convertInt(models[i].getIteration()));
      s2child->setText(1, iter);
      stp= QString::fromStdString(convertInt(models[i].getStep()));
      s2child->setText(2, stp);

    }

  }
  
  treeWidget->setSortingEnabled(true);
  treeWidget->resizeColumnToContents(1);
  treeWidget->resizeColumnToContents(2);
  treeWidget->resizeColumnToContents(3);
  treeWidget->sortItems(1, Qt::AscendingOrder);
  treeWidget->sortItems(2, Qt::AscendingOrder);
  treeWidget->sortItems(3, Qt::AscendingOrder);

}



//Set the Treewidget reference
void ExperimentManager::setTreeWidget(QTreeWidget *TreeWidget){
  treeWidget = TreeWidget;

}


//Print list of experiments for debugging purposes
void ExperimentManager::print_list_of_experiments()
{
  for(unsigned int i = 0; i < list_of_experiments_.size(); i++)
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
  for(unsigned int i = 0; i < list_of_experiments_.size(); i++)
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

string ExperimentManager::convertInt(int number)
{
  if (number == 0)
    return "0";
  string temp="";
  string returnvalue="";
  while (number>0)
  {
    temp+=number%10+48;
    number/=10;
  }
  for (unsigned int i=0;i<temp.length();i++)
    returnvalue+=temp[temp.length()-i-1];
  return returnvalue;
}

//destructor
ExperimentManager::~ExperimentManager() {

}