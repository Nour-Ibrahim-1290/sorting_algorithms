#include "sort.h"


int *partition(int *array, size_t l, size_t r);
void merge(int *array, int *left, int *rihgt, size_t l, size_t r);

/**
 * merge_sort - sorting ints in scending order using Top-Down Merging
 * @array: array to be sorted
 * @size: length of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	left = partition(array, 0, size / 2 + 1);
	right = partition(array, size / 2, size);

	merge_sort(left, size / 2);
	merge_sort(right, size - (size / 2));

	merge(array, left, right, size / 2, size - (size / 2));
}


/**
 * partition - split array at certain positions
 * @array: list to be splitted
 * @l: left side position to start at
 * @r: rihgt side position to end at
 * Return: int array
 */
int *partition(int *array, size_t l, size_t r)
{
	size_t i;
	int *output;

	output = (int *)malloc(sizeof(int) * (r - l));

	for (i = l; i < r; i++)
	{
		output[i - l] = array[i];
	}

	return (output);
}


/**
 * merge - add all sub-arrays together
 * @array: main array to store results
 * @left: left array to be sorted
 * @right: right array to be sorted
 * @l: left array boundary
 * @r: right array boundary
 * Return: void
 */
void merge(int *array, int *left, int *right, size_t l, size_t r)
{
	size_t i = 0, j = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l);
	printf("[right]: ");
	print_array(right, r);

	while (i < l && j < r)
	{
		if (left[i] < right[j])
		{
			array[i + j] = left[i];
			i++;
		}
		else
		{
			array[i + j] = right[j];
			j++;
		}
	}

	for (; i < l; i++)
		array[i + j] = left[i];

	for (; j < r; j++)
		array[i + j] = right[j];

	printf("[Done]: ");
	print_array(array, l + r);

	free(left);
	free(right);
}
