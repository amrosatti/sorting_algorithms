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
	int sorted;

	if (!list)
		return;
	if (!(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		insert_point = current->prev;

		while (insert_point && insert_point->n > current->n)
			insert_point = insert_point->prev;

		sorted = is_sorted(insert_point == current->prev, current);

		if (!sorted)
		{
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
		}

		print_list(*list);
		current = next;
	}
}

/**
 * is_sorted - Check if positions are already sorted and switch links
 *
 * @isit: True if sorted, 0 otherwise
 * @node: Node to orphan
 *
 * Return: 1 if sorted, 0 otherwise
 */
int is_sorted(int isit, listint_t *node)
{
	if (isit)
		return (1);

	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	return (0);
}
