#include <stdio.h>
#include <string.h>

#include "compiler/comet.h"

int main(int argc, char *argv[]) {
    char *arg = argv[1];
    if (arg != NULL && strstr(arg, ".cml") != NULL) {
        run_file(arg);
    } else {
        printf("error reading file");
        printf("%s", arg);
        run_prompt();
    }
}
