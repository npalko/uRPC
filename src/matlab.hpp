/*
  Example Usage
  
    loadlibrary('matlab', 'matlab.hpp');
    libisloaded('matlab');
    libfunctions('matlab');
    z = calllib('matlab', 'zeros', 4, 10);
    unloadlibrary('matlab');

  Implementation Notes
  
    * For primitive types, MATLAB automatically converts any argument to the 
      type expected by the external function
    * MATLAB automatically converts an argument passed by value into an 
      argument passed by reference when the external function prototype defines
      the argument as a pointer.
    * MATLAB string equivalent to char *
    * Exported function arguments passed by reference to calllib() functions
      will appear as output. This is messy, and unfortunate. 

  Interaction with MATLAB enviroment
  
  mexPrintf               ANSI C printf-style output routine
  mexWarnMsgIdAndTxt      Issue warning message with identifier
  mexErrMsgIdAndTxt       Issue error message with identifier and return to MATLAB prompt 
  
  
  mxIsNaN                 Determine whether input is NaN (Not-a-Number) 
  
  Structures
  
  mxIsStruct              Determine whether input is structure mxArray
  mxGetNumberOfFields 
  mxGetFieldNameByNumber  Get field name, given field number in structure array
  mxGetFieldByNumber      Get field value, given field number and index into structure array
  


  Open Questions
  
    * how does the mexFunction(nlhs,mxArray,nrhs,mxArray) functionality 
      translate into calllib()? is it even available?
    * how to return multiple output arguments?
    * can we read a nested struct if it's presented as a mxArray
      
    



 */

#ifndef URPC_MATLAB_HPP
#define URPC_MATLAB_HPP

// Decoration required by Microsoft compiler only. _WIN32 is also defined for 
// WIN64 enviroment. What a country!

#ifdef _WIN32 
#define EXPORTED_FUNCTION __declspec(dllexport)
#else
#define EXPORTED_FUNCTION
#endif

// loadlibrary() calls the C preprocessor on this file w, which is why we need
// the __cplusplus guard

#ifdef __cplusplus
extern "C" {
#endif

EXPORTED_FUNCTION mxArray *request(const char *, int, const mxArray *);
EXPORTED_FUNCTION mxArray *zeros(int, int);

#ifdef __cplusplus
}
#endif

#endif // URPC_MATLAB_HPP
