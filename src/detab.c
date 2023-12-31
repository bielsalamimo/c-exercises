#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABSTOP 8

void detab(char *to, char *from, size_t tabstop);

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
// Also this just looks ugly as shit
// At this point should rewrite it
void detab(char *to, char *from, size_t tabstop)
{
    int tabstop_next = tabstop;
    size_t from_size = strlen(from);

    int i_to = 0;
    int i_from = 0;

    while (i_from < from_size) {
        if (from[i_from] != '\t') {
            to[i_to] = from[i_from];
            tabstop_next--;
            i_to++;
            i_from++;
        } else {
            for (int i = 0; i <= tabstop_next; i++) {
                to[i_to + i] = ' ';
            }
            i_to += tabstop_next;
            i_from++;
            tabstop_next = tabstop;
        }

        if (tabstop_next == 0) {
            tabstop_next = tabstop;
        }
    }

    to[i_to] = '\0';
}
