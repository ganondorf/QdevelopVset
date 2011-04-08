
#include "RenderWindow.h"
#include <QApplication>
/**
//#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>
#include <QVTKWidget.h>
*/
int RenderWindow::main(int argc, char** argv)
{
	/**
  QApplication app(argc, argv);
 
  QVTKWidget widget;
  widget.resize(256,256);
  
  //setup window
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
      vtkSmartPointer<vtkRenderWindow>::New();
 
  //setup renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
      
  renderWindow->AddRenderer(renderer);

  
  renderer->ResetCamera();
 
  widget.SetRenderWindow(renderWindow);
  
  widget.show();
 
  app.exec();
 
  return EXIT_SUCCESS;
**/
}