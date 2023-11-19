#include <stdio.h>
#include "sort.h"

/**
* swap - Function that swaps two values.
*
* @a: the first value
* @b: the second value
* Return: 0
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
