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

#include <stdlib.h>
#include <string.h>
#include <proto/exec.h>

static APTR mempool;

int setup_malloc(void) {
	mempool = IExec->AllocSysObjectTags(ASOT_MEMPOOL,
		ASOPOOL_Name,      "lz4.library memory pool",
		ASOPOOL_Protected, TRUE,
		ASOPOOL_MFlags,    MEMF_SHARED,
		ASOPOOL_LockMem,   FALSE,
		ASOPOOL_Puddle,    4096,
		ASOPOOL_Threshold, 1024,
		TAG_END);
	return mempool != NULL;
}

void cleanup_malloc(void) {
	IExec->FreeSysObject(ASOT_MEMPOOL, mempool);
}

void *malloc(size_t size) {
	size_t *ptr;
	ptr = IExec->AllocPooled(mempool, sizeof(size_t) + size);
	if (ptr) *ptr++ = size;
	return ptr;
}

void *calloc(size_t num, size_t size) {
	size *= num;
	void *ptr = malloc(size);
	if (ptr != NULL) bzero(ptr, size);
	return ptr;
}

void free(void *ptr) {
	if (ptr) {
		size_t *base = (size_t *)ptr - 1;
		IExec->FreePooled(mempool, base, sizeof(size_t) + *base);
	}
}

