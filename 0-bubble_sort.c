#include "sort.h"


/**
 * bubble_sort - that sorts an array of integers in ascending order
 * in O(n^2) time
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, n, new_n;
	int temp;

	if (!array || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		new_n = 0;
		for (j = 1; j < n; j++)
		{

			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				new_n = j;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
