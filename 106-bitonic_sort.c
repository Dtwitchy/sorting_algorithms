#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_arr - prints an array
 * @array: given array
 * @low: lower boundary
 * @high: upper boundary
 */
void print_arr(int *array, int low, int high)
{
	char *dil;

	for (dil = ""; low <= high; low++)
	{
		printf("%s%d", dil, array[low]);
		dil = ", ";
	}
	printf("\n");
}

/**
 * swaps_dir - swaps two elements if they are in the
 * specified bitonic direction
 * @array: given array
 * @e1: first element
 * @e2: second element
 * @dir: direction 1 for UP and 0 for DOWN
 */
void swaps_dir(int *array, int e1, int e2, int dir)
{
	int data;

	if (dir == (array[e1] > array[e2]))
	{
		data = array[e1];
		array[e1] = array[e2];
		array[e2] = data;
	}
}

/**
 * merge_seq - merge sequence bitonically
 * @array: given array
 * @low: lower boundary
 * @high: high boundary
 * @dir: direction 1 for UP and 0 for DOWN
 * @size: array size
 */
void merge_seq(int *array, size_t low, size_t high, int dir, size_t size)
{
	size_t mid, g, h;

	if (high - low < 1)
		return;

	mid = (low + high) / 2;
	for (g = low, h = mid + 1; g <= mid; g++, h++)
		swaps_dir(array, g, h, dir);

	merge_seq(array, low, mid, dir, size);
	merge_seq(array, mid + 1, high, dir, size);
}

/**
 * makes_seq - make bitonic sequence
 * @array: given array
 * @low: lower boundary
 * @high: high boundary
 * @dir: direction 1 for UP and 0 for DOWN
 * @size: array size
 */
void makes_seq(int *array, size_t low, size_t high, int dir, size_t size)
{
	char *direction;
	size_t mid;

	if (high - low < 1)
		return;

	direction = dir ? "UP" : "DOWN";
	printf("Merging [%ld/%ld] (%s):\n", high - low + 1, size, direction);
	print_arr(array, low, high);

	mid = (low + high) / 2;
	makes_seq(array, low, mid, 1, size);
	makes_seq(array, mid + 1, high, 0, size);

	merge_seq(array, low, high, dir, size);
	printf("Result [%ld/%ld] (%s):\n", high - low + 1, size, direction);
	print_arr(array, low, high);
}

/**
 * bitonic_sort -  sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: given array
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	makes_seq(array, 0, size - 1, 1, size);
}
