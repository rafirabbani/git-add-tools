#include <stdio.h>
#include "type.h"
#include "utils.h"

int main(int argcount, char** argvalue) 
{   
    Input* input_ptr = NULL;
   
    for (int i = 1; i < argcount; i++) {
        char* key = argvalue[i]; // the flags

        
        if (i + 1 >= argcount) {
            break;  // avoiding segs fault
        }

        char* val = argvalue[i+1]; // the value

        if (key_checker("-", key) || key_checker("--", key)) {
            input_ptr = insert_input(input_ptr, key, val, i);    
        }
         
    }

   return 0;
};


// TODO: 
// 1. Create Input Validation for keys that will be used as input DONE
// 2. Create Validation For empty input from Type ListOfInput
// 3. Create Enums for Key Types