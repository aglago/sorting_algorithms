#include "sort.h"
/**
 * count_sort - sorting array of ints
 * @array: array of ints
 * @size: size of array
 *
 */
void count_sort(int *array, size_t size)
{
	int *cp, *count;
	unsigned int max, i, tmp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (array[i] > (int)max)
			max = array[i];
		i++;
	}
	max++;

	count = malloc(max * sizeof(int));
	if (count == NULL)
		return;
	cp = malloc(size * sizeof(int));
	if (cp == NULL)
	{
		free(count);
		return;
	}

	i = 0;
	while (i < size)
	{
		cp[i] = array[i];
		i++;
	}

	i = 0;
	while (i < max)
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		count[array[i]]++;
		i++;
	}

	i = 1;
	while (i < max)
	{
		count[i] += count[i - 1];
		i++;
	}

	print_array(count, max);

	i = 0;
	while (i < size)
	{
		tmp = cp[i];
		array[count[tmp] - 1] = tmp;
		count[tmp]--;
		i++;
	}
	free(count);
	free(cp);
}
