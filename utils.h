#ifndef UTILS_FUNC_1
#define UTILS_FUNC_1
#define _FLAG "-", "k", "e"
#define _VERBOSE_FLAG "--", "key", "ext"
#define ARRAY_SIZE(x) ( sizeof(x) / sizeof((x)[0]) )

Input* insert_input(Input* input_ptr, char* key, char* value, int i);
_Bool key_checker(char* key);
// void print_something(char* out);

#endif