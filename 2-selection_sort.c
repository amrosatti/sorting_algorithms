#include "sort.h"

/**
 * selection_sort - Sort an array on integers using `Selection Sort` algorithm
 *
 * @array: Array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, l;

	for (i = 0; i < size - 1; i++)
	{
		l = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[l])
				l = j;

		if (l != i)
		{
			swap(&array[i], &array[l]);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swap two integers values
 *
 * @x: First integer
 * @y: Second integer
 */
void swap(int *x, int *y)
{
	int z = *x;

	*x = *y;
	*y = z;
}
