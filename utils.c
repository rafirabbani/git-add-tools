#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "type.h"
#include "utils.h"

static char* remove_sub_string(char* input, const char* substr, bool is_copy) {
    char *p, *q, *r;
    char* output;

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

bool key_checker(char* key) {
    char* flags[] = {_FLAG}; 
    char* verbose_flags[] = {_VERBOSE_FLAG};

    char first_char = key[0];
    char second_char = key[1];
    char flag_char = *flags[0];
    size_t key_len = strlen(key) + 1;
    char* trimmed_key;

    if ((flag_char == first_char) && (flag_char == second_char)) {
        trimmed_key = remove_sub_string(key, verbose_flags[0], false);
        // printf("trimmed_key: %s\n", trimmed_key);
        size_t size_verbose_flag = ARRAY_SIZE(verbose_flags);
        
        for (int i = 1; i < size_verbose_flag; i++) {
            size_t current_verbose_flag_len = strlen(verbose_flags[i]) + 1;
            if ((strncmp(trimmed_key, verbose_flags[i], key_len > current_verbose_flag_len ? key_len : current_verbose_flag_len)) == 0) {
                return true;
            }
        } 
    }
    else {
        trimmed_key = remove_sub_string(key, flags[0], false);
        // printf("trimmed_key: %s\n", trimmed_key);
        size_t size_flag = ARRAY_SIZE(flags);
        for (int i = 1; i < size_flag; i++) {
            if ((strncmp(trimmed_key, flags[i], key_len > size_flag ? key_len : size_flag)) == 0) {
                return true;
            }
        }
    }

    return false;  
}

static Input* create_input(char* key, char* value, int len) {
    Input* list_of_input;
    list_of_input = malloc(sizeof(Input) * len);
    if (list_of_input != NULL) {
        for (int i = 0; i < len; i++) {
            list_of_input[i].key = key;
            list_of_input[i].value = value;
            // printf("created_input \n");
            // printf("index: %d, key: %s, value: %s\n", i, list_of_input[i].key, list_of_input[i].value);
        }
        list_of_input->size = len;
        return list_of_input;
    }
    else {
        printf("error memory allocation");
        exit(1);
    }
}

Input* insert_input(Input* current_input, char* key, char* value, int index) {
    // printf("masuk with_key:%s\n", key);
    if (current_input == NULL) {
        // printf("masuk_if with_key:%s\n", key);
       Input* input = create_input(key, value, index);
       return input;        
    }
    else {
        // printf("masuk_else_1 with_key:%s\n", key);
        Input* new_input = create_input(key, value, index);
        Input* temp_current_input = current_input;
        int size_new_input = new_input->size;
        int size_current_input = current_input->size;
        // printf("masuk_else_2 with_key:%s\n", key);
        if (size_new_input < size_current_input) { // exit when mem allocation is fault
            printf("error memory allocation");
            free(new_input);  // free mem from the new struct
            free(current_input); // free mem from the old struct
            exit(1);
        }

        int i = 1;
        // printf("masuk_else_3 with_key:%s\n", key);
        // char *temp_key, *temp_value = NULL;
        // printf("masuk_else_4 with_key:%s\n", key);
        // size_t len_temp_key = strlen(new_input[0].key) + 1;
        // size_t len_temp_value = strlen(new_input[0].value) + 1;
        // temp_key = malloc(sizeof(new_input[0].key));
        // temp_value = malloc(sizeof(new_input[0].value));
        // strncpy(temp_key, new_input[0].key, len_temp_key);
        // strncpy(temp_value, new_input[0].value, len_temp_value);


        while (i < size_new_input) {
            for (int j = 0; j < size_current_input; j++) { 
                new_input[i].key = temp_current_input[j].key;
                new_input[i].value = temp_current_input[j].value;
                i++;
            }
        }

        // char* temp_key = new_input->key;

        // TODO debug this so we can use only 1 loop and the array doesn't change the sequence
        // for (int i = 0; i < size_new_input; i++) { 
        //     printf("i: %d \n", i);
        //     if (i == (size_new_input - 1)) {
        //         new_input[i].key = temp_key;
        //         new_input[i].value = temp_value;
        //         free(temp_key);
        //         free(temp_value);
        //         break;
        //     }

        //     new_input[i].key = temp_current_input[i].key;
        //     new_input[i].value = temp_current_input[i].value;       
            
        // } 
        // if (temp_key != NULL) {
        //     printf("masuk_temp_key \n");
        //     free(temp_key);
        // }

        // if (temp_value != NULL) {
        //     printf("masuk_temp_value \n");
        //     free(temp_value);
        // }
        free(current_input); // free mem from the old struct
        return new_input;
    }
}

// TODO: create reducer for structs input