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
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			swap_ints(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
