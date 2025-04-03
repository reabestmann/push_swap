/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:42 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/03 16:10:19 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
int	find_biggest(t_node *stack)
{
	t_node	*current;
	int	biggest;
	int	biggest_pos;
	int	i;

	current = stack;
	biggest = current->value;
	i = 0;
	biggest_pos = 0;
	while (current)
	{
		if (current->value > biggest)
		{
			biggest = current->value;
			biggest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (biggest_pos);
}

int	find_smallest(t_node *stack)
{
	t_node	*current;
	int	smallest;
	int	smallest_pos;
	int	i;

	current = stack;
	smallest = current->value;
	i = 0;
	smallest_pos = 0;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			smallest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (smallest_pos);
}

int	is_reversed(t_node *stack)
{
//	int	moves;

//	moves = 0;
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
/*	if (stack_size(stack) > 3)
	{
		while (stack_size(stack_a) > 3)
		{
			moves += rra(&stack_a);
			moves += pb(&stack_a, &stack_b);
		}
		moves += sort_three(&stack_a);
		while (stack_b)
			moves += pa(&stack_a, &stack_b);
		return (moves);
	}*/
	return (1);
}

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
