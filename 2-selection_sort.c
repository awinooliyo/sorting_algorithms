#include "sort.h"


/**
* swap_ints - Function that swaps two values.
*
* @a: the first value
* @b: the second value
* Return: 0
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}


/**
* selection_sort - sorts an array of integers in ascending order
*                  using the selection sort algorithm.
* @array: the array of integers to be sorted.
* @size: The size of the array.
*
* Description: Prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + 1, min);
			print_array(array, size);
		}
	}
}
