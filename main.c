#include "shell.h"

int main()
{
    while (true) {
        printf("> ");
        char *line = kash_read_line();
        char **tokens = kash_split_line(line);

        if (tokens[0] != NULL) {
            kash_exec(tokens);
        }

        free(tokens);
        free(line);
    }
    return 0;
}
