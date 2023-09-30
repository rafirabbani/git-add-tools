#ifndef DEBUG_UTILS_FUNC_1
#define DEBUG_UTILS_FUNC_1
#define malloc(X) my_malloc( X, __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free( X, __FILE__, __LINE__, __FUNCTION__)

void* my_malloc(size_t size, const char *file, int line, const char *func);
void my_free(void* ptr, const char *file, int line, const char *func);

#endif