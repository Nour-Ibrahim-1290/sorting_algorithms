#include "sort.h"


/**
 * shell_sort - sorting ints in ascending order using shell algorithm
 * @array: array of ints to be sorted
 * @size: length of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* The Algorithm */
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size ; i += 1)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
