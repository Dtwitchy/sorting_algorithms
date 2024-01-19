#include "sort.h"

void swaps_intes(int *y, int *p);
int l_partition(int *array, size_t size, int up, int down);
void l_sorter(int *array, size_t size, int up, int down);
void quick_sort(int *array, size_t size);

/**
 * swaps_intes - swaps two integers in an array.
 *
 * @f: The 1st integer to swap.
 *
 * @s: The 2nd integer to swap.
 *
 */

void swaps_intes(int *f, int *s)
{
	int tmp;

	tmp = *f;
	*f = *s;
	*s = tmp;
}

/**
 * l_partition - Orders a subset of an array
 * using a partition scheme.
 *
 * @array: the array of int
 * @size: the size of the array.
 * @up: starting index of the subset to order.
 * @down: the ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 */

int l_partition(int *array, size_t size, int up, int down)
{
	int *pivot = array + down;
	int l, r;

	for (l = r = up; r < down; r++)
	{
		if (array[r] < *pivot)
		{
			if (l < r)
			{
				swaps_intes(array + r, array + l);
				print_array(array, size);
			}
			l++;
		}
	}

	if (array[l] > *pivot)
	{
		swaps_intes(array + l, pivot);
		print_array(array, size);
	}

	return (l);
}

/**
 * l_sorter - This func implements the
 * quicksort algorithm through recursion.
 *
 * @array: represents an array of integers to sort.
 *
 * @size: represents the size of the array.
 *
 * @up: The starting index of the array
 * partition to order.
 *
 * @down: The ending index of the array
 * partition to order.
 *
 * Description: using the Lomuto partition scheme.
 *
 */

void l_sorter(int *array, size_t size, int up, int down)
{
	int p_index;

	if (down - up > 0)
	{
		p_index = l_partition(array, size, up, down);
		l_sorter(array, size, up, p_index - 1);
		l_sorter(array, size, p_index + 1, down);
	}
}

/**
 * quick_sort - sorts a given using
 * the quicksort algorithm.
 *
 * @array: the array to be sorted
 *
 * @size: the size of the array.
 *
 * Description: Makes use of the Lomuto partition scheme,
 * Prints the array after each swap of two elements.
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	l_sorter(array, size, 0, size - 1);
}
