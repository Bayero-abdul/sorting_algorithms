#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort
 * @array: the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, swapped = 0;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		swapped = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				swapped = 1;
			}
		}
		temp = array[min_index];
		array[min_index] = array[i];
		array[i] = temp;
		if (swapped)
			print_array(array, size);
	}
}
