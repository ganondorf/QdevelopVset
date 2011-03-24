/* 
 * File:   VelocityModel.cpp
 * Author: ahlatimer
 * 
 * Created on March 4, 2011, 7:51 PM
 * VelocityModel:
 *    - Stores the raw data of the actual model
 *    Methods of VelocityModel:
 *    - int read ()
 */

#include "Model.h"

VelocityModel::VelocityModel(string p, Experiment *exp) : Model(p, exp) {
}

VelocityModel::~VelocityModel() {
}
//Places the binary file into the vector<float> floats
int VelocityModel::read() {
    ifstream file(path.c_str(), ios::in|ios::binary);
    int float_length = sizeof(float);
    char buff[128];
    vector<float> floats;

    if(file.is_open()) {
        while(!file.eof()) {
            file.read(buff, float_length);
            floats.push_back(atof(buff));
        }
        file.close();
    } else {
        return -1;
    }

    return 0;
}