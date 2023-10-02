#include <stdlib.h>
#include <stdio.h>

void* my_malloc(size_t size, const char *file, int line, const char *func) {
    printf ("Try Allocating = %s, %i, [%li]\n", file, line, size);
    void *p = malloc(size);
    printf ("Allocated = %s, %i, %p[%li]\n", file, line, p, size);
    return p;
}


void my_free(void* ptr, const char *file, int line, const char *func) {
    printf ("Try Deallocating = %s, %i, %p\n", file, line, ptr);
    free(ptr);
    printf ("Deallocated = %s, %i, %p\n", file, line, ptr);
}

void* my_realloc(void* ptr, size_t size, const char *file, int line, const char *func) {
    printf ("Try Reallocating = %s, %i, %p[%li]\n", file, line, ptr, size);
    void *p = realloc(ptr, size);
    printf ("Reallocated = %s, %i, %p[%li]\n", file, line, ptr, size);
    return p;
}

void* my_calloc(size_t size, size_t index, const char *file, int line, const char *func) {
    printf ("Try Allocating = %s, %i, [%li]\n", file, line, size);
    void *p = calloc(index, size);
    printf ("Allocated = %s, %i, %p[%li]\n", file, line, p, size);
    return p;
}