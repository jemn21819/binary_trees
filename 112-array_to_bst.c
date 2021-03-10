#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: numeber of elements in the array
 * Return: return a pointer to the root node of the created BST,
 * or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root_node = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root_node, array[i]);
	}
	return (root_node);
}
