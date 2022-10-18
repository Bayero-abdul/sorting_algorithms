#include "sort.h"
#include <stdlib.h>


/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort
 * @array: array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *copy = NULL, n = size, i, k;

	if (!array || size < 2)
		return;

	k = array[0];
	for (i = 1; i < n; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	copy = malloc(sizeof(*copy) * size);
	if (copy == NULL)
		return;

	count = malloc(sizeof(*count) * (k + 1));
	if (count == NULL)
		return;

	for (i = 0; i < k + 1; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[array[i]] += 1;

	for (i = 1; i < k + 1; i++)
		count[i] = count[i - 1] + count[i];
	print_array(count, k + 1);

	for (i = n - 1; i >= 0; i--)
	{
		--count[array[i]];
		copy[count[array[i]]] = array[i];
	}

	for (i = 0; i < n; i++)
		array[i] = copy[i];

	free(count);
	free(copy);
}
