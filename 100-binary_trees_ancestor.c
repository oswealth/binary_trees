#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node,
 * NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = first;

	while (ancestor != NULL)
	{
		if (binary_tree_is_descendant(ancestor, second))
			return ((binary_tree_t *)ancestor);

	/* Move to the parent of the current ancestor */
		ancestor = ancestor->parent;
    	}

	return (NULL);
}

/**
 * binary_tree_is_descendant - Checks if a node is a descendant of another node
 * @ancestor: Pointer to the potential ancestor node.
 * @node: Pointer to the potential descendant node.
 * Return: 1 if node is a descendant of ancestor, 0 otherwise.
 */
int binary_tree_is_descendant(const binary_tree_t *ancestor,
		const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (node == ancestor || binary_tree_is_descendant(ancestor,
				node->left) || binary_tree_is_descendant(ancestor, node->right));
}
