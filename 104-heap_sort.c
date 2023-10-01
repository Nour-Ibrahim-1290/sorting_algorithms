#include "sort.h"


void heapify(int *array, size_t size, size_t base, size_t root);
void swap(int *el1, int *el2);

/**
 * heap_sort - sort array as a heap using shift-down algorithm
 * @array: array to be sorted
 * @size: length of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = ((int)size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, (size_t)i);

	for (i = (int)size - 1; i >= 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, (size_t)i, 0);
	}
}

/**
 * heapify - heapify until its othe array is ordered (root is always largest)
 * @array: array to be heapified
 * @size: length of array
 * @base: index of base row
 * @root: index of root
 * Return: void
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t max = root, l = 2 * root + 1, r = 2 * root + 2;

	if (l < base && array[l] > array[max])
		max = l;

	if (r < base && array[r] > array[max])
		max = r;

	if (max != root)
	{
		swap(array + root, array + max);
		print_array(array, size);
		heapify(array, size, base, max);
	}
}

/**
 * swap - sway 2 elements of an array
 * @el1: element 1 to swap
 * @el2: element 2 tp swap
 * Return: void
 */
void swap(int *el1, int *el2)
{
	int temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}
