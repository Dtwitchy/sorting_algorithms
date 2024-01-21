#include "sort.h"

/**
 * f_pow - find the power of a number
 * @y: the base number
 * @z: the value of power
 *
 * Return: the power of y
 */
int f_pow(int y, size_t z)
{
	if (z == 0)
		return (1);

	return (y * f_pow(y, z - 1));
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
	size_t i = 0;
	int g = 0, curr_term, *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	curr_term = 0;
	while (i < size)
	{
		curr_term = curr_term + f_pow(3, i);
		sequence[g] = curr_term;
		i++;
		g++;
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
	size_t g = 0, ind_sequence;

	rev_seq = malloc(sizeof(int) * size);
	if (rev_seq == NULL)
		return (NULL);

	ind_sequence = size - 1;
	while (g < size)
	{
		rev_seq[g] = sequence[ind_sequence];
	       g++;
	       ind_sequence--;
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
	int h, flag = 0;
	int temp, *sequence, *rev_seq, gap;
	size_t g, ind_sequence = 0;

	sequence = gen_sequence(size);
	if (sequence == NULL)
		return;

	rev_seq = rev_sequence(sequence, size);
	if (rev_seq == NULL)
		return;

	while (ind_sequence < size)
	{
		for (g = rev_seq[ind_sequence]; g < size; g++)
		{
			temp = array[g];
			gap = rev_seq[ind_sequence];
			for (h = g; h >= gap && array[h - gap] > temp; h -= gap)
			{
				array[h] = array[h - rev_seq[ind_sequence]];
			}
			array[h] = temp;
			flag = 1;
		}
		if (flag)
			print_array(array, size);
		ind_sequence++;
	}
	free(sequence);
	free(rev_seq);
}
