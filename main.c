#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "utils.h"

int main(int argcount, char* argvalue[]) {   
    Input* input = NULL;
    int count = 0;
   
    for (int i = 1; i < argcount; i++) {
        char* key = argvalue[i]; // the flags

        
        if (i + 1 >= argcount) {
            break;  // avoiding segs fault
        }

        char* val = argvalue[i+1]; // the value
        if (key_checker(key)) {
            count++;
            input = insert_input(input, key, val, count);    
        }
         
    }

    printf("final result \n");
    printf("input_size %d\n", input->size);
    for (int j = 0; j < input->size; j++) {
        printf("key: %s, value: %s\n", input[j].key, input[j].value);
    }

   exit(0);
};