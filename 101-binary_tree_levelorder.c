#include "binary_trees.h"


/**
 * create_queue_node - Creates a new queue node with a given binary tree node
 * @tree_node: Pointer to the binary tree node
 *
 * Return: Pointer to the new queue node, or NULL on failure
 */
queue_node_t *create_queue_node(const binary_tree_t *tree_node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	return (new_node);
}


/**
 * enqueue - Enqueues a binary tree node to the queue
 * @head: Double pointer to the queue head
 * @tail: Double pointer to the queue tail
 * @tree_node: Pointer to the binary tree node
 *
 * Return: Pointer to the new queue head, or NULL on failure
 */
queue_node_t *enqueue(queue_node_t **head, queue_node_t **tail,
		const binary_tree_t *tree_node)
{
	queue_node_t *new_node = create_queue_node(tree_node);

	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		/* Append the new node to the end of the queue */
		(*tail)->next = new_node;
		*tail = new_node;
	}

	return (*head);
}


/**
 * dequeue - Dequeues a binary tree node from the queue
 * @head: Double pointer to the queue head
 * @tail: Double pointer to the queue tail
 *
 * Return: Pointer to the dequeued binary tree node, or NULL if queue is empty
 */
const binary_tree_t *dequeue(queue_node_t **head, queue_node_t **tail)
{
	const binary_tree_t *tree_node;

	if (*head == NULL)
		return (NULL);

	tree_node = (*head)->tree_node;

	queue_node_t *temp = *head;
	*head = (*head)->next;
	free(temp);

	if (*head == NULL)
		*tail = NULL;

	return (tree_node);
}


/**
 * binary_tree_levelorder -Goes through binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_node_t *head = NULL, *tail = NULL;

	if (enqueue(&head, &tail, tree) == NULL)
		return;

	while (head != NULL)
	{
		const binary_tree_t *node = dequeue(&head, &tail);

		func(node->n);

		if (node->left != NULL)
		{
			if (enqueue(&head, &tail, node->left) == NULL)
				return;
		}
		if (node->right != NULL)
		{
			if (enqueue(&head, &tail, node->right) == NULL)
				return;
		}
	}
}
