#include "sort.h"

/**
 * quick_sort - Sorts array of integers usin `Quick Sort` algortithm
 *
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	recursive_quicksort(array, size, 0, size - 1);
}

/**
 * recursive_quicksort - Implement the quick sort recursively
 *
 * @array: Array
 * @lo: Lowest index
 * @hi: Highest index
 */
void recursive_quicksort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, size, lo, hi);

		recursive_quicksort(array, size, lo, p - 1);
		recursive_quicksort(array, size, p + 1, hi);
	}
}

/**
 * partition - Divides @array into two partitions,
 *		using `Lomuto Sceeme`
 *
 * @array: Array
 * @lo: Lowest index
 * @hi: Highest index
 *
 * Return: Index of the pivot
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot = array[hi];

	i = lo - 1;
	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[hi]);
	print_array(array, size);

	return (i + 1);
}

/**
 * swap - Swaps two integers
 *
 * @x: ...
 * @y: ...
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
