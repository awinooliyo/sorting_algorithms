#include "sort.h"

void merge(int *array, int *temp_array, size_t left, size_t mid, size_t right);
void merge_sort_helper(int *array, int *temp_array, size_t left, size_t right);
void merge_sort(int *array, size_t size);

/**
* merge - Merge two subarrays of array[].
* @array: The array containing the subarrays to be merged.
* @temp_array: The temporary array to store the merged subarrays.
* @left: Starting index of the first subarray.
* @mid: Ending index of the first subarray
*	and the starting index of the second subarray.
* @right: Ending index of the second subarray.
*/
void merge(int *array, int *temp_array, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;

	/* Merge the subarrays into tempArray in sorted order */
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			temp_array[k++] = array[i++];
		}
		else
		{
			temp_array[k++] = array[j++];
		}
	}
	/* Copy the remaining elements from the left subarray */
	while (i <= mid)
	{
		temp_array[k++] = array[i++];
	}

	/* Copying the remaining elements from the right subarray */
	while (j <= right)
	{
		temp_array[k++] = array[j++];
	}

	for (i = left; i <= right; i++)
	{
		array[i] = temp_array[i];
	}
}

/**
* merge_sort_helper - Recursive function to implement the merge sort algorithm.
* @array: The array of integers to be sorted.
* @temp_array: The temporary array used for merging.
* @left: Starting index of the subarray to be sorted.
* @right: Ending index of the subarray to be sorted.
*/
void merge_sort_helper(int *array, int *temp_array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_helper(array, temp_array, left, mid);
		merge_sort_helper(array, temp_array, mid + 1, right);
		merge(array, temp_array, left, mid, right);
	}
}

/**
* merge_sort - Sort an array of integers in ascending.
* order using the merge sort algorithm.
* @array: The array of integers to be sorted.
* @size: The size of the array.
*
* Description: Implements the top-down merge sort algorithm.
*/
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;

	/* Allocate a temporary array for merging */
	temp_array = (int *)malloc(size * sizeof(int));

	if (temp_array == NULL)
		return;

	merge_sort_helper(array, temp_array, 0, size - 1);

	/* Free allocated memory for temp_array */
	free(temp_array);
}
