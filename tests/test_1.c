#include "../sort.h"

/**
 * main - Tests sorting a doubly linked list using `Insertions Sort` algorithm
 *
 * Return: 0 on success
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(*array);

	list = create_dlist(array, n);
	if (!list)
		exit(EXIT_FAILURE);

	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	free_list(list);

	exit(EXIT_SUCCESS);
}
