#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: Pointer to the array of integers to be printed
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t g;

	g = 0;
	while (array != NULL && g < size)
	{
		if (g > 0)
			printf(", ");
		printf("%d", array[g]);
		++g;
	}
	printf("\n");
}
