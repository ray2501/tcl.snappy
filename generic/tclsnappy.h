#ifndef _SNAPPY
#define _SNAPPY

/*
 * For C++ compilers, use extern "C"
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <tcl.h>
    
/*
 * Only the _Init function is exported.
 */

extern DLLEXPORT int	Snappy_Init(Tcl_Interp * interp);

int  snappycompress (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[]);
int  snappydecompress (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[]);

/*
 * end block for C++
 */

#ifdef __cplusplus
}
#endif

#endif /* _SNAPPY */
