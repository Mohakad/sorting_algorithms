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
 * selection_sort -selection sort
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swapi(array + i, min);
			print_array(array, size);
		}
	}
}
