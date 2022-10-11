#include "sort.h"


/**
 * bubble_sort - that sorts an array of integers in ascending order
 * in O(n^2) time
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n, is_sorted;
	int temp;

	if (size < 2)
		return;

	n = size;
	for (i = 0; i < size; i++)
	{
		is_sorted = 1;
		for (j = 1; j < n; j++)
		{

			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
				is_sorted = 0;
			}
		}
		n = n - 1;
		if (is_sorted)
			break;
	}
}
