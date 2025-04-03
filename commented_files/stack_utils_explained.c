/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_explained.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 14:39:01 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function created a new node with a given value.

t_node *new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node)); //if malloc fails, no new node can be added.
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL; //the node is currently alone
	return node; //ready to join the stack!
}

//this function appends a new node to the linked list.

void	append_node(t_node *stack, int value)
{
	t_node	*new;
	t_node	*temp;

	new = new_node(value);
	if (!new) //if the creation failed, dont continue
		return ;
	if (*stack == NULL) //if the stack is empty, the new node becomes the first node.
	{
		*stack = new;
		return ;
	}
	temp = stack;
	while (temp->next) //move until the last node
		temp = temp->next;
	temp->next = new; //add the new node at the end!
}

//for debugging purposes - this function prints a linked list

void	print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_printf("Stack is empty.\n")
		return ;
	}

	while (stack) //go through each node
	{
		ft_printf("%i\n", stack->value); //show the number stored inside the node
		stack = stack->next; // move onto the next one
	}
}

//this function frees the entire stack and sets it to NULL

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack) //go through all nodes
	{
		temp = (*stack)->next; //hold onto the next node
		free(*stack); //let the current node go
		*stack = temp; //move onto the next
	}
	*stack = NULL; //stack is now empty!
}
