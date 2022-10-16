#include "sort.h"

/**
 *partition - Devides an array into two partition
 *@array: The array to be partitioned
 *@l: first element index
 *@r: last element index
 *@size: main array size
 *Return: pivot index
 */
int partition(int *array, int l, int r, size_t size)
{
	int temp, j;
	int pivot = array[r];
	int i = l - 1;

	for (j = l; j < r; j++)
	{
		if (pivot > array[j])
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[r])
	{
		temp = array[i + 1];
		array[i + 1] = array[r];
		array[r] = temp;
		print_array(array, size);
	}
	return (i + 1);
}


/**
 *sort - sorts the array
 *@left: first element index
 *@right: last element index
 *@array: Array to be sorted
 *@size: Size of array
 */
void sort(int *array, int left, int right, size_t size)
{
	int q;

	if (left < right)
	{
		q = partition(array, left, right, size);
		sort(array, left, q - 1, size);
		sort(array, q + 1, right, size);
	}
}


/**
 *quick_sort - sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: Array to be sorted
 *@size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);

}
