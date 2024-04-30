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

