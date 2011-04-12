/* 
 * File:   Model.cpp
 * Author: ahlatimer
 * 
 * Created on March 4, 2011, 7:50 PM
 * Model:
 *   -Superclass to VelocityModel, PerturbationModel, CoverageModel, and TimeModel
 */

#include "Model.h"
//Constructor method
//Takes the path of the binary file, obtains the substring of the path to obtain
// iteration and step
//Sets the object's path and experiment values to the values passed
Model::Model(string path, Experiment *experiment) {
    int slash_pos = path.rfind("/");
    string base_name = path.substr(slash_pos + 1, path.length());
    name = base_name.substr(0, base_name.find(".") - 2);
    iteration = atoi(base_name.substr(base_name.find(".") - 2, 1).c_str());
    step = atoi(base_name.substr(base_name.find(".") - 1, 1).c_str());
    this->path = path;
    this->experiment = experiment;
}

Model::Model() {
}

Model::~Model() {
}

    int Model::getStep(){
    	return step;
   	}
    int Model::getIteration()
    {
     return iteration;	
   	}
    string Model::getName(){
    	return name;
   	}
   	
void Model::render() {
  renderVel();
  return;
}

void Model::TkCheckAbort(vtkRenderWindow *renWin){
  vtkRenderWindow *tempWin = renWin;
  int foo =renWin->GetEventPending();
  if(foo!= 0){
    if(NULL!=renWin){
      renWin->SetAbortRender(1);
    }
  } 
}

void Model::renderVel() {
  // This is a simple volume rendering example that
  // uses a vtkVolumeRayCast mapper

  //package->require(vtk);
  //package->require(vtkinteraction);

  // Create the standard renderer, render window
  // and interactor
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  // Create the reader for the data
  vtkImageReader *reader = vtkImageReader::New();
  reader->SetFileName(path);
  reader->SetDataScalarTypeToUnsignedShort();
  reader->SetDataByteOrderToLittleEndian();
  reader->SetFileDimensionality(3);
  reader->SetDataOrigin(0, 0, 0);
  reader->SetDataSpacing(1, 1, 1);
  reader->SetDataExtent(0, 230, 0, 25, 0, 68);
  reader->SetNumberOfScalarComponents(1);
  reader->FileLowerLeftOn();
  //#reader->SetDataMask(0x7fff);

  // Create transfer mapping scalar value to opacity
  vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
  opacityTransferFunction->AddPoint(20, 0.0);
  opacityTransferFunction->AddPoint(255, 0.2);

  // Create transfer mapping scalar value to color
  vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
  colorTransferFunction->AddRGBPoint(0.0, 1.0, 0.0, 0.0);
  colorTransferFunction->AddRGBPoint(30315.0, 0.0, 0.0, 1.0);

  // The property describes how the data will look
  vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
  volumeProperty->SetColor(colorTransferFunction);
  volumeProperty->SetScalarOpacity(opacityTransferFunction);
  volumeProperty->ShadeOn();
  volumeProperty->SetInterpolationTypeToLinear();

  //###########################################################

  // Create five surfaces F(x,y,z) = constant between range specified. The
  // GenerateValues() method creates n isocontour values between the range
  // specified.
  vtkContourFilter *contours = vtkContourFilter::New();
  contours->SetInput(reader->GetOutput());
  contours->GenerateValues(30, 0.0, 30315.0);

  vtkPolyDataMapper *contMapper = vtkPolyDataMapper::New();
  contMapper->SetInput(contours->GetOutput());
  contMapper->SetScalarRange(0.0, 30315.0);

  vtkActor *contActor = vtkActor::New();
  contActor->SetMapper(contMapper);

  // We'll put a simple outline around the data.
  vtkOutlineFilter *outline = vtkOutlineFilter::New();
  outline->SetInput(reader->GetOutput());

  vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
  outlineMapper->SetInput(outline->GetOutput());

  vtkActor *outlineActor = vtkActor::New();
  outlineActor->SetMapper(outlineMapper);
  //outlineActor->GetProperty()->SetColor(0, 0);

  //##########################################################

  // The mapper / ray cast function know how to render the data
  vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();
  vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();
  volumeMapper->SetVolumeRayCastFunction(compositeFunction);
  volumeMapper->SetInputConnection(reader->GetOutputPort());

  // The volume holds the mapper and the property and
  // can be used to position/orient the volume
  vtkVolume *volume = vtkVolume::New();
  volume->SetMapper(volumeMapper);
  volume->SetProperty(volumeProperty);

  volume->RotateX(90);
  contActor->RotateX(90);
  outlineActor->RotateX(90);

  ren1->AddVolume(volume);
  ren1->SetBackground(1, 1, 1);
  ren1->AddActor(contActor);
  ren1->AddActor(outlineActor);
  renWin->SetSize(600, 600);
  renWin->Render();
  /*
  // Maginfiy the image? How much?
  vtkRenderLargeImage *renderLarge = vtkRenderLargeImage::New();
  renderLarge->SetInput(ren1);
  renderLarge->SetMagnification(1);

  // We write out the image which causes the rendering to occur.
  vtkTIFFWriter *writer = vtkTIFFWriter::New();
  writer->SetInputConnection(renderLarge->GetOutputPort());
  writer->SetFileName("vel3d.jpg");
  writer->Write();
  */

  TkCheckAbort(renWin);
  //renWin->AddObserver("AbortCheckEvent", vtkCommand::AbortCheckEvent ,1.0f);
  //iren->AddObserver(UserEvent {wm deiconify .vtkInteract});
  iren->Initialize();
  iren->Start();


  //wm->withdraw(.);
}

void renderTimeWVol() {
  /*
   * Create the standard renderer, render window and interactor
   */
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);

  // Create the reader for the data
  vtkImageReader *reader = vtkImageReader::New();
    reader->SetFileName(IMG_FILE);
    reader->SetDataScalarTypeToUnsignedShort();
    reader->SetDataByteOrderToLittleEndian();
    reader->SetFileDimensionality(3);    
    reader->SetNumberOfScalarComponents(1);
    reader->FileLowerLeftOn();
    reader->SetDataExtent(0,230, 0, 25, 0,68);
    //reader->setDataMask(0x7fff);

  //Create transfer mapping scalar value to opacity
  vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
    opacityTransferFunction->AddPoint(20,0.0);
    opacityTransferFunction->AddPoint(255,0.2);

  //Create transfer mapping scalar value to color
  vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
    colorTransferFunction->AddRGBPoint(0.0,1.0,0.0,0.0);
    colorTransferFunction->AddRGBPoint(30315.0,0.0,0.0,1.0);

  //The property describes how the data will look
  vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
    volumeProperty->SetColor(colorTransferFunction);
    volumeProperty->SetScalarOpacity(opacityTransferFunction);
    volumeProperty->ShadeOn();
    volumeProperty->SetInterpolationTypeToLinear();
  
  /**********************************************************/
  /*
   * Create five surfaces F(x,y,z) = constant between range specified. 
   * The GenerateValues() method creates n isocontour values between the
   * range specified.
   */
  vtkContourFilter *contours = vtkContourFilter::New();
    contours->SetInput((vtkDataObject*)(reader->GetOutput())); //needs to be caste
    contours->GenerateValues(30,0.0,30315.0);

  vtkPolyDataMapper *contMapper = vtkPolyDataMapper::New();
    contMapper->SetInput(contours->GetOutput());
    contMapper->SetScalarRange(0.0,30315.0);

  vtkActor *contActor = vtkActor::New();
    contActor->SetMapper(contMapper);
  
  //We'll put a simple outline around the data.  
  vtkOutlineFilter *outline = vtkOutlineFilter::New();
    outline->SetInput((vtkDataObject*)(reader->GetOutput()));
    
  vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
    outlineMapper->SetInput(outline->GetOutput());
    
  vtkActor *outlineActor = vtkActor::New();
    outlineActor->SetMapper(outlineMapper);
    (outlineActor->GetProperty())->SetColor(0,0,0);
    
  /**********************************************************/
  // The mapper / ray cast function know how to render the data

  vtkSmartPointer<vtkVolumeRayCastCompositeFunction> compositeFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();
    vtkSmartPointer<vtkVolumeRayCastMapper> volumeMapper = vtkSmartPointer<vtkVolumeRayCastMapper>::New();
    volumeMapper->SetVolumeRayCastFunction(compositeFunction);
    volumeMapper->SetInputConnection(reader->GetOutputPort());
  
  /*
   * The volume holds the mapper and the property and
   * can be used to position/orient the volume
   */
  //vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
  vtkVolume *volume = vtkVolume::New();
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);
    
  volume->RotateX(90);
  contActor->RotateX(90);
  outlineActor->RotateX(90);
  
  ren1->AddVolume(volume);
  ren1->SetBackground(1,1,1); 
  ren1->AddActor(contActor);
  ren1->AddActor(outlineActor);
  
  renWin->SetSize(600,600);
  renWin->Render();

  /* //remove because errors, and i'm lazy
  //Maginfiy the image? How much?
  vtkRenderLargeImage *renderLarge = vtkRenderLargeImage::New();
    renderLarge->SetInput(ren1);
    renderLarge->SetMagnification(1);
  //We write out the image which causes the rendering to occur. 
  vtkTiffWriter *writer = vtkTiffWriter::New();
    writer->SetInputConnection(renderLarge->GetOutputPort);
    writer->setFileName->("../vel3d.jpg");
    writer-Write();
  */

  TkCheckAbort(renWin); //renWin AddObserver AbortCheckEvent {TkCheckAbort}
  //iren->AddObserver();//iren AddObserver UserEvent {wm deiconify .vtkInteract}
  
  iren->Initialize();
  iren->Start(); //not in tcl code
}

void renderTimeWOVol() {
  /*
   * Create the standard renderer, render window and interactor
   */
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);

  // Create the reader for the data
  vtkImageReader *reader = vtkImageReader::New();
    reader->SetFileName(IMG_FILE);
    reader->SetDataScalarTypeToUnsignedShort();
    reader->SetDataByteOrderToLittleEndian();
    reader->SetFileDimensionality(3);    
    reader->SetNumberOfScalarComponents(1);
    reader->FileLowerLeftOn();
    reader->SetDataExtent(0,230, 0, 25, 0,68);
    //reader->setDataMask(0x7fff);

  //Create transfer mapping scalar value to opacity
  vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
    opacityTransferFunction->AddPoint(20,0.0);
    opacityTransferFunction->AddPoint(255,0.2);

  //Create transfer mapping scalar value to color
  vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
    colorTransferFunction->AddRGBPoint(0.0,1.0,0.0,0.0);
    colorTransferFunction->AddRGBPoint(30315.0,0.0,0.0,1.0);

  //The property describes how the data will look
  vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
    volumeProperty->SetColor(colorTransferFunction);
    volumeProperty->SetScalarOpacity(opacityTransferFunction);
    volumeProperty->ShadeOn();
    volumeProperty->SetInterpolationTypeToLinear();
  
  /**********************************************************/
  /*
   * Create five surfaces F(x,y,z) = constant between range specified. 
   * The GenerateValues() method creates n isocontour values between the
   * range specified.
   */
  vtkContourFilter *contours = vtkContourFilter::New();
    contours->SetInput((vtkDataObject*)(reader->GetOutput())); //needs to be caste
    contours->GenerateValues(30,0.0,30315.0);

  vtkPolyDataMapper *contMapper = vtkPolyDataMapper::New();
    contMapper->SetInput(contours->GetOutput());
    contMapper->SetScalarRange(0.0,30315.0);

  vtkActor *contActor = vtkActor::New();
    contActor->SetMapper(contMapper);
  
  //We'll put a simple outline around the data.  
  vtkOutlineFilter *outline = vtkOutlineFilter::New();
    outline->SetInput((vtkDataObject*)(reader->GetOutput()));
    
  vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
    outlineMapper->SetInput(outline->GetOutput());
    
  vtkActor *outlineActor = vtkActor::New();
    outlineActor->SetMapper(outlineMapper);
    (outlineActor->GetProperty())->SetColor(0,0,0);
    
  /**********************************************************/
  contActor->RotateX(90);
  outlineActor->RotateX(90);
  
  ren1->SetBackground(1,1,1); 
  ren1->AddActor(contActor);
  ren1->AddActor(outlineActor);
  
  renWin->SetSize(600,600);
  renWin->Render();

  /* //remove because errors, and i'm lazy
  //Maginfiy the image? How much?
  vtkRenderLargeImage *renderLarge = vtkRenderLargeImage::New();
    renderLarge->SetInput(ren1);
    renderLarge->SetMagnification(1);
  //We write out the image which causes the rendering to occur. 
  vtkTiffWriter *writer = vtkTiffWriter::New();
    writer->SetInputConnection(renderLarge->GetOutputPort);
    writer->setFileName->("../vel3d.jpg");
    writer-Write();
  */

  TkCheckAbort(renWin); //renWin AddObserver AbortCheckEvent {TkCheckAbort}
  //iren->AddObserver();//iren AddObserver UserEvent {wm deiconify .vtkInteract}
  
  iren->Initialize();
  iren->Start(); //not in tcl code
}

void renderDusum() {
  // This is a simple volume rendering example that
  // uses a vtkVolumeRayCast mapper

  //package->require(vtk);
  //package->require(vtkinteraction);

  // Create the standard renderer, render window
  // and interactor
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  // Create the reader for the data
  vtkImageReader *reader = vtkImageReader::New();
  reader->SetFileName("dusum.3d");
  reader->SetDataScalarTypeToUnsignedShort();
  reader->SetDataByteOrderToLittleEndian();
  reader->SetFileDimensionality(3);
  reader->SetDataOrigin(0, 0, 0);
  reader->SetDataSpacing(1, 1, 1);
  reader->SetDataExtent(0, 229, 0, 24, 0, 67);
  reader->SetNumberOfScalarComponents(1);
  reader->FileLowerLeftOn();
  //#reader->SetDataMask(0x7fff);

  // Create transfer mapping scalar value to opacity
  vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
  opacityTransferFunction->AddPoint(20, 0.0);
  opacityTransferFunction->AddPoint(255, 0.2);

  // Create transfer mapping scalar value to color
  vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
  colorTransferFunction->AddRGBPoint(11950.0, 1.0, 0.0, 0.0);
  colorTransferFunction->AddRGBPoint(12025.0, 0.0, 0.0, 1.0);

  // The property describes how the data will look
  vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
  volumeProperty->SetColor(colorTransferFunction);
  volumeProperty->SetScalarOpacity(opacityTransferFunction);

  //The property describes how the will look
  volumeProperty->ShadeOn();
  volumeProperty->SetInterpolationTypeToLinear();

  //###########################################################

  // Create five surfaces F(x,y,z) = constant between range specified. The
  // GenerateValues() method creates n isocontour values between the range
  // specified.

  // Create n isocontour values between the range specified.
  vtkContourFilter *contours = vtkContourFilter::New();
  contours->SetInput(reader->GetOutput());
  contours->GenerateValues(40, 11950.0, 12025.0);

  vtkPolyDataMapper *contMapper = vtkPolyDataMapper::New();
  contMapper->SetInput(contours->GetOutput());
  contMapper->SetScalarRange(11950.0, 12025.0);

  vtkActor *contActor = vtkActor::New();
  contActor->SetMapper(contMapper);

  // We'll put a simple outline around the data.
  vtkOutlineFilter *outline = vtkOutlineFilter::New();
  outline->SetInput(reader->GetOutput());

  vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
  outlineMapper->SetInput(outline->GetOutput());


  vtkActor *outlineActor = vtkActor::New();
  outlineActor->SetMapper(outlineMapper);
  //outlineActor->GetProperty()->SetColor(0, 0);

  //##########################################################

  // The mapper / ray cast function know how to render the data
  //vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();
  //vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();
  //volumeMapper->SetVolumeRayCastFunction(compositeFunction);
  //volumeMapper->SetInputConnection(reader->GetOutputPort());

  // The volume holds the mapper and the property and
  // can be used to position/orient the volume
  //vtkVolume *volume = vtkVolume::New();
  //volume->SetMapper(volumeMapper);
  //volume->SetProperty(volumeProperty);

  //volume->RotateX(90);
  contActor->RotateX(90);
  outlineActor->RotateX(90);

  //ren1->AddVolume(volume);
  ren1->SetBackground(1, 1, 1);
  ren1->AddActor(contActor);
  ren1->AddActor(outlineActor);
  renWin->SetSize(600, 600);
  renWin->Render();

  /* Maginfiy the image? How much?
  vtkRenderLargeImage *renderLarge = vtkRenderLargeImage::New();
  renderLarge->SetInput(ren1);
  renderLarge->SetMagnification(1);

  // We write out the image which causes the rendering to occur.
  vtkTIFFWriter *writer = vtkTIFFWriter::New();
  writer->SetInputConnection(renderLarge->GetOutputPort());
  writer->SetFileName("vel3d.jpg");
  writer->Write();
  */

  TkCheckAbort(renWin);
  //renWin->AddObserver("AbortCheckEvent", vtkCommand::AbortCheckEvent ,1.0f);
  //iren->AddObserver(UserEvent {wm deiconify .vtkInteract});
  iren->Initialize();
  iren->Start();


  //wm->withdraw(.);
}

void renderCoverage() {
  // This is a simple volume rendering example that
  // uses a vtkVolumeRayCast mapper

  //package->require(vtk);
  //package->require(vtkinteraction);

  // Create the standard renderer, render window
  // and interactor
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  // Create the reader for the data
  vtkImageReader *reader = vtkImageReader::New();
  reader->SetFileName("icovsh.3d");
  reader->SetDataScalarTypeToUnsignedShort();
  reader->SetDataByteOrderToLittleEndian();
  reader->SetFileDimensionality(3);
  reader->SetDataOrigin(0, 0, 0);
  reader->SetDataSpacing(1, 1, 1);
  reader->SetDataExtent(0, 229, 0, 24, 0, 67);
  reader->SetNumberOfScalarComponents(1);
  reader->FileLowerLeftOn();
  //#reader->SetDataMask(0x7fff);

  // Create transfer mapping scalar value to opacity
  vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
  opacityTransferFunction->AddPoint(20, 0.0);
  opacityTransferFunction->AddPoint(255, 0.2);

  // Create transfer mapping scalar value to color
  vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
  colorTransferFunction->AddRGBPoint(0.0, 1.0, 0.0, 0.0);
  colorTransferFunction->AddRGBPoint(30315.0, 0.0, 0.0, 1.0);

  // The property describes how the data will look
  vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
  volumeProperty->SetColor(colorTransferFunction);
  volumeProperty->SetScalarOpacity(opacityTransferFunction);
          colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
          colorTransferFunction->AddRGBPoint(64.0, 1.0, 0.0, 0.0);
          colorTransferFunction->AddRGBPoint(128.0, 0.0, 0.0, 0.0);
          colorTransferFunction->AddRGBPoint(192.0, 0.0, 0.0, 0.0);
          colorTransferFunction->AddRGBPoint(255.0, 0.0, 0.0, 0.0);

  //The property describes how the will look
  volumeProperty->ShadeOn();
  volumeProperty->SetInterpolationTypeToLinear();

  //###########################################################

  // Create five surfaces F(x,y,z) = constant between range specified. The
  // GenerateValues() method creates n isocontour values between the range
  // specified.

  //vtkActor *contActor = vtkActor::New();
  //contActor->SetMapper(contMapper);

  // We'll put a simple outline around the data.
  vtkOutlineFilter *outline = vtkOutlineFilter::New();
  outline->SetInput(reader->GetOutput());

  vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
  outlineMapper->SetInput(outline->GetOutput());

  vtkActor *outlineActor = vtkActor::New();
  outlineActor->SetMapper(outlineMapper);
  //outlineActor->GetProperty()->SetColor(0, 0);

  //##########################################################

  // The mapper / ray cast function know how to render the data
  vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();
  vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();
  volumeMapper->SetVolumeRayCastFunction(compositeFunction);
  volumeMapper->SetInputConnection(reader->GetOutputPort());

  // The volume holds the mapper and the property and
  // can be used to position/orient the volume
  vtkVolume *volume = vtkVolume::New();
  volume->SetMapper(volumeMapper);
  volume->SetProperty(volumeProperty);

  volume->RotateX(90);
  //contActor->RotateX(90);
  outlineActor->RotateX(90);

  ren1->AddVolume(volume);
  ren1->SetBackground(1, 1, 1);
  //ren1->AddActor(contActor);
  ren1->AddActor(outlineActor);
  renWin->SetSize(600, 600);
  renWin->Render();

  /* Maginfiy the image? How much?
  vtkRenderLargeImage *renderLarge = vtkRenderLargeImage::New();
  renderLarge->SetInput(ren1);
  renderLarge->SetMagnification(1);

  // We write out the image which causes the rendering to occur.
  vtkTIFFWriter *writer = vtkTIFFWriter::New();
  writer->SetInputConnection(renderLarge->GetOutputPort());
  writer->SetFileName("vel3d.jpg");
  writer->Write();
  */

  TkCheckAbort(renWin);
  //renWin->AddObserver("AbortCheckEvent", vtkCommand::AbortCheckEvent ,1.0f);
  //iren->AddObserver(UserEvent {wm deiconify .vtkInteract});
  iren->Initialize();
  iren->Start();


  //wm->withdraw(.);
}

