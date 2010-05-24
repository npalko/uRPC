#include "mex.h"
#include "matlab.hpp"

EXPORTED_FUNCTION void multDoubleArray(double *x, int size)
{
  // Multiply each element of the array by 3 
  // UNCLEAR how this is being returned! need x = calllib() in order to get
  // return value, not obvious from this construction

  for (int i=0; i<size; i++)
    *x++ *= 3;
}

EXPORTED_FUNCTION mxArray* zeros(int m, int n)
{
  // rough replica of MATLAB zeros() function
  
  mxArray* zeroArray;
  zeroArray = mxCreateNumericMatrix((mwSize) m, (mwSize) n, 
    mxDOUBLE_CLASS, mxREAL);
  return zeroArray;
}
