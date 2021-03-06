
/* This file was generated by idltool 53.23. Do not edit */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif
#ifndef LIBRARIES_LZ4_H
#include <libraries/lz4.h>
#endif

/* forward declaration */
struct LZ4IFace;

extern uint32               VARARGS68K _main_Obtain(struct LZ4IFace *);
extern uint32               VARARGS68K _main_Release(struct LZ4IFace *);
extern int32                VARARGS68K _main_LZ4_versionNumber(struct LZ4IFace *);
extern int32                VARARGS68K _main_LZ4_compress(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 sourceSize);
extern int32                VARARGS68K _main_LZ4_decompress_safe(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 compressedSize, int32 maxDecompressedSize);
extern int32                VARARGS68K _main_LZ4_compressBound(struct LZ4IFace *, int32 isize);
extern int32                VARARGS68K _main_LZ4_compress_limitedOutput(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 sourceSize, int32 maxOutputSize);
extern int32                VARARGS68K _main_LZ4_decompress_fast(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 originalSize);
extern int32                VARARGS68K _main_LZ4_decompress_safe_partial(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 compressedSize, int32 targetOutputSize, int32 maxDecompressedSize);
extern int32                VARARGS68K _main_LZ4_compressHC(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 inputSize);
extern int32                VARARGS68K _main_LZ4_compressHC_limitedOutput(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 inputSize, int32 maxOutputSize);
extern int32                VARARGS68K _main_LZ4_compressHC2(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 inputSize, int32 compressionLevel);
extern int32                VARARGS68K _main_LZ4_compressHC2_limitedOutput(struct LZ4IFace *, CONST_APTR source, APTR dest, int32 inputSize, int32 maxOutputSize, int32 compressionLevel);
extern int32                VARARGS68K _main_LZ4_sizeofStateHC(struct LZ4IFace *);
extern int32                VARARGS68K _main_LZ4_compressHC_withStateHC(struct LZ4IFace *, APTR state, CONST_APTR source, APTR dest, int32 inputSize);
extern int32                VARARGS68K _main_LZ4_compressHC_limitedOutput_withStateHC(struct LZ4IFace *, APTR state, CONST_APTR source, APTR dest, int32 inputSize, int32 maxOutputSize);
extern int32                VARARGS68K _main_LZ4_compressHC2_withStateHC(struct LZ4IFace *, APTR state, CONST_APTR source, APTR dest, int32 inputSize, int32 compressionLevel);
extern int32                VARARGS68K _main_LZ4_compressHC2_limitedOutput_withStateHC(struct LZ4IFace *, APTR state, CONST_APTR source, APTR dest, int32 inputSize, int32 maxOutputSize, int32 compressionLevel);
