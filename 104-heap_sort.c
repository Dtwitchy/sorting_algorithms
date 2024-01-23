#include "sort.h"

/**
 * s_position - swaps position of values in array
 * @array: array to be changed
 * @f_index: first index
 * @s_index: second index
 *
 * Return: nothing
 */
void s_position(int **array, int f_index, int s_index)
{
	int hold;

	hold = (*array)[f_index];
	(*array)[f_index] = (*array)[s_index];
	(*array)[s_index] = hold;
}

/**
 * build_Mheap - builds a heap from an array
 * @array: array to be changed to heap array
 * @e_index: end index as array is partitioned
 * @s_index: starting point index as array is sorted
 * @a_size: array size unchanged
 *
 * Return: nothing
 */
void build_Mheap(int *array, int e_index, int s_index, int a_size)
{
	int wide, up, down;

	wide = s_index;
	up = (s_index * 2) + 1;
	down = (s_index * 2) + 2;

	if (up < e_index && array[up] > array[wide])
		wide = up;

	if (down < e_index && array[down] > array[wide])
		wide = down;

	if (wide != s_index)
	{
		s_position(&array, s_index, wide);
		print_array(array, a_size);
		build_Mheap(array, e_index, wide, a_size);
	}
}

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int s_index, g;

	if (!array || size < 2)
		return;

	s_index = ((int)size - 1) / 2;

	/*Build max heap*/
	for (g = s_index; g >= 0; g--)
	{
		build_Mheap(array, size, g, size);
	}

	/*Destroy max heap and print sorted array*/
	for (g = size - 1; g > 0; g--)
	{
		s_position(&array, 0, g);
		print_array(array, size);
		build_Mheap(array, g, 0, size);
	}
}
