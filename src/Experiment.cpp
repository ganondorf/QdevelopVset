/* 
 * File:   Experiment.cpp
 * Author: ahlatimer
 * 
 * Created on March 4, 2011, 8:07 PM
 * 
 * Experiment:
 *   -Parses the XML file and stores the necessary data
 *     -project_name, project_path, iterations, date, nx, ny, nz, h, and a vector of shotpoints
 *   -Obtains the directory paths to the models, parses and stores the model files
 *   Methods in Experiment:
 *     - bool open_model (Model model)
 *     - bool close_model(Model model)
 *     - void read_xml() (seen in constructor)
 *        - void set_shot_points() (seen in read_xml())
 *     - void parse_paths() (seen in constructor)
 *        - int getdir(string path, vector<string>&files) (seen in parse_paths())
 *        - void create_models(vector<string> files, int model_type) (seen in parse_paths())
 *           - string coverage_path(), string time_path(), string velocity_path, string perturbation_path (seen in create_models())
 *  
 *  3/10/2011 -- updated set_shot_points() method (for loop "heading")
 */

/*
    vector<ShotPoint> shot_points;
 */

#include "Experiment.h"


const int COVERAGE_MODEL = 1;
const int VELOCITY_MODEL = 2;
const int TIME_MODEL = 3;
const int PERTURBATION_MODEL = 4;

//Constructor
Experiment::Experiment(string f) {
    xml_filename = f;
    read_xml();
    parse_paths();
}

Experiment::~Experiment() {
}


bool Experiment::open_model(Model model) {

    return true;
}

bool Experiment::close_model(Model model) {
    return true;
}


//Uses XML parser(pugixml) to obtain data from XML file
//Obtains and stores project_name, project_path, iterations, date, and nx, ny, nz, h, and the shotpoints (sp)
void Experiment::read_xml() {
    pugi::xml_document doc;
    string xmlstr = xml_filename;
    const char *xmlname = xmlstr.c_str();

    /* TODO: Better error handling. Should throw an exception, etc. */
    if (!doc.load_file(xmlname)) return;

    pugi::xml_node workspace = doc.child("seismicTomoWU").child("workspace");
    project_name = workspace.child_value("projectname");
    project_path = workspace.child_value("projectpath");
    iterations   = atoi(workspace.child_value("iterations"));
    date         = workspace.child_value("date");

    pugi::xml_node punch = workspace.child("punch");
    nx = atoi(punch.child_value("nx"));
    ny = atoi(punch.child_value("ny"));
    nz = atoi(punch.child_value("nz"));
    h  = atoi(punch.child_value("h"));

    set_shot_points(punch);
}

//Takes a node and iterates through its children to obtain each shotpoint
//Stores them in vector<ShotPoint> shot_points (see header file)
void Experiment::set_shot_points(pugi::xml_node node) {

    for(pugi::xml_node sp_node = node.child("sp"); sp_node; sp_node = sp_node.next_sibling()) {
        ShotPoint sp(sp_node);
        shot_points.push_back(sp);
    }

}

//Gets the paths to the model files, stores the model files into its respective vector
void Experiment::parse_paths() {
    vector<string> coverage_files;
    vector<string> time_files;
    vector<string> velocity_files;
    vector<string> perturbation_files;

    getdir(coverage_path(), coverage_files);
    getdir(time_path(), time_files);
    getdir(velocity_path(), velocity_files);
    getdir(perturbation_path(), perturbation_files);
    
    create_models(coverage_files, COVERAGE_MODEL);
    /*
    create_models(velocity_files, VELOCITY_MODEL);
    create_models(time_files, TIME_MODEL);
    create_models(perturbation_files, PERTURBATION_MODEL);
*/
}

string Experiment::coverage_path() {
  return project_path + "Model/RayCov";
}

string Experiment::time_path() {
  return project_path + "Model/Time";
}

string Experiment::velocity_path() {
  return project_path + "Model/Vel";
}

string Experiment::perturbation_path() {
  return project_path + "Model/VelPer";
}

//Takes in a path to the directory, stores the files in a vector<string>
int Experiment::getdir(string path, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(path.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << path << endl;
        return errno;
    }
    int count = 0;
    while ((dirp = readdir(dp)) != NULL) {
      if(count>1)
        files.push_back(string(dirp->d_name));

      count++;
    }
    closedir(dp);
    return 0;
}


//From the model files, this method creates and stores the models in a vector<Model>
void Experiment::create_models(vector<string> files, int model_type) {
	vector<Model> models;
    for(unsigned int i = 0; i < files.size()-1; i++) {
        Model model;
        switch(model_type) {
            case COVERAGE_MODEL:
                model = CoverageModel(files.at(i), this);
                break;
            case VELOCITY_MODEL:
                model = VelocityModel(files.at(i), this);
                break;
            case TIME_MODEL:
                model = TimeModel(files.at(i), this);
                break;
            case PERTURBATION_MODEL:
                model = PerturbationModel(files.at(i), this);
                break;
        }
        models.push_back(model);
    }

}

string Experiment::getprojectName() {
    return project_name;
}

vector<Model> Experiment::getModels(){
   	return models;
   	
  	}
