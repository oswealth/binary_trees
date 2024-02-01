#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if the parent has two children */
	if (node->parent->left != NULL && node->parent->right != NULL)
	{
		if (node == node->parent->left)
			return (node->parent->right);

		if (node == node->parent->right)
			return (node->parent->left);
	}

	/* Otherwise, the node has no sibling */
	return (NULL);
}
