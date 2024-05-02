#include "../sort.h"

/**
 * main - Tests sorting a doubly linked list using `Insertions Sort` algorithm
 *
 * Return: 0 on success
 */
int main(void)
{
	listint_t *list;
	int array[] = { 82, 65, 67, 19, 15, 63, 51,
			5, 80, 96, 55, 46, 70, 59,
			26, 90, 32, 60, 57, 4, 53,
			87, 74, 21, 10, 71, 62, 24,
			40, 13, 16, 69, 47, 31, 58,
			33, 41, 42, 52, 44, 86, 6,
			39, 100, 45, 25, 20, 97, 83, 1 };
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
