#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Input 
{
    char* key;
    char* value;
};

typedef struct Input Input ;

struct ListOfInput
{
    // TODO: Create dynamic size array for type Input
};

typedef struct ListOfInput ListOfInput;

void insert_input(Input *input, char* key, char* value)
{
    input->key = key;
    char* current_val = input->value;
    if (current_val[0] !=  '\0' && strcmp(current_val, value) != 0) {
        sprintf(input->value, "%s,%s", input->value, value);
    }
    else {
        input->value = value; 
        
    }
    
    printf("key: %s value: %s ptr: %p \n", input->key, input->value, &input);
}

void validate_input(char* input_value, char* input_key)
{
    // Create Input validation Here
}

int main(int argcount, char** argvalue) 
{   
    struct Input input = {.key = "", .value = ""}; // initialize struct for easier string manipulations
    struct Input* input_ptr = &input;

    for (int i = 1; i < argcount; i++) {
        
        char* key = argvalue[i];
        char* val = argvalue[i+1];
        // Get Input Value for -k / --key value
        if (strcmp(key, "-k") == 0 || strcmp(key, "--key") == 0) {
            insert_input(input_ptr, "k", val);
        }
       
    }

   return 0;
};


// TODO: 
// 1. Create Input Validation for keys that will be used as input
// 2. Create Validation For empty input from Type ListOfInput