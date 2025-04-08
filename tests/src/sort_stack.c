/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:43:25 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/07 18:40:39 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finish_rotation(t_node **a, t_node **b, t_node *cheapest)
{
	int	moves;

	moves = 0;
	while (*b != cheapest)
	{
		if (cheapest->upper_half)
			moves += rb(b);
		else
			moves += rrb(b);
		set_pos(*b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->upper_half)
			moves += ra(a);
		else
			moves += rra(a);
		set_pos(*a);
	}
	return (moves);
}
	
int	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int	moves;

	moves = 0;
	cheapest = find_cheapest(*b);
	if (cheapest->upper_half && cheapest->target->upper_half)
		moves += rr(a, b, cheapest);
	else if (!(cheapest->upper_half) && !(cheapest->target->upper_half))
		moves += rrr(a, b, cheapest);
	moves += finish_rotation(a, b, cheapest);
	moves += pa (a, b);
	return (moves);
}

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
	if (first > second && second > third && third < first)
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

int	push_swap(t_node **a, t_node **b, int size)
{
	t_node	*smallest;
	int	moves;
	int	i;

	moves = 0;
	i = size;
	while (i-- > 3)
		moves += pb(a, b);
	moves += sort_three(a);
	while (*b)
	{
		update_nodes(*a, *b);
		moves += move_nodes(a, b);
	}
	smallest = find_smallest(*a);
	if (smallest->upper_half)
		while (*a != smallest)
			moves += ra(a);
	else
		while (*a != smallest)
			moves += rra(a);
	return (moves);
}

int	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if(is_sorted(*a))
		return (0);
	if (size == 2)
		return (sa(a));
	else if (size == 3)
		return (sort_three(a));
	return (push_swap(a, b, size));
}
