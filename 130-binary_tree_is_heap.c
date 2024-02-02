#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
* no_es_legal - helper
* @tree: helper
* @n: helper
* Return: 1, else 0
*/
int no_es_legal(const binary_tree_t *tree, int n)
{
	int i, j;

	if (!tree)
		return (1);
	if (tree->n < n)
	{
		i = no_es_legal(tree->left, n);
		j = no_es_legal(tree->right, n);
		if (i && j)
			return (1);
	}
	return (0);
}

/**
* binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (no_es_legal(tree->left, tree->n) && no_es_legal(tree->right, tree->n))
		if (!tree->left || binary_tree_is_heap(tree->left))
			if (!tree->right || binary_tree_is_heap(tree->right))
				if (binary_tree_is_complete(tree))
					return (1);
	return (0);
}
