#include "sort.h"

int gets_max(int *array, int size);
void radix_csort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * gets_max - This func gets maximum value in an array of int
 *
 * @array: This an array of int
 *
 * @size: This is the size of the array.
 *
 * Return: The max int in the array.
 *
 */

int gets_max(int *array, int size)
{
	int max, index;

	for (max = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * radix_csort - This func will sort the significant
 * digits of an array of int in ascending order using
 * counting sort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * @sig: This is the significant digit to sort on.
 *
 * @buff: Represents the buffer to store the sorted array.
 *
 */

void radix_csort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < size; index++)
		count[(array[index] / sig) % 10] += 1;

	for (index = 0; index < 10; index++)
		count[index] += count[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		buff[count[(array[index] / sig) % 10] - 1] = array[index];
		count[(array[index] / sig) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		array[index] = buff[index];
}

/**
 * radix_sort - This func will sort an array of int
 * in ascending order using the radix sort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * Description: Only implements the LSD radix sort algorithm.
 * Prints the array after each significant digit increase.
 *
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = gets_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_csort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
