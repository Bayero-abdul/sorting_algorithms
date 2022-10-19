#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void sort(int *copy, int *array, size_t left, size_t right);
void merge(int *copy, int *array, size_t left, size_t mid, size_t right);

/**
 * merge_sort -  sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: the array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy = NULL;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(*copy) * size);
	if (copy == NULL)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	sort(copy, array, 0, size);

	free(copy);
}


/**
 * sort - sorts the array recursively
 * @copy: array used for sorting the subarray
 * @array: the array
 * @left: index of the first element of the subarray
 * @right: one past the index of the last element in the subarray
 */
void sort(int *copy, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (right + left) / 2;
		sort(copy, array, left, mid);
		sort(copy, array, mid, right);
		merge(copy, array, left, mid, right);
	}
}


/**
 * merge - sorts and merge the subarray
 * @copy: array used for sorting the subarray
 * @array: the array
 * @left: index of the first element of the subarray
 * @mid: middle index of the subarray
 * @right: one past the index of the last element in the subarray
 */
void merge(int *copy, int *array, size_t left, size_t mid, size_t right)
{
	size_t k = left;
	size_t i = left, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	while (i < mid && j < right)
	{
		if (array[i] < array[j])
			copy[k++] = array[i++];
		else
			copy[k++] = array[j++];
	}

	for	(; i < mid; i++)
		copy[k++] = array[i];

	for (; j < left; j++)
		copy[k++] = array[j];

	for (i = left; i < k; i++)
		array[i] = copy[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
