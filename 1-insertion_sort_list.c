#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *			in ascending order using `Insertion Sort` algorithm
 *
 * @list: List to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL, *tmp, *current;

	if (!(*list) || !(*list)->next)
		return;

	current = *list;
	while (current)
	{
		tmp = current->next;
		current->prev = current->next = NULL;

		insert_sort(&sorted_list, current);
		print_list(sorted_list);

		current = tmp;
	}

	*list = sorted_list;
}

/**
 * insert_sort - Inserts the node to the currect position of the sorted portion
 *
 * @head: Head of the sorted list
 * @node: Node to be inserted
 */
void insert_sort(listint_t **head, listint_t *node)
{
	listint_t *cursor;

	if (!(*head))
		*head = node;
	else if ((*head)->n >= node->n)
	{
		node->next = *head;
		node->next->prev = node;
		*head = node;
	}
	else
	{
		cursor = *head;

		while (cursor->next && cursor->next->n < node->n)
			cursor = cursor->next;

		node->next = cursor->next;

		if (cursor->next)
			node->next->prev = node;

		cursor->next = node;
		node->prev = cursor;
	}
}
