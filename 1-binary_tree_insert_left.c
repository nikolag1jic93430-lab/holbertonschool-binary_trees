#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Insère un nœud comme enfant gauche du parent.
 *
 * @parent: Pointeur vers le nœud où insérer l'enfant gauche.
 * @value: La valeur à stocker dans le nouveau nœud.
 *
 * Si parent a déjà un enfant gauche, le nouveau nœud prend sa place,
 * et l'ancien enfant gauche devient l'enfant gauche du nouveau nœud.
 *
 * Return: Pointeur vers le nœud créé, ou NULL si parent est NULL ou en cas d'échec.
 */
binary_tree_t *binary_tree_insert_left(
		binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		new_node->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
