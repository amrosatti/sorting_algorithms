#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to print
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i >= 1)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to print
 */
void print_list(const listint_t *list)
{
	int i;

	for (i = 0; list; i++, list = list->next)
	{
		if (i)
			printf(", ");
		printf("%d", list->n);
	}
	printf("\n");
}

/**
 * create_dlist - Creates a doubly linked list from a given array
 *
 * @array: Array to convert
 * @size: Size of the array
 *
 * Return: Pointer to head of the list, NULL otherwise
 */
listint_t *create_dlist(const int *array, size_t size)
{
	listint_t *head, *node;
	int *tmp;

	head = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(head);
			return (NULL);
		}

		tmp = (int *)&node->n;
		*tmp = *(array + size);

		node->next = head;
		node->prev = NULL;
		head = node;
		if (head->next)
			head->next->prev = head;
	}

	return (head);
}

/**
 * free_list - Frees a doubly linked list from memory
 *
 * @head: Head of the list
 */
void free_list(listint_t *head)
{
	if (!head)
		return;

	free_list(head->next);

	head->prev = NULL;
	free(head);
	head = NULL;
}
