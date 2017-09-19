TARGET  := lz4.library
VERSION := 53

LZ4DIR := lz4-r123

CC     := ppc-amigaos-gcc
STRIP  := ppc-amigaos-strip
AR     := ppc-amigaos-ar
RANLIB := ppc-amigaos-ranlib 

CFLAGS  := -O2 -g -Wall -Wwrite-strings -Werror -I./include -I./$(LZ4DIR)
LDFLAGS := -static
LIBS    := 

LZ4_SRCS := $(wildcard $(LZ4DIR)/*.c)
LZ4_OBJS := $(LZ4_SRCS:.c=.o)

main_SRCS := main/Obtain.c main/Release.c main/LZ4_versionNumber.c \
             main/LZ4_compress.c main/LZ4_decompress_safe.c main/LZ4_compressBound.c \
             main/LZ4_compress_limitedOutput.c main/LZ4_decompress_fast.c \
             main/LZ4_decompress_safe_partial.c main/LZ4_compressHC.c \
             main/LZ4_compressHC_limitedOutput.c main/LZ4_compressHC2.c \
             main/LZ4_compressHC2_limitedOutput.c main/LZ4_sizeofStateHC.c \
             main/LZ4_compressHC_withStateHC.c \
             main/LZ4_compressHC_limitedOutput_withStateHC.c \
             main/LZ4_compressHC2_withStateHC.c \
             main/LZ4_compressHC2_limitedOutput_withStateHC.c
main_OBJS := $(main_SRCS:.c=.o)

SRCS := init.c malloc.c
OBJS := $(main_SRCS:.c=.o)  $(SRCS:.c=.o)

.PHONY: all
all: $(TARGET)

init.o: $(TARGET)_rev.h lz4_vectors.c lz4_vectors.h
$(main_OBJS): lz4_vectors.h

$(LZ4_OBJS): CFLAGS += -DNO_STREAM -DNO_OBSOLETE

$(LZ4DIR)/liblz4-static.a: $(LZ4_OBJS)
	$(AR) -crv $@ $^
	$(RANLIB) $@

$(TARGET): $(OBJS) $(LZ4DIR)/liblz4-static.a
	$(CC) $(LDFLAGS) -nostartfiles -o $@.debug $^ $(LIBS)
	$(STRIP) -R.comment -o $@ $@.debug

.PHONY: clean
clean:
	rm -f $(LZ4DIR)/liblz4-static.a $(LZ4DIR)/*.o
	rm -f $(TARGET) $(TARGET).debug *.o main/*.o

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)

