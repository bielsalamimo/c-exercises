/* NOTE: This is a horrible approach. Pls fix */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED(a) 		\
	do { 			\
		(void) (a);	\
	} while(0)

typedef struct {
	size_t rows_count;
	unsigned long int *data_array;
	size_t data_size;
} PascalTriangle;

int main(int argc, char **argv)
{
	UNUSED(argc);
	UNUSED(argv);

	PascalTriangle p = {0};
	p.rows_count = 10;

	for (int i = 1; i <= p.rows_count; i++) {
		p.data_size += i;
	}

	p.data_array = malloc(sizeof(unsigned long int) * 1000);
	memset(p.data_array, 0, sizeof(unsigned long int) * 1000);
	
	// Find index of data_array that should be 1s
	for (int i = 1; i <= p.data_size; i++) {
		p.data_array[(i*i-i)/2] = 1;
		if (i != 1) {
			p.data_array[(i*i+i)/2 - 1] = 1;
		}
	}

	for (int row = 1; row <= p.rows_count; row++) {
		printf("ROW %d\n", row);
		for (int i = 0; i < row; i++) {
			printf("%ld", *p.data_array);
			p.data_array++;
		}
		printf("\n");
	}

	return 0;
}
