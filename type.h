#ifndef TYPE_DEF_1
#define TYPE_DEF_1

struct Input 
{
    char* key;
    char* value;
};

typedef struct Input Input; 

struct ListOfInput
{
    int size;
    Input* input[];
};

typedef struct ListOfInput ListOfInput;

#endif