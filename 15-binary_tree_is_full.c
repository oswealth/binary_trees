#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is full, 0 if tree is NULL or not full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if tree is a leaf*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Check if tree has two children  */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
