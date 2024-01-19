#include "sort.h"

/**
 * swaps_post - swaps the positions of values in array
 *
 * @array: array to be modified
 * @fi: first index
 * @si: second index
 */
void swaps_post(int **array, size_t fi, size_t si)
{
	int temp;

	temp = (*array)[fi];
	(*array)[fi] = (*array)[si];
	(*array)[si] = temp;
}

/**
 * selection_sort - sorts an array using the selection
 * sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t g, h;
	int current_min, min_index, swap;

	if (size < 2)
		return;

	for (g = 0; g < size; g++)
	{
		current_min = array[g];
		min_index = g;
		swap = 0;

		for (h = g + 1; h < size; h++)	/* start from the unsorted part */
		{
			if (current_min > array[h])  /* check for min value */
			{
				current_min = array[h];
				min_index = h;
				swap = 1;
			}
		}

		if (swap)
		{
			swaps_post(&array, g, min_index);
			print_array(array, size);
		}
	}
}
