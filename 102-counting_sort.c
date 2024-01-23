#include "sort.h"

/**
 * gets_max - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int gets_max(int *array, int size)
{
	int gmax, f;

	for (gmax = array[0], f = 1; f < size; f++)
	{
		if (array[f] > gmax)
			gmax = array[f];
	}

	return (gmax);
}

/**
 * counting_sort - Sort an array of integers using the
 * counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, gmax, f;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	gmax = gets_max(array, size);
	count = malloc(sizeof(int) * (gmax + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (f = 0; f < (gmax + 1); f++)
		count[f] = 0;
	for (f = 0; f < (int)size; f++)
		count[array[f]] += 1;
	for (f = 0; f < (gmax + 1); f++)
		count[f] += count[f - 1];
	print_array(count, gmax + 1);

	for (f = 0; f < (int)size; f++)
	{
		sorted[count[array[f]] - 1] = array[f];
		count[array[f]] -= 1;
	}

	for (f = 0; f < (int)size; f++)
		array[f] = sorted[f];

	free(sorted);
	free(count);
}
