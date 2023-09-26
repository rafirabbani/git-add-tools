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

static Input* create_input(char* key, char* value) 
{
    Input* input = malloc((sizeof(struct Input)));
    if (input != NULL) {
        input->key = strdup(key);
        input->value = strdup(value);
        printf("create input type with key: %s and value: %s points to %p\n", key, value, &input);
        return input;
    }
    return NULL;
}

static void delete_input(Input* input)
{
    free(input->key);
    free(input->value);
    free(input);
}


static ListOfInput* create_list_of_input(ListOfInput* list_of_input, Input* new_input, int index) 
{
    
    // return list_of_input;
    if (list_of_input != NULL) {
        // int current_size_list_input = list_of_input->size;

        // for (int i = 0; i < current_size_list_input; i++) {
        //     Input* input = list_of_input[i].input;
        //     printf("new_key: %s new_value: %s new_ptr: %p \n", input->key, input->value, &input);
        // }
        return list_of_input;
    }
    else {
        
        ListOfInput* new_list_of_input = malloc(sizeof(struct ListOfInput));
        if (index == 0) {
            new_list_of_input->size = 1;
        }
        else {
            new_list_of_input->size = index;
        }

        // TODO: a
        // 1. alloc new_list_of_input->input since type is array
        // 2. map index to allocated
       
        memcpy(&new_list_of_input->input, &new_input, sizeof(new_input));
        delete_input(new_input);


        for(int i = 1; i < new_list_of_input->size; i++) {
            printf("list_of_input: %p, input: %p, size_list_of_input", list_of_input, new_input);
            // Input* input = *new_list_of_input[i].input;
            // printf("new_key: %s new_value: %s new_ptr: %p \n", input->key, input->value, &input);
        }
        return new_list_of_input;
    }
}

Input* insert_input(Input* input_ptr, char* key, char* value, int index)
{
    if (input_ptr == NULL) {
       Input* input = create_input(key, value);
       return input;        
    }
    else { 
        ListOfInput* list_input = NULL;
        Input current_input = *input_ptr;
        printf("current_key: %s current_value: %s current_ptr: %p \n", current_input.key, current_input.value, &current_input);
        create_list_of_input(list_input, input_ptr, index);
        Input* new_input = create_input(key, value);
        printf("new_key: %s new_value: %s new_ptr: %p \n", new_input->key, new_input->value, &new_input);
        return new_input;
    }
}