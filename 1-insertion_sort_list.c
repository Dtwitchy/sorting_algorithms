#include "sort.h"

/**
 * swaps_node - swaps two nodes
 * in a listint_t doubly-linked list.
 *
 * @h: points the head of the doubly-linked list.
 *
 * @fn: points the 1st node to swap.
 *
 * @sn: points the second node to swap.
 *
 */

void swaps_node(listint_t **h, listint_t **fn, listint_t *sn)
{
	(*fn)->next = sn->next;
	if (sn->next != NULL)
		sn->next->prev = *fn;
	sn->prev = (*fn)->prev;
	sn->next = *fn;
	if ((*fn)->prev != NULL)
		(*fn)->prev->next = sn;
	else
		*h = sn;
	(*fn)->prev = sn;
	*fn = sn->prev;
}

/**
 * insertion_sort_list - This func sorts a doubly linked list
 * of integers using the insertion sort algorithm.
 *
 * @list: points the head of a
 * doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swaps_node(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
