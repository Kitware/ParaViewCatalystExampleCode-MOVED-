// Adaptor for getting Fortran simulation code into ParaView Catalyst.

// CoProcessor specific headers
#include "vtkCPDataDescription.h"
#include "vtkCPInputDataDescription.h"
#include "vtkCPProcessor.h"
#include "vtkSmartPointer.h"
#include "vtkDoubleArray.h"
#include "vtkPointData.h"
#include "vtkImageData.h"

// Fortran specific header
#include "vtkCPPythonAdaptorAPI.h"

// These will be called from the Fortran "glue" code"
// Completely dependent on data layout, structured vs. unstructured, etc.
// since VTK/ParaView uses different internal layouts for each.

// Creates the data container for the CoProcessor.
extern "C" void createcpimagedata_(int* dimensions, int* extent)
{
  if (!vtkCPPythonAdaptorAPI::GetCoProcessorData())
    {
    vtkGenericWarningMacro("Unable to access CoProcessorData.");
    return;
    }

  // The simulation grid is a 3-dimensional topologically and geometrically
  // regular grid. In VTK/ParaView, this is considered an image data set.
  vtkSmartPointer<vtkImageData> grid = vtkSmartPointer<vtkImageData>::New();

  // Name should be consistent between here, Fortran and Python client script.
  vtkCPPythonAdaptorAPI::GetCoProcessorData()->GetInputDescriptionByName("input")->SetGrid(grid);
}

// Add field(s) to the data container.
// Separate from above because this will be dynamic, grid is static.
// By hand name mangling for fortran.
extern "C" void addfield_(double* scalars, char* name)
{
}
