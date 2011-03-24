/**
 * Cesar Chacon
 */
#include "ExperimentManager.h"
#include <string>
#include <QMessageBox>
#include <QString>

 ExperimentManager::ExperimentManager()
{
    	
   	}
   	
   	//Add experiment to the list
void ExperimentManager::add(string expStr,  QTreeWidget *treeWidget) {

  //vector<Model> models;

   // experimentList.push_back(Experiment(expStr));
     
   QMessageBox msgBox;
   QString qstr = QString::fromStdString(expStr);
 msgBox.setText(qstr);
 msgBox.exec();
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

   //Remove experiment from the list
void ExperimentManager::remove(string expStr, QTreeWidget *treeWidget) {
			//vector name:  experimentList
			  int i;
		
		int removei;
		//get the index where the experiment is
		
		for(i=0 ;i<experimentList.size(); i++){
		   if (experimentList[i].getprojectName() == expStr){
			removei = i;
			
		   }
		}
		  
		experimentList.erase(experimentList.begin()+removei);
		
		 //
		  //cout << "myvector contains:";
		  //for (i=0; i<myvector.size(); i++)
		    //cout << " " << myvector[i];
		  //cout << endl;
		
    

}


//destructor
ExperimentManager::~ExperimentManager() {

}

