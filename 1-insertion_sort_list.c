#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *			in ascending order using `Insertion Sort` algorithm
 *
 * @list: List to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *current, *insert_point;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;

		insert_point = current->prev;
		while (insert_point && insert_point->n > current->n)
			insert_point = insert_point->prev;

		if (insert_point != current->prev)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			if (!insert_point)
			{
				current->prev = NULL;
				current->next = *list;
				(*list)->prev = current;
				*list = current;
			}
			else
			{
				current->next = insert_point->next;
				insert_point->next = current;
				current->prev = insert_point;
				current->next->prev = current;
			}
			print_list(*list);
		}

		current = next;
	}
}
