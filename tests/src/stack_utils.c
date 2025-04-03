/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/03 15:36:04 by rbestman         ###   ########.fr       */
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

void	push_front(t_node **stack, int value)
{
	t_node	*new;

	new = new_node(value);
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
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
	ft_printf("\n");
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
