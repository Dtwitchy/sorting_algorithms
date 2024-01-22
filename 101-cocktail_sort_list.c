#include "sort.h"

void swaps_nodea(listint_t **list, listint_t **ptail, listint_t **shake);
void swaps_nodeb(listint_t **list, listint_t **ptail, listint_t **shake);
void cocktail_sort_list(listint_t **list);

/**
 * swaps_nodea - swaps a node in a listint_t
 * doubly-linked list of int with the node ahead of it.
 *
 * @list: pointer to the head of a
 * doubly-linked list of integers.
 *
 * @ptail: pointer to the tail of
 * the doubly-linked list.
 *
 * @pshake: pointer to the current
 * swapping node of the cocktail shaker algo.
 *
 */

void swaps_nodea(listint_t **list, listint_t **ptail, listint_t **pshake)
{
	listint_t *tmp = (*pshake)->next;

	if ((*pshake)->prev != NULL)
		(*pshake)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*pshake)->prev;
	(*pshake)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *pshake;
	else
		*ptail = *pshake;
	(*pshake)->prev = tmp;
	tmp->next = *pshake;
	*pshake = tmp;
}

/**
 * swaps_nodeb - swaps a node in a listint_t
 * doubly-linked list of integers with the node behind it.
 *
 * @list: pointer to the head of a
 * doubly-linked list of integers.
 *
 * @ptail: pointer to the tail of the doubly-linked list.
 *
 * @pshake: pointer to the current swapping node
 * of the cocktail shaker algo.
 *
 */

void swaps_nodeb(listint_t **list, listint_t **ptail, listint_t **pshake)
{
	listint_t *tmp = (*pshake)->prev;

	if ((*pshake)->next != NULL)
		(*pshake)->next->prev = tmp;
	else
		*ptail = tmp;
	tmp->next = (*pshake)->next;
	(*pshake)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *pshake;
	else
		*list = *pshake;
	(*pshake)->next = tmp;
	tmp->prev = *pshake;
	*pshake = tmp;
}

/**
 * cocktail_sort_list - This func sorts a listint_t doubly-linked list of int
 *  in ascending order using the cocktail shaker algorithm.
 *
 * @list: pointer to the head of a listint_t doubly-linked list.
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptail, *pshake;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ptail = *list; ptail->next != NULL;)
		ptail = ptail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (pshake = *list; pshake != ptail; pshake = pshake->next)
		{
			if (pshake->n > pshake->next->n)
			{
				swaps_nodea(list, &ptail, &pshake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (pshake = pshake->prev; pshake != *list;
				pshake = pshake->prev)
		{
			if (pshake->n < pshake->prev->n)
			{
				swaps_nodeb(list, &ptail, &pshake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
