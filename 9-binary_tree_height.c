#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

<<<<<<< HEAD
	/**
	 * Return the maximum height of the left or right subtree,
	 * plus 1 for the current node
	 */
=======
>>>>>>> d3444672a6d57620e94f34ac587e2ab71885e778
	return (1 + (left_height > right_height ? left_height : right_height));
}
