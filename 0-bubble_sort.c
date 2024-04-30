#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 *		in ascending order using `Bubble Sort` Algorithm
 * @array: Sortable data
 * @size: Size of @array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, n = size;

	do {
		swapped = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				swapped += 1;
			}
		}
		n -= 1;
	} while (swapped);
}

/**
 * swap - Swaps two integers values
 * @n: ...
 * @m: ...
 */
void swap(int *n, int *m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}
