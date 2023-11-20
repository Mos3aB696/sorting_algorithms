#include "sort.h"

/**
 * swap - function that used to swap to element
 * @xp:first element
 * @yp: sacond element
 *
 * Return: nothing
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * partition - function that used tp partition the
 * array around povit
 * @arr: input array
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of array
 *
 * Return: index
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}

/**
 * quick_sort_helper -  function that sorts an array of integers in
 * ascending order using
 * the Quick sort algorithm
 * @arr: input array
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort_helper(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int index = partition(arr, low, high, size);

		quick_sort_helper(arr, low, index - 1, size);
		quick_sort_helper(arr, index + 1, high, size);
	}
}

/**
 * quick_sort -  function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: input array
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
