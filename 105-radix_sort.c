#include "sort.h"

int get_max(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int pos);


/**
 * radix_sort - sort array in ascending order using redix algo.
 * @array: array to be sorted
 * @size: length of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		radix_counting_sort(array, size, pos);
		print_array(array, size);
	}
}

/**
 * get_max - find max element in ints array
 * @array: array to search for max
 * @size: length of array
 * Return: int max
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - using counting sorting to sort array base on pos
 * @array: array to be sorted
 * @size: length of array
 * @pos: special position to sort based on
 * Return: void
 */
void radix_counting_sort(int *array, size_t size, int pos)
{
	int *output, *count;
	int max = (array[0] / pos) % 10;
	size_t i;

	output = (int *)malloc(sizeof(int) * (size + 1));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		if (((array[i] / pos) % 10) > max)
			max = array[i];

	count = (int *)malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / pos) % 10] - 1] = array[i];
		count[(array[i] / pos) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];


	free(output);
	free(count);
}
