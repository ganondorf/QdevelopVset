/* 
 * File:   Model.h
 * Author: ahlatimer
 *
 * Created on March 4, 2011, 7:50 PM
 */

#ifndef MODEL_H
#define	MODEL_H

#include <iostream>
#include <fstream>
#include <string>
#include "Experiment.h"
#include "vtkActor.h"
#include "vtkColorTransferFunction.h"
#include "vtkContourFilter.h"
#include "vtkImageReader.h"
#include "vtkOutlineFilter.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderLargeImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkStructuredPoints.h"
#include "vtkTIFFWriter.h"
#include "vtkVolume.h"
#include "vtkVolumeProperty.h"
#include "vtkVolumeRayCastCompositeFunction.h"
#include "vtkVolumeRayCastMapper.h"
#include "vtkCommand.h"

using namespace std;

class Experiment;
class Model {
    friend class Experiment;
public:
    Model();
    Model(string p, Experiment *exp);
    Model& operator=(const Model&) {};
    virtual ~Model();
    int getStep();
    int getIteration();
    string getName();
    void render();
    //virtual int draw() {};
    
    int step;
    int iteration;
    string name;
protected:
    Experiment *experiment;
   // virtual int read() {};
    string path;
private:
  void TkCheckAbort(vtkRenderWindow *renWin);
  void renderVel();
  void renderTimeWVol();
  void renderTimeWOVol();
  void renderDusum();
  void renderCoverage();
};

class PerturbationModel: public Model {
public:
    PerturbationModel(string p, Experiment *exp);
    virtual ~PerturbationModel();
private:

};

class CoverageModel: public Model {
public:
    CoverageModel(string p, Experiment *exp);
    virtual ~CoverageModel();
private:

};

class VelocityModel : public Model {
public:
    VelocityModel(string path, Experiment *exp);
    virtual ~VelocityModel();
private:
    int read();
};

class TimeModel : public Model {
public:
    TimeModel(string path, Experiment *exp);
    virtual ~TimeModel();
private:

};

#endif	/* MODEL_H */

