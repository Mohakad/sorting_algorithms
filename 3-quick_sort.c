#include "sort.h"
/**
 * swapi - swap 
 * @in1: first
 * @in2: second
 */
void swapi(int *in1, int *in2)
{
    int temp;
    
    temp = *in1;
    *in1 = *in2;
    *in2 = temp;
}

/**
 * part - partitions
 * @arr: array
 * @low: start
 * @high: end
 * Return: pivot
 */
int part(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, k, j;

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapi(&arr[i], &arr[j]);
            if (i != j)
            {
                for (k = low; k <= high; k++)
                    printf("%d%s", arr[k], k == high ? "\n" : ", ");
            }
        }
    }
    swapi(&arr[i + 1], &arr[high]);
    if (i + 1 != high)
    {
        for (k = low; k <= high; k++)
            printf("%d%s", arr[k], k == high ? "\n" : ", ");
    }
    return (i + 1);
}

/**
 * quick_sort - sort quick
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
    int low = 0, high = size - 1, p;

    if (size < 2)
        return;
    if (low < high)
    {
        p = part(array, low, high);

        quick_sort(array, p);
        quick_sort(array + p + 1, size - p - 1);
    }
}
