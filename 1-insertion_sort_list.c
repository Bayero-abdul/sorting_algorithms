#include "sort.h"

/**
 * insertion_sort_list - Sorts list in ascending order
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *walk = NULL, *next = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	walk = (*list)->next;
	while (walk)
	{
		next = walk->next;
		temp = walk->prev;
		while (temp && walk->n < temp->n)
		{
			walk->next = temp;
			walk->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = walk;

			temp->prev = walk;
			temp->next = next;
			if (temp->next)
				temp->next->prev = temp;

			if (walk->prev == NULL)
				*list = walk;
			print_list(*list);
			temp = walk->prev;
			next = walk->next;
		}
		walk = walk->next;
	}
}
