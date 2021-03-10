#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: tore in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_root;

	if (tree)
	{
		if (!*tree)
		{
			*tree = (bst_t *)binary_tree_node(NULL, value);
			return (*tree);
		}
		new_root = *tree;
		while (new_root)
		{
			if (new_root->n == value)
				break;
			if (new_root->n > value)
			{
				if (!new_root->left)
				{
					new_root->left = (bst_t *)binary_tree_node(new_root, value);
					return (new_root->left);
				}
				new_root = new_root->left;
			}
			else if (new_root->n < value)
			{
				if (!new_root->right)
				{
					new_root->right = (bst_t *)binary_tree_node(new_root, value);
					return (new_root->right);
				}
				new_root = new_root->right;
			}
		}
	}
	return (NULL);
}
