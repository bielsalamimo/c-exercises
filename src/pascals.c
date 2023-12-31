/* NOTE: No idea how the hell I should do this */
#include <stdio.h>

#define UNUSED(a)   \
    do {            \
        (void) (a); \
    } while(0)

int main(int argc, char **argv)
{
    UNUSED(argc);
    UNUSED(argv);

    unsigned long int pascal[100];
    pascal[0] = 1;

    pascal[1] = 1;
    pascal[2] = 1;

    pascal[3] = 1;
    pascal[4] = pascal[1] + pascal[2];
    pascal[5] = 1;

    pascal[6] = 1;
    pascal[7] = pascal[3] + pascal[4];
    pascal[8] = pascal[4] + pascal[5];
    pascal[9] = 1;

    for (int i = 0; i <= 9; i++) {
        printf("%ld\n", pascal[i]);
    }
    return 0;
}
