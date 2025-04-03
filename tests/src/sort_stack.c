/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:43:25 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/03 16:39:43 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;
	int	moves;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	moves = 0;
	if (is_reversed(*stack))
	{
		moves += sa(stack);
		moves += rra(stack);
	}
	else if (first > second && second < third && third < first)
		return (ra(stack));
	else if (first < second && second > third && third < first)
		return (rra(stack));
	else if (first > second && second < third && first < third)
		return (sa(stack));
	else
	{
		moves += sa(stack);
		moves += ra(stack);
	}
	return (moves);
}

int	sort_large_stack(t_node **stack_a, int size)
{
	t_node	*stack_b;
	int	moves;
	int	num;

	stack_b = NULL;
	moves = 0;
	if (size > 4)
	{
		moves += pb(stack_a, &stack_b);
		moves += pb(stack_a, &stack_b);
	}
	while (size > 3)
	{
		num = find_cheapest_move(*stack_a, stack_b);
		moves += cheapest_move(num, stack_a, &stack_b);
		size--;
	}
	moves += sort_three(stack_a);
	while (stack_b)
		moves += push_back(stack_a, &stack_b);
	return (moves);
}

int	sort_stack(t_node **stack)
{
	int	size;

	size = stack_size(*stack);
	if(is_sorted(*stack))
		return (0);
	if (size == 2)
		return(sa(stack));
	else if (size == 3)
		return (sort_three(stack));
	return (sort_large_stack(stack, size));
}
