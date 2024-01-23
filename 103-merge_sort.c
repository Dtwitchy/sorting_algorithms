#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t f_index, size_t m_index,
		size_t b_index);
void merge_sort_rec(int *subarr, int *buff, size_t f_index, size_t b_idex);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - merges sorted  subarrays of integers
 *
 * @subarr: subarray of an array of integers to sort.
 *
 * @buff: buffer to store the sorted subarray.
 *
 * @f_index: front index of the array.
 *
 * @m_index: middle index of the array.
 *
 * @b_index: back index of the array.
 *
 */

void merge_subarr(int *subarr, int *buff, size_t f_index, size_t m_index,
		size_t b_index)
{
	size_t g, h, i = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + f_index, m_index - f_index);

	printf("[right]: ");
	print_array(subarr + m_index, b_index - m_index);

	for (g = f_index, h = m_index; g < m_index && h < b_index; i++)
		buff[i] = (subarr[g] < subarr[h]) ? subarr[g++] : subarr[h++];
	for (; g < m_index; g++)
		buff[i++] = subarr[g];
	for (; h < b_index; h++)
		buff[i++] = subarr[h];
	for (g = f_index, i = 0; g < b_index; g++)
		subarr[g] = buff[i++];

	printf("[Done]: ");
	print_array(subarr + f_index, b_index - f_index);
}

/**
 * merge_sort_rec - Recursive function to implement
 * the merge sort algorithm.
 *
 * @subarr: subarray of an array of integers to sort.
 *
 * @buff: buffer to store the sorted result.
 *
 * @f_index: front index of the subarray.
 *
 * @b_index: back index of the subarray.
 *
 */

void merge_sort_rec(int *subarr, int *buff, size_t f_index, size_t b_index)
{
	size_t m_index;

	if (b_index - f_index > 1)
	{
		m_index = f_index + (b_index - f_index) / 2;
		merge_sort_rec(subarr, buff, f_index, m_index);
		merge_sort_rec(subarr, buff, m_index, b_index);
		merge_subarr(subarr, buff, f_index, m_index, b_index);
	}
}

/**
 * merge_sort - sorts an array of int
 * in ascending order using merge sort algorithm.
 *
 * @array: This is an array of integers.
 *
 * @size: This is the size of the array.
 *
 * Description: only implements the top-down merge sort algorithm.
 *
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_rec(array, buff, 0, size);

	free(buff);
}
