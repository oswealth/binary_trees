#include "binary_trees.h"
#include<stdlib.h>
/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array.
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *a;
	int ext, i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	a = malloc(heap_size * sizeof(int));
	if (!a)
		return (NULL);
	while (heap)
	{
		ext = heap_extract(&heap);
		a[i] = ext;
		i++;
	}
	return (a);
}
