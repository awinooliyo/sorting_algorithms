#include "sort.h"

/**
* bubble_sort - Calls function
* @array: Array to sort.
* @size: Size of the array.
* Description: Function that orts an array using bubble sort method
* Return: 0
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++) /* loop to access each array element */
	{
		for (j = 0; j < size - i - 1; j++) /* loop to compare array elements */
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
