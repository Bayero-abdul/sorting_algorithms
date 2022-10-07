#include "sort.h"


/**
 * bubble_sort - that sorts an array of integers in ascending order
 * in O(n^2) time
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	if (size == 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
