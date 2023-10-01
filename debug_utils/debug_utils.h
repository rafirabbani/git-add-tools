#ifndef DEBUG_UTILS_FUNC_1
#define DEBUG_UTILS_FUNC_1
#define malloc(X) my_malloc( X, __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free( X, __FILE__, __LINE__, __FUNCTION__)
#define realloc(X,Y) my_realloc( X, Y, __FILE__, __LINE__, __FUNCTION__)
#define calloc(X,Y) my_calloc( X, Y, __FILE__, __LINE__, __FUNCTION__)

void* my_malloc(size_t size, const char *file, int line, const char *func);
void my_free(void* ptr, const char *file, int line, const char *func);
void* my_realloc(void* ptr, size_t size, const char *file, int line, const char *func);
void* my_calloc(size_t size, size_t index, const char *file, int line, const char *func);

#endif