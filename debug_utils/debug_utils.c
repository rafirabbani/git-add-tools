#include <stdlib.h>
#include <stdio.h>

void* my_malloc(size_t size, const char *file, int line, const char *func) {
    void *p = malloc(size);
    printf ("Allocated = %s, %i, %p[%li]\n", file, line, p, size);

    return p;
}


void my_free(void* ptr, const char *file, int line, const char *func) {
    printf ("Deallocated = %s, %i, %p\n", file, line, ptr);
    free(ptr);
}