#include "../sort.h"

/**
 * main - Tests bubble sort
 *
 * Return - Always 0
 */
int main(void)
{
	double time1, timedif;
	int array[] = { 89, 20, 80, 66, 16, 84, 13, 18,
		68, 40, 62, 37, 79, 56, 58, 94, 41, 75,
		88, 45, 3, 86, 46, 65, 81, 63, 30, 87,
		55, 53, 33, 98, 82, 83, 51, 50, 74, 12,
		5, 99, 96, 27, 22, 69, 19, 70, 93, 29,
		71, 35 };
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");

	time1 = (double) clock();
	time1 /= CLOCKS_PER_SEC;

	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);

	timedif = (((double) clock()) / CLOCKS_PER_SEC) - time1;
	
	printf("\n\n\n");
	printf("running time: %f seconds\n", timedif);
	return (0);
}
