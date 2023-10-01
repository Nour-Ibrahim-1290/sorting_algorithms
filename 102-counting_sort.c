#include "sort.h"



int max_element(int *array, size_t size);

/**
 * counting_sort - sorting ints in ascending order using countring sort
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k;
	size_t i;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	k = max_element(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}

	/* Initialize the count array with all zeros */
	for (i = 0; (int)i <= k; i++)
		count[i] = 0;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* store the cumulative count of each elemnt */
	for (i = 1; (int)i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}


/**
 * max_element - find max. element in array
 * @array: array to search
 * @size: length of array
 * Return: int max
 */
int max_element(int *array, size_t size)
{
	int max = array[0];
	size_t i = 1;

	if (array == NULL || size < 2)
		return (0);

	for (; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
