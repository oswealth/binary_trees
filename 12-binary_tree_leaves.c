#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves.
 *
 * Return: Number of leaves, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	count += binary_tree_leaves(tree->left);

	count += binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		count++;

	/* Return the number of leaves */
	return (count);
}
