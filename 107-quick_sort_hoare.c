#include "sort.h"


void quick_sort_recur(int *array, size_t size, int start, int end);
int pivot(int *array, size_t size, int start, int end);

/**
 * quick_sort_hoare - sorting ints array using quick sort algo.
 *			with Hoare scheme
 * @array: array too be sorted
 * @size: length of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recur(array, size, 0, size - 1);
}

/**
 * quick_sort_recur - algorithm implementation using recursion
 * @array: arrayto be sorted
 * @size: length of array
 * @start: starting index
 * @end: ending index
 */
void quick_sort_recur(int *array, size_t size, int start, int end)
{
	int pos;

	if (start < end)
	{
		pos = pivot(array, size, start, end);

		quick_sort_recur(array, size, start, pos - 1);
		quick_sort_recur(array, size, pos, end);
	}
}

/**
 * pivot - all smaller elements to left and all larger elements to right
 * @array: array to be sorted
 * @size: length of array
 * @start: starting index
 * @end: ending index
 * Return: int
 */
int pivot(int *array, size_t size, int start, int end)
{

	int temp, pos,  i, j;

	pos = array[end];

	for (i = start - 1, j = end + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pos);

		do {
			j--;
		} while (array[j] > pos);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	return (i);
}
