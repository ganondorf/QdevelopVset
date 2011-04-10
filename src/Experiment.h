/* 
 * File:   Experiment.h
 * Author: Andrew Lahtimer, Cesar Chacon, Alexandria Ogrey
 *
 * Created on March 4, 2011, 8:07 PM
 */

#ifndef EXPERIMENT_H
#define	EXPERIMENT_H

#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <map>
#include "pugixml.hpp"
#include <stdlib.h>
#include "ShotPoint.h"
#include <string>
#include <sys/types.h>
#include <vector>
#include "Model.h"

using namespace std;

class Model;
class Experiment {
    friend class Model;
public:
    /* METHODS */
    Experiment(string filename);
    virtual ~Experiment();
    bool close_model(Model model);
    bool open_model(Model model);
    string getprojectName();
    vector<Model> getModels();
    /* END METHODS*/
    
    /* ATTRIBUTES */
    vector<Model> open_models;
    vector<Model> models;

    string project_name;
    string project_path;
    string xml_filename;
    int iterations;
    /* TODO: Make this an actual date object. */
    string date;
    int nx;
    int ny;
    int nz;
    float h;
    vector<ShotPoint> shot_points;
    /* END ATTRIBUTES */
private:
    /* METHODS */
    void read_xml();
    void parse_paths();
    void create_models(vector<string> files, int model_type);
    void set_shot_points(pugi::xml_node node);
    
    string coverage_path();
    string time_path();
    string velocity_path();
    string perturbation_path();
    string smoother1_path();
    string smoother2_path();
   /* string finalfiles_path();*/
    
    
    int getdir(string path, vector<string> &files);
    /* METHODS END */

    /* ATTRIBUTES */

    /* ATTRIBUTES END */
};



#endif	/* EXPERIMENT_H */

