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
  cout << "FECxxAdaptor.cxx: Creating an image data\n";
}

// Add field(s) to the data container.
// Separate from above because this will be dynamic, grid is static.
// By hand name mangling for fortran.
extern "C" void addfield_(double* scalars, char* name)
{
  cout << "FECxxAdaptor.cxx: Creating field data\n";
}
