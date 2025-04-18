/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:43:25 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 12:45:14 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*(reverse)rotates until a given node is on top of its stack*/
static int	to_top(t_node **stack, t_node *node, char name)
{
	int	moves;

	moves = 0;
	while ((*stack)->value != node->value)
	{
		if (name == 'a')
		{
			if (node->upper_half)
				moves += ra(stack);
			else
				moves += rra(stack);
		}
		else if (name == 'b')
		{
			if (node->upper_half)
				moves += rb(stack);
			else
				moves += rrb(stack);
		}
	}
	return (moves);
}

/*finds the next node to be pushed to b, puts it and its
	target into the correct position and pushes*/
static int	a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		moves;

	moves = 0;
	cheapest = find_cheapest(*a);
	if (cheapest->upper_half && cheapest->target->upper_half)
		moves += rr(a, b, cheapest);
	else if (!(cheapest->upper_half) && !(cheapest->target->upper_half))
		moves += rrr(a, b, cheapest);
	moves += to_top(a, cheapest, 'a');
	moves += to_top(b, cheapest->target, 'b');
	moves += pb(a, b);
	return (moves);
}

/*puts the target node of the top node in stack
	b on top of a & pushes back b node to a*/
static int	b_to_a(t_node **a, t_node **b)
{
	int	moves;

	moves = 0;
	moves += to_top(a, (*b)->target, 'a');
	moves += pa(a, b);
	return (moves);
}

/*sorts three numbers in a in 1-2 moves*/
int	sort_three(t_node **a)
{
	t_node	*biggest;
	int		moves;

	moves = 0;
	biggest = find_biggest(*a);
	if (biggest == *a)
		moves += ra(a);
	else if (biggest == (*a)->next)
		moves += rra(a);
	if ((*a)->value > (*a)->next->value)
		moves += sa(a);
	return (moves);
}

/*our sorting algorithm*/
int	push_swap(t_node **a, t_node **b, int size)
{
	int	moves;

	moves = 0;
	if (size-- > 3 && !is_sorted(*a))
		moves += pb(a, b);
	if (size-- > 3 && !is_sorted(*a))
		moves += pb(a, b);
	while (size-- > 3 && !is_sorted(*a))
	{
		set_nodes(*a, *b, 'a');
		moves += a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_nodes(*a, *b, 'b');
		moves += b_to_a(a, b);
	}
	set_pos(*a);
	moves += to_top(a, find_smallest(*a), 'a');
	return (moves);
}
