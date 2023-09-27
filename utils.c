#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "type.h"
#include "utils.h"

bool key_checker(char* pre, char* key) 
{
    return strncmp(pre, key, strlen(pre)) == 0;
}

static Input* create_input(char* key, char* value, int len) 
{
    Input* list_of_input;
    list_of_input = malloc(sizeof(Input) * len);
    if (list_of_input != NULL) {
        for (int i = 0; i < len; i++) {
            list_of_input[i].key = key;
            list_of_input[i].value = value;
            printf("created_input \n");
            printf("index: %d, key: %s, value: %s\n", i, list_of_input[i].key, list_of_input[i].value);
        }
        list_of_input->size = len;
        return list_of_input;
    }
    else {
        printf("error memory allocation");
        exit(1);
    }
}

Input* insert_input(Input* current_input, char* key, char* value, int index)
{
    if (current_input == NULL) {
       Input* input = create_input(key, value, index);
       return input;        
    }
    else { 
        Input* new_input = create_input(key, value, index);
        Input* temp_current_input = current_input;
        int size_new_input = new_input->size;
        int size_current_input = current_input->size;

        if (size_new_input < size_current_input) { // exit when mem allocation is fault
            printf("error memory allocation");
            free(new_input);  // free mem from the new struct
            free(current_input); // free mem from the old struct
            exit(1);
        }

        int i = 1;
        while (i < size_new_input) {
            char* temp_key;
            char* temp_value;
            for (int j = 0; j < size_current_input; j++) {
                temp_key = temp_current_input[j].key;
                temp_value = temp_current_input[j].value;
                new_input[i].key = temp_key;
                new_input[i].value = temp_value;
                i++;
            }
        }

        free(current_input); // free mem from the old struct
        
        for (int k = 0; k < size_new_input; k++) {
            printf("key: %s, value: %s \n", new_input[k].key, new_input[k].value);
        }
        return new_input;
    }
}