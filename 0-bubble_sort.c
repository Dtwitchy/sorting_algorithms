#include "sort.h"

/**
 * swaps_int - Swaps integers of values in array.
 * @f: first integer to swap.
 * @s: second integer to swap.
 */
void swaps_int(int *f, int *s)
{
	int tmp;

	tmp = *f;
	*f = *s;
	*s = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t g, len = size;
	bool swap = false;

	if (array == NULL || size < 2)
		return;

	while (!swap)
	{
		swap = true;
		for (g = 0; g < len - 1; g++)
		{
			if (array[g] > array[g + 1])
			{
				swaps_int(array + g, array + g + 1);
				print_array(array, size);
				swap = false;
			}
		}
		len--;
	}
}
