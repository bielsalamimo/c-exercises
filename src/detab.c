#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detab(char *to, char *from, int tabstop)
{
    int next_tabstop = tabstop;
    size_t from_size = strlen(from);

    int to_i = 0;
    int from_i = 0;

    while (from_i < from_size) {
        if (from[from_i] != '\t') {
            to[to_i] = from[from_i];
            next_tabstop--;
            to_i++;
            from_i++;
        } else {
            for (int i = 0; i <= next_tabstop; i++) {
                to[to_i + i] = ' ';
            }
            to_i += next_tabstop;
            from_i++;
            next_tabstop = tabstop;
        }

        if (next_tabstop == 0) {
            next_tabstop = tabstop;
        }
    }

    to[to_i] = '\0';
}

#define MAX_SIZE 4096
#define TABSTOP 8

int main(int argc, char **argv)
{
    if (argc <= 1) {
        fprintf(stderr, "[ERROR] Please provide input file\n");
        exit(1);
    }
    char *filename = (char *) malloc(sizeof(*filename) * MAX_SIZE);
    filename = argv[1];
    char detabbed[MAX_SIZE] = {0};

    char *file_content = (char *) malloc(sizeof(*file_content) * MAX_SIZE);
    size_t file_size = 0;
    FILE *file_ptr;
    file_ptr = fopen(filename, "r");
    if (!file_ptr)  {
        fprintf(stderr, "[ERROR] File '%s' not found\n", filename);
        exit(1);
    }
    fseek(file_ptr, 0, SEEK_END);
    file_size = ftell(file_ptr);
    rewind(file_ptr);
    file_content = (char *) malloc(sizeof(*file_content) * file_size);
    fread(file_content, 1, file_size, file_ptr);
    fclose(file_ptr);

    detab(detabbed, file_content, TABSTOP);

    printf("%s", detabbed);

    return 0;
}
