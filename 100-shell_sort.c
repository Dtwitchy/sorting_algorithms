#include "sort.h"

/**
 * cal_pow - calculate the power of a number
 * @y: the base number
 * @z: the value of power
 *
 * Return: the power of y
 */
int cal_pow(int y, size_t z)
{
	if (z == 0)
		return (1);

	return (y * cal_pow(y, z - 1));
}

/**
 * gen_sequence - generates a sequence base
 * on power of 3
 * @size: size of sequence
 *
 * Return: pointer to the generated sequence
 */
int *gen_sequence(size_t size)
{
	size_t i;
	int *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		sequence[i] = cal_pow(3, i);
	}
	return (sequence);
}

/**
 * rev_sequence - reverses a given sequence
 * @sequence: pointer to the sequence to be reversed
 * @size: size of the sequence
 *
 * Return: sequence in reverse
 */
int *rev_sequence(int *sequence, size_t size)
{
	int *rev_seq;
	size_t g = 0;

	rev_seq = malloc(sizeof(int) * size);
	if (rev_seq == NULL)
		return (NULL);

	for (g = 0; g < size; g++)
	{
		rev_seq[g] = sequence[size - g - 1];
	}
	return (rev_seq);
}

/**
 * shell_sort - sorts an array using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, temp, *sequence, *rev_seq;
	size_t g, h, gap;

	sequence = gen_sequence(size);
	if (sequence == NULL)
		return;

	rev_seq = rev_sequence(sequence, size);
	if (rev_seq == NULL)
	{
		free(sequence);
		return;
	}

	for (g = 0; g < size; g++)
	{
		gap = rev_seq[g];


		for (h = gap; h < size; h++)
		{
			temp = array[h];
			for (i = g; i >= (int)gap && array[i - gap] > temp; i -= gap)
			{
				array[i] = array[i - gap];
			}
			array[g] = temp;
		}
		print_array(array, size);
	}

	free(sequence);
	free(rev_seq);
}
