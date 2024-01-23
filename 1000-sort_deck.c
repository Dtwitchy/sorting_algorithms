#include "deck.h"

int c_str(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void sort_deck_card(deck_node_t **deck);
void sort_deck_dia(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * c_str - This func compares two str
 *
 * @s1: This is the 1st str to compare
 *
 * @s2: This is the 2nd str to compare
 *
 * Return: Positive byte difference if s1 > s2 0 if s1 == s2
 * Negative byte difference if s1 < s2
 *
 */

int c_str(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - This func gets the numerical value of a card
 *
 * @card: Represents a pointer to a deck_node_t card.
 *
 * Return: Represents a numerical value of the card.
 *
 */

char get_value(deck_node_t *card)
{
	if (c_str(card->card->value, "Ace") == 0)
		return (0);
	if (c_str(card->card->value, "1") == 0)
		return (1);
	if (c_str(card->card->value, "2") == 0)
		return (2);
	if (c_str(card->card->value, "3") == 0)
		return (3);
	if (c_str(card->card->value, "4") == 0)
		return (4);
	if (c_str(card->card->value, "5") == 0)
		return (5);
	if (c_str(card->card->value, "6") == 0)
		return (6);
	if (c_str(card->card->value, "7") == 0)
		return (7);
	if (c_str(card->card->value, "8") == 0)
		return (8);
	if (c_str(card->card->value, "9") == 0)
		return (9);
	if (c_str(card->card->value, "10") == 0)
		return (10);
	if (c_str(card->card->value, "Jack") == 0)
		return (11);
	if (c_str(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_card - This fun will sort
 * a deck of cards from spades to diamonds
 *
 * @deck: Represents a pointer to the head of a
 * deck_node_t doubly-linked list
 *
 */

void sort_deck_card(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck_dia - This func sorts a deck of cards sorted
 * from spades to diamonds from ace to king.
 *
 * @deck: Represents a pointer to the head of a
 * deck_node_t doubly-linked list.
 *
 */

void sort_deck_dia(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - This func sorts a deck of cards from ace to
 * king and from spades to diamonds.
 *
 * @deck: Represents a pointer to the head of a
 * deck_node_t doubly-linked list.
 *
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_card(deck);
	sort_deck_dia(deck);
}
