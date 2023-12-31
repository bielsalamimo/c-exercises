#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detab(char *to, char *from, size_t tabstop);

#define TABSTOP 8

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "[ERROR] Please provide arguments\n");
        exit(1);
    }
    char *filename = (char *) malloc(sizeof(*filename) * FILENAME_MAX);
    filename = argv[1];
    char *filename_out = (char *) malloc(sizeof(*filename_out) * FILENAME_MAX);
    filename_out = argv[2];

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

    char *file_content = (char *) malloc(sizeof(*file_content) * file_size);
    fread(file_content, 1, file_size, file_ptr);
    fclose(file_ptr);

    char detabbed[file_size];
    detab(detabbed, file_content, TABSTOP);
    printf("%d\n", argc);
    FILE *file_out_ptr = fopen(filename_out, "w");
    if (!file_out_ptr) {
        fprintf(stderr, "[ERROR] File '%s' not found\n", filename_out);
        exit(1);
    }
    fprintf(file_out_ptr, "%s", detabbed);

    return 0;
}

// TODO: Make this shit deal with newlines itself,
// this garbage only works when _from_ points to a single line,
// if its more than a line, it fucks up the tabstops.
void detab(char *to, char *from, size_t tabstop)
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
