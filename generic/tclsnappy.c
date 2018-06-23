/*
 * Copyright (c) <2016-2018>, <Danilo Chang>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <tcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tclsnappy.h"
#ifdef USE_SYSTEM_SNAPPY
#include <snappy-c.h>
#else
#include "snappy-c.h"
#endif

#ifdef __cplusplus
}
#endif

int  snappycompress (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[])
{
    char *snappy_string = NULL;
    int snappy_len = 0;
    char *output;
    size_t output_len = 0;
    Tcl_Obj *pResultStr = NULL;

    if(objc != 2)
    {
        Tcl_WrongNumArgs(interp, 1, obj, "string");
        return TCL_ERROR;
    }

    snappy_string = (char *) Tcl_GetStringFromObj(obj[1], &snappy_len);
    if( !snappy_string || snappy_len < 1 ){
       return TCL_ERROR;
    }

    output_len = snappy_max_compressed_length(snappy_len);
    output = (char *)malloc(output_len);
    if (!output) {
          Tcl_AppendResult(interp, "compress: memory error",  (char*)0);
          return TCL_ERROR;
    }

    if (snappy_compress(snappy_string, snappy_len, output, &output_len) == SNAPPY_OK) {
        pResultStr = Tcl_NewStringObj( output, output_len);
        Tcl_SetObjResult(interp, pResultStr);
    } else {
        if(output) free(output);
        Tcl_AppendResult(interp, "compress: error",  (char*)0);
        return TCL_ERROR;
    }
    
    if(output) free(output);
    return TCL_OK;
}

int  snappydecompress (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[])
{
    char *snappy_string = NULL;
    int snappy_len = 0;
    char *output;
    size_t output_len = 0;
    Tcl_Obj *pResultStr = NULL;

    if(objc != 2)
    {
        Tcl_WrongNumArgs(interp, 1, obj, "string");
        return TCL_ERROR;
    }

    snappy_string = (char *) Tcl_GetStringFromObj(obj[1], &snappy_len);
    if( !snappy_string || snappy_len < 1 ){
       return TCL_ERROR;
    }

    if (snappy_uncompressed_length(snappy_string, snappy_len, &output_len) != SNAPPY_OK) {
        Tcl_AppendResult(interp, "decompress : output length error",  (char*)0);
        return TCL_ERROR;
    }

    output = (char *)malloc(output_len);
    if (!output) {
        Tcl_AppendResult(interp, "decompress : memory error",  (char*)0);
        return TCL_ERROR;
    }

    if (snappy_uncompress(snappy_string, snappy_len, output, &output_len) == SNAPPY_OK) {
        pResultStr = Tcl_NewStringObj( output, output_len);
        Tcl_SetObjResult(interp, pResultStr);
    } else {
        if(output) free(output);
        Tcl_AppendResult(interp, "decompress: error",  (char*)0);
        return TCL_ERROR;
    }
    
    if(output) free(output);
    return TCL_OK;
}

int  snappycompressB (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[])
{
    unsigned char *snappy_string = NULL;
    int snappy_len = 0;
    unsigned char *output;
    size_t output_len = 0;
    Tcl_Obj *pResultStr = NULL;

    if(objc != 2)
    {
        Tcl_WrongNumArgs(interp, 1, obj, "byte_array");
        return TCL_ERROR;
    }

    snappy_string = (unsigned char *) Tcl_GetByteArrayFromObj(obj[1], &snappy_len);
    if( !snappy_string || snappy_len < 1 ){
       return TCL_ERROR;
    }

    output_len = snappy_max_compressed_length(snappy_len);
    output = (unsigned char *)malloc(output_len);
    if (!output) {
          Tcl_AppendResult(interp, "compress: memory error",  (char*)0);
          return TCL_ERROR;
    }

    if (snappy_compress((char *)snappy_string, snappy_len, (char *)output, &output_len) == SNAPPY_OK) {
        pResultStr = Tcl_NewByteArrayObj( output, output_len);
        Tcl_SetObjResult(interp, pResultStr);
    } else {
        if(output) free(output);
        Tcl_AppendResult(interp, "compress: error",  (char*)0);
        return TCL_ERROR;
    }

    if(output) free(output);
    return TCL_OK;
}

int  snappydecompressB (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST obj[])
{
    unsigned char *snappy_string = NULL;
    int snappy_len = 0;
    unsigned char *output;
    size_t output_len = 0;
    Tcl_Obj *pResultStr = NULL;

    if(objc != 2)
    {
        Tcl_WrongNumArgs(interp, 1, obj, "byte_array");
        return TCL_ERROR;
    }

    snappy_string = (unsigned char *) Tcl_GetByteArrayFromObj(obj[1], &snappy_len);
    if( !snappy_string || snappy_len < 1 ){
       return TCL_ERROR;
    }

    if (snappy_uncompressed_length((char *) snappy_string, snappy_len, &output_len) != SNAPPY_OK) {
        Tcl_AppendResult(interp, "decompress : output length error",  (char*)0);
        return TCL_ERROR;
    }

    output = (unsigned char *)malloc(output_len);
    if (!output) {
        Tcl_AppendResult(interp, "decompress : memory error",  (char*)0);
        return TCL_ERROR;
    }

    if (snappy_uncompress((char *) snappy_string, snappy_len, (char *) output, &output_len) == SNAPPY_OK) {
        pResultStr = Tcl_NewByteArrayObj( output, output_len);
        Tcl_SetObjResult(interp, pResultStr);
    } else {
        if(output) free(output);
        Tcl_AppendResult(interp, "decompress: error",  (char*)0);
        return TCL_ERROR;
    }

    if(output) free(output);
    return TCL_OK;
}

int Snappy_Init(Tcl_Interp *interp)
{
    if (Tcl_InitStubs(interp, "8.4", 0) == NULL) {
	return TCL_ERROR;
    }
    if (Tcl_PkgProvide(interp, PACKAGE_NAME, PACKAGE_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }

    Tcl_CreateObjCommand(interp, "snappy::compress", (Tcl_ObjCmdProc *) snappycompress,
	   (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    Tcl_CreateObjCommand(interp, "snappy::decompress", (Tcl_ObjCmdProc *) snappydecompress,
       (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    Tcl_CreateObjCommand(interp, "snappy::compressByte", (Tcl_ObjCmdProc *) snappycompressB,
	   (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    Tcl_CreateObjCommand(interp, "snappy::decompressByte", (Tcl_ObjCmdProc *) snappydecompressB,
       (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}
