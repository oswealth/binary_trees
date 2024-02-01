#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);  /* Call the function on the current node */
<<<<<<< HEAD
	binary_tree_preorder(tree->left, func);   /* Recursively traverse left */
	binary_tree_preorder(tree->right, func);  /* Recursively traverse right */
=======
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
>>>>>>> d3444672a6d57620e94f34ac587e2ab71885e778
}
