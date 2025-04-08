/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_old.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/07 18:27:37 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return node;
}

void	append_node(t_node **stack, int value)
{
	t_node	*node;
	t_node	*temp;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	mode->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

//for debugging purposes

void	print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_printf("Stack is empty.\n");
		return ;
	}

	while (stack)
	{
		ft_printf("%i\n", stack->value);
		stack = stack->next;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
