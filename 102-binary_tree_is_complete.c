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
 * enqueue - Enqueues/push a binary tree node to the queue
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
		(*tail)->next = new_node;
		*tail = new_node;
	}
	return (*head);
}


/**
 * dequeue - Dequeues/pop a binary tree node from the queue
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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	queue_node_t *head = NULL, *tail = NULL;

	if (enqueue(&head, &tail, tree) == NULL)
		return (0);

	while (head != NULL)
	{
		const binary_tree_t *node = dequeue(&head, &tail);

		if (node == NULL)
		{
			while (head != NULL)
			{
				node = dequeue(&head, &tail);

				if (node != NULL)
					return (0);
			}
			return (1);
		}
		if (enqueue(&head, &tail, node->left) == NULL)
			return (0);
		if (enqueue(&head, &tail, node->right) == NULL)
			return (0);
	}
	return (1);
}
