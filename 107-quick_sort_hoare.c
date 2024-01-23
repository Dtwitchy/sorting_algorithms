#include "sort.h"

void swaps_ints(int *g, int *h);
int hoare_par(int *array, size_t size, int start, int end);
void hoare_stecur(int *array, size_t size, int start, int end);
void quick_sort_hoare(int *array, size_t size);

/**
 * swaps_ints - This func will swap
 * two integers in an array.
 *
 * @g: This is the 1st int to swap.
 *
 * @h: This is the 2nd int to swap.
 *
 */

void swaps_ints(int *g, int *h)
{
	int tmp;

	tmp = *g;
	*g = *h;
	*h = tmp;
}

/**
 * hoare_par - This func orders a subset of an array
 * of int according to the hoare partition scheme.
 *
 * @array: This is the array of int
 *
 * @size: This is the size of the array.
 *
 * @start: This is the starting index of the subset
 *
 * @end: This is the ending index of the subset
 *
 * Return: Final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 *
 */

int hoare_par(int *array, size_t size, int start, int end)
{
	int pivot, up, down;

	pivot = array[end];
	for (up = start - 1, down = end + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swaps_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_srecur - implements the quick sort
 * algorithm through recursion.
 *
 * @array: This is an array of int to sort.
 *
 * @size: This is the size of the array.
 *
 * @start: This is the starting index of the array partition
 *
 * @end: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 *
 */

void hoare_srecur(int *array, size_t size, int start, int end)
{
	int newp;

	if (end - start > 0)
	{
		newp = hoare_par(array, size, start, end);
		hoare_srecur(array, size, start, newp - 1);
		hoare_srecur(array, size, newp, end);
	}
}

/**
 * quick_sort_hoare - This func will sort an array of int
 * in ascending order using the quicksort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_srecur(array, size, 0, size - 1);
}
