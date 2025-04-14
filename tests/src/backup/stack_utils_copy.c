/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/06 19:28:38 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    append_node(t_node **stack, int value)
{
        t_node  *node;
	t_node	*current;

        node = malloc(sizeof(t_node));
        if (!node)
                return ;
	node->next = NULL;
	node->value = value;
        if (*stack == NULL)
        {
                *stack = node;
		node->prev = NULL;
                return ;
        }
	else
	{
		current = *stack;
        	while (current->next)
			current = current->next;
        current->next = node;
	node->prev = current;
	}
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
