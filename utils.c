#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "type.h"
#include "utils.h"
#include "./debug_utils/debug_utils.h"

static char* remove_sub_string(char *input, const char *substr, bool is_copy) {
    char *p, *q, *r;
    p = q = r = NULL;
    char *output;

    if (is_copy) {
        output = malloc(sizeof(input)); 
        size_t len_input = strlen(input) + 1;
        strncpy(output, input, len_input);
    }
    else {
        output = input;
    }
    
    // printf("input_key:%s, p: %s, q: %s, r: %s\n", input, p, q, r);
    if (*substr && (q = r = strstr(output, substr)) != NULL) {
        // printf("input_key:%s, p: %s, q: %s, r: %s\n", input, p, q, r);
        size_t len = strlen(substr);
        while ((r = strstr(p = r + len, substr)) != NULL) {
            // printf("input_key:%s, p: %s, q: %s, r: %s\n", input, p, q, r);
            while (p < r)
                *q++ = *p++;
                // printf("input_key:%s, p: %s, q: %s, r: %s\n", input, p, q, r);
        }
        while ((*q++ = *p++) != '\0') {
            // printf("input_key:%s, p: %s, q: %s, r: %s\n", input, p, q, r);
            continue;
        }
        
    }

    // reset value p,q,r

    if (p != NULL) {
        p = NULL;
    }

    if (q != NULL) {
        q = NULL;
    }

    if (r != NULL) {
        r = NULL;
    }

    return output;
}

bool key_checker(char *key) {
    char *flags[] = {_FLAG}; 
    char *verbose_flags[] = {_VERBOSE_FLAG};

    char first_char = key[0];
    char second_char = key[1];
    char flag_char = *flags[0];
    char *trimmed_key;
    size_t trimmed_key_len;

    if ((flag_char == first_char) && (flag_char == second_char)) {
        trimmed_key = remove_sub_string(key, verbose_flags[0], false);
        // printf("trimmed_key: %s\n", trimmed_key);
        size_t size_verbose_flag = ARRAY_SIZE(verbose_flags);
        trimmed_key_len = strlen(trimmed_key) + 1;

        for (int i = 1; i < size_verbose_flag; i++) {
            if ((strncmp(trimmed_key, verbose_flags[i], trimmed_key_len)) == 0) {
                return true;
            }
        } 
    }
    else {
        trimmed_key = remove_sub_string(key, flags[0], false);
        // printf("trimmed_key: %s\n", trimmed_key);
        trimmed_key_len = strlen(trimmed_key) + 1;
        size_t size_flag = ARRAY_SIZE(flags);
        for (int i = 1; i < size_flag; i++) {
            if ((strncmp(trimmed_key, flags[i], trimmed_key_len)) == 0) {
                return true;
            }
        }
    }

    return false;  
}

static Input* create_input(char *key, char *value, int len) {
    // printf("masuk key: %s, val: %s, len: %d \n", key, value, len);
    Input* list_of_input = malloc(sizeof(Input) * len);
    if (list_of_input != NULL) {
        list_of_input[0].key = malloc(strlen(key) + 1);
        list_of_input[0].value = malloc(strlen(value) + 1);
        strncpy(list_of_input[0].key, key, strlen(key) + 1);
        strncpy(list_of_input[0].value, value, strlen(value) + 1);
        list_of_input->size = len;
        return list_of_input;
    }
    else {
        printf("error memory allocation \n");
        exit(1);
    }
}

Input* insert_input(Input *current_input, char *key, char *value, int index) {
    // printf("masuk with_key:%s\n", key);
    if (current_input == NULL) {
        // printf("masuk_if with_key:%s\n", key);
       Input *input = create_input(key, value, index);
       return input;        
    }
    else {
        printf("masuk_else_1 with_key: %s\n", key);
        Input *new_input = create_input(key, value, index);
        // Input* temp_current_input = current_input;
        int size_new_input = new_input->size;
        int size_current_input = current_input->size;
        
        if (size_new_input < size_current_input) { // exit when mem allocation is failed
            printf("error memory allocation \n");
            free(new_input);  // free mem from the new struct
            free(current_input); // free mem from the old struct
            exit(1);
        }

        for (int i = 0; i < size_current_input; i++) { 
            // printf("new_input[%d].key: %s, new_input[%d].value: %s\n", i, new_input[i].key, i, new_input[i].value);
            // printf("current_input[%d].key: %s, current_input[%d].value: %s\n", i, current_input[i].key, i, current_input[i].value);
            new_input[i+1].key = current_input[i].key;
            new_input[i+1].value = current_input[i].value;
        }

        // printf("new_input[0].key: %s, new_input[0].value: %s\n", new_input[0].key, new_input[0].value);

        free(current_input); // free mem from the old struct
        return new_input;
    }
}

Input* reduce_input(Input *input) {
    if (input == NULL) {
        printf("Empty Input \n");
        exit(1);
    }

    char *flags[] = {_FLAG}; 
    char *verbose_flags[] = {_VERBOSE_FLAG};

    Input *reduced_input = malloc(sizeof(reduced_input) * 2); // size of struct is defined

    if (reduced_input == NULL) {
        printf("error memory allocation");
        exit(1);
    }
    reduced_input->size = 2; // size of struct is defined
    printf("before_loop: %d\n", input->size);
    for (int i = 0; i < input->size; i++) {
        size_t current_input_key_len = strlen(input[i].key) + 1;
        size_t current_input_value_len = strlen(input[i].value) + 1;  
        printf("before_if_checks\n");     
        if (strncmp(flags[1], input[i].key, current_input_key_len) == 0 || strncmp(verbose_flags[1], input[i].key, current_input_key_len) == 0) {

            if (reduced_input[0].key == NULL && reduced_input[0].value == NULL) {
                reduced_input[0].key = malloc(current_input_key_len);
                reduced_input[0].value = malloc(current_input_value_len);
                if (reduced_input[0].key != NULL && reduced_input[0].value != NULL) {
                    strncpy(reduced_input[0].key, input[i].key, current_input_key_len);
                    strncpy(reduced_input[0].value, input[i].value, current_input_value_len);
                }
                else {
                    for (int j = i; j < input->size; j++) {
                        free(input[j].key);
                        free(input[j].value);
                    }
                    free(input);
                    printf("error memory allocation \n");
                    exit(1);
                }
                
                
            }
            else {
                char *current_final_value = reduced_input[0].value;
                char *current_input_value = input[i].value;
                printf("before_copy\n");
                char *copy_current_final_value = malloc(strlen(current_final_value) + 1);
                strncpy(copy_current_final_value, current_final_value, strlen(current_final_value) + 1);
                free(current_final_value);
                printf("before_concat\n");
                current_final_value = malloc(strlen(copy_current_final_value) + strlen(current_final_value) + 2); // add one more for separator
                printf("after_concat\n");
                snprintf(current_final_value, strlen(copy_current_final_value) + 1 + strlen(current_input_value), "%s,%s", copy_current_final_value, input[i].value);
                // free(copy_current_final_value);
            }
            
        }
        printf("before free i: %d, key: %s, val: %s\n", i, input[i].key, input[i].value);

        free(input[i].key);
        free(input[i].value);
    }

    free(input);    
    return reduced_input;
}

