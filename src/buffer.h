#ifndef BUFFER_H
#define BUFFER_H

#include "jega.h"
#include "util.h"

typedef enum{
    WRITE_OK,
    MEMORY_ERROR,
    LIMIT_OVER,
} buffer_result;

typedef struct {
    char *buf;
    size_t buf_size;
    size_t len;
    size_t limit;
} buffer_t;

buffer_t* new_buffer(size_t buf_size, size_t limit);

buffer_result extend_buffer(buffer_t *buf, size_t  l);

buffer_result write2buf(buffer_t *buf, const char *c, size_t  l);

void free_buffer(buffer_t *buf);

PyObject* getPyString(buffer_t *buf);

PyObject* getPyStringAndDecode(buffer_t *buf);

char* getString(buffer_t *buf);

int copy_buffer(buffer_t *src, buffer_t *dest);

#endif
