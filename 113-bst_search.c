#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	node = (bst_t *)tree;
	while (node)
	{
		if (node->n == value)
			return (node);
		if (node->n < value)
			node = node->right;
		else
			node = node->left;
	}
	return (NULL);
}
