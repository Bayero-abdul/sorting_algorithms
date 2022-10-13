#include "sort.h"

void swap(int *a, int *b);
void sort(int *array, int p, int r, size_t size);
int partition(int *array, int p, int r, size_t size);


/**
 *quick_sort - sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: Array to be sorted
 *@size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);

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
 *partition - Devides an array into two partition
 *@array: The array to be partitioned
 *@p: first element index
 *@r: last element index
 *@size: main array size
 *Return: pivot index
 */
int partition(int *array, int p, int r, size_t size)
{
	int i, j;
	int pivot = array[r];

	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[r])
	{
		swap(&array[i + 1], &array[r]);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * swap - swaps two numbers
 * @a: number
 * @b: number
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
