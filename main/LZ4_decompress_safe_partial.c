/*
 * AmigaOS shared library implementation of liblz4.
 *
 * Copyright (C) 2014-2017 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <interfaces/lz4.h>
#include "../lz4_vectors.h"

/****** lz4/main/LZ4_decompress_safe_partial ******************************************
*
*   NAME
*      LZ4_decompress_safe_partial -- Description
*
*   SYNOPSIS
*      int32 LZ4_decompress_safe_partial(CONST_APTR source, APTR dest, 
*          int32 compressedSize, int32 targetOutputSize, 
*          int32 maxDecompressedSize);
*
*   FUNCTION
*
*   INPUTS
*       source - 
*       dest - 
*       compressedSize - 
*       targetOutputSize - 
*       maxDecompressedSize - 
*
*   RESULT
*       The result ...
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

int32 _main_LZ4_decompress_safe_partial(struct LZ4IFace *Self, CONST_APTR source, APTR dest,
	int32 compressedSize, int32 targetOutputSize, int32 maxDecompressedSize)
{
	return LZ4_decompress_safe_partial(source, dest, compressedSize, targetOutputSize, maxDecompressedSize);
}

