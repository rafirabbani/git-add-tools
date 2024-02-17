#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug_utils/debug_utils.h"
#include "type.h"
#include "git_calls.h"


void git_status(char *cmd, Input* input) {
    char output[BUFFER_SIZE] = {0};
    // char *_git_keys[] = {GIT_STATUS_KEY};
    FILE *output_stream;
    // Input *git_output = malloc(sizeof(Input));
    // git_output->key = "output";
    // git_output->size = 1;

    if ((output_stream = popen(cmd, "r")) == NULL) {
        printf("Error executing git status\n");
        exit(1);
    }

    while((fgets(output, BUFFER_SIZE, output_stream)) != NULL) {
        printf("%s", output);
        size_t current_buffer_len = strlen(output) + 1;


    }

    if(pclose(output_stream)) {
        printf("Command not found or exited with error status\n");
        exit(1);
    }
    // return output_stream;
}