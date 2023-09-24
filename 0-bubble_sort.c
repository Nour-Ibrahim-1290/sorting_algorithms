#include "sort.h"


/**
 * bubble_sort - sort array in descending order
 * @array: array to be sorted
 * @size: length of the array to be sorted
 *
 * Return: sorted array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	/* Array checks */
	if (array == NULL)
		return;

	if (size < 2)
		return;

	/* The Algorithm */
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
