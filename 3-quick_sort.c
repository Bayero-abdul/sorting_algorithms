#include "sort.h"

/**
 *partition - Devides an array into two partition
 *@array: The array to be partitioned
 *@p: first element index
 *@r: last element index
 *@size: main array size
 *Return: pivot index
 */
int partition(int *array, int p, int r, size_t size)
{
	int i, j, temp;
	int pivot = array[r];

	i = p - 1;
	for (j = p; j < r; j++)
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
	if (array[i + 1] != array[r] && r - p != 1)
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
 *@p: first element index
 *@r: last element index
 *@array: Array to be sorted
 *@size: Size of array
 */
void sort(int *array, int p, int r, size_t size)
{
	int q;

	if (p < r)
	{
		q = partition(array, p, r, size);
		sort(array, p, q - 1, size);
		sort(array, q + 1, r, size);
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
