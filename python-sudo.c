#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv){
    if(setuid(0)) {
        printf("setuid() error: %d", errno);
        return -1;
    }
    
    // Absolute path to venv bin directory containing the current python interpreter
    char* py = "";

    char** param_list = malloc(sizeof(char*) * (argc + 1));
    memcpy(param_list, argv, sizeof(char*) * (argc));
    param_list[0] = py;
    param_list[argc] = NULL;
    

    if(execv(py, param_list)) {
        printf("execve() error: %d", errno);
        return -1;
    }

    free(param_list);
    param_list = NULL;
}
