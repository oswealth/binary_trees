#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	count += binary_tree_nodes(tree->left);

	count += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		count++;

	/* Return the number of nodes */
	return (count);
}
