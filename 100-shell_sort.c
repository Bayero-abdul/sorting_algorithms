#include "sort.h"


/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int j, i, gap, temp, n = size;

	for (gap = n / 3; gap >= 1; gap = gap / 3)
	{
		for (j = gap; j < n; j = j + gap)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
				{
					break;
				}
				else
				{
					temp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = temp;
				}

			}
		}
		print_array(array, size);
	}
}
