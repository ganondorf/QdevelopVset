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
#include "Experiment.h"
#include "Visualization.h"

using namespace std;

class Workspace
{
	private:
		//Attributes
		string name_;
		vector<Experiment*> list_of_experiments_;
		vector<Visualization*> list_of_visualizations_;

	public:
		//Constructors and destructors
		Workspace();
		virtual ~Workspace();

		//Accessors and mutators
		string getName() const;
		void setName(string name_);

		vector<Experiment*> getList_of_experiments() const;
		vector<Visualization*> getList_of_visualizations() const;

		//Methods
		//Manage experiments
		void add_experiment(Experiment*);
		void remove_experiment(int);
		void remove_experiment(Experiment*);
		void print_list_of_experiments();

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
