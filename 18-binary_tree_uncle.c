#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if the parent has a parent */
	if (node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left != NULL && node->parent->parent->right != NULL)
	{
		if (node->parent == node->parent->parent->left)
			return (node->parent->parent->right);

		if (node->parent == node->parent->parent->right)
			return (node->parent->parent->left);
	}

	/* Otherwise, the node has no uncle */
	return (NULL);
}
