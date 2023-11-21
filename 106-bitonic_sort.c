#include <stdio.h>

void bitonic_merge(int *array, size_t start, size_t seq, char flow);
void swap_ints(int *a, int *b);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Swaps the values of two integers using pointers.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* bitonic_merge - Merges a bitonic sequence.
* @array: Array of integers.
* @start: Starting index of the sequence to sort.
* @seq: Size of the sequence to sort.
* @flow: Direction to sort in ('U' for up, 'D' for down).
*
* Recursively merges a bitonic sequence inside an array of integers.
*/
void bitonic_merge(int *array, size_t start, size_t seq, char flow)
{
	size_t i, jump;

	if (seq > 1)
	{
		jump = seq / 2;

		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
				(flow == 'D' && array[i] < array[i + jump]))
			{
				swap_ints(&array[i], &array[i + jump]);
			}
		}
		bitonic_merge(array, start, jump, flow);
		bitonic_merge(array, start + jump, jump, flow);
	}
}

/**
* bitonic_sort - Sorts an array using Bitonic sort algorithm.
* @array: Array of integers to be sorted.
* @size: Size of the array.
*
* Sorts the array in ascending order using Bitonic sort.
*/
void bitonic_sort(int *array, size_t size)
{
	size_t i, seq;

	if (array == NULL || size < 2)
		return;

	for (seq = 2; seq <= size; seq *= 2)
	{
		for (i = 0; i < size; i += seq)
		{
			char direction = (i / seq) % 2 == 0 ? 'U' : 'D';

			bitonic_merge(array, i, seq, direction);
		}
	}
}
