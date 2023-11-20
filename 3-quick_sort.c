#include "sort.h"

/**
 * swap - function that used to swap to element
 * @a: first element
 * @b: sacond element
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
 * _partition - function that used tp partition the 
 * array around povit
 * @arr: input array
 * @low: index for the first element
 * @high: index for the last element
 *
 * Return: index 
 */
int _partition(int arr[], int low, int high)
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
            print_array(arr, high - low + 1);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    print_array(arr, high - low + 1);
    return (i + 1);
}

/**
 * quick_sort -  function that sorts an array of integers in 
 * ascending order using
 * the Quick sort algorithm
 * @arr: input array
 * @low: index for the first element
 * @high: index for the last element
 *
 * Return: nothing
 */
void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int index = _partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}
