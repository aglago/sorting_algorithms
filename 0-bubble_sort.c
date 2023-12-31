#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array containing elements to be sorted
 * @size: size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, repeat = 0;
	int temp;

	if (size <= 0)
		return;
	if (size == 1)
	{
		print_array(array, size);
		return;
	}

	for (repeat = 0; repeat < size - 1; repeat++)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
