/**
 * Cesar Chacon
 */
#ifndef __EXPERIMENTMANAGER_H__
#define __EXPERIMENTMANAGER_H__

#include "Experiment.h"
#include <QTreeWidget>
/**
 * Experiment Manager handles the number of Experiments running
 * and adds or removes certain experiments from the list.
 * Should be used to pupulate the experiment manager widget on the
 * GUI.
 */
class ExperimentManager{
	
public:
	/*Methods*/
    ExperimentManager();
    virtual~ExperimentManager();
    void add(string expStr, QTreeWidget *treeWidget);
    void remove(string expStr, QTreeWidget *treeWidget);
    /* Attributes*/
    vector<Experiment> experimentList;//stores the active experiments in an array

};


#endif // __EXPERIMENTMANAGER_H__
