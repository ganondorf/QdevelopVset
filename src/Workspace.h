/*
 * Workspace.h
 *
 *      Author: Joel Quintana
 *
 *      WORKSPACE
 *      This class contains all the information relevant to a Visualization Project
 *      Contains:
 *      - keeps track of added experiments
 *      - keeps track of visualizations opened
 *      - keeps track of synchronization groups
 *      - has the ability to save to and load from disk
 *      - launches the animation interface
 *
 *		Last update: 11:13 am / 25 / March / 2011
 */

#ifndef WORKSPACE_H_
#define WORKSPACE_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "ExperimentManager.h"
#include "Visualization.h"
#include <QTreeWidget>
using namespace std;

class Workspace
{
	private:
		//Attributes
		string name_;
		vector<Visualization*> list_of_visualizations_;
		ExperimentManager expMan;

	public:
		//Constructors and destructors
		Workspace();
		virtual ~Workspace();

		//Accessors and mutators
		string getName() const;
		void setName(string name_);
		void setTree(QTreeWidget *TreeWidget);
		vector<Visualization*> getList_of_visualizations() const;

		//Experiment Methods
		void add_experiment(string expstring);
		vector<Experiment*> getList_of_experiments() const;

		//Manage visualizations
		void add_visualization(Visualization*);
		void remove_visualization(int);
		void remove_visualization(Visualization*);



		//TO-DO
		void animate(); //Start the animation interface
		void create_sync_group(); //Handle synchronizations
		void sync_all(); //Synchronize all models
		void save_workspace(string); //Save workspace to the disk
		void load_workspace(string); //Loade workspace from disk
};

#endif /* WORKSPACE_H_ */
