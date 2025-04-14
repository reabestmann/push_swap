/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:37:22 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/13 21:19:02 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_node **a)
{
	t_node	*biggest;
	int		moves;

	moves = 0;
	biggest = find_biggest(*a);
	else if (biggest == *a)
		moves += ra(a);
	else if (biggest == (*a)->next)
		moves += rra(a);
	if ((*a)->value > (*a)->next->value)
		moves += sa(a);
	return (moves);
}

static int	finish_sort(t_node **a)
{
	t_node	*smallest;
	int		moves;

	smallest = find_smallest(*a);
	moves = 0;
	while (*a != smallest)
	{
		if (smallest->upper_half)
			moves += ra(a);
		else
			moves += rra(a);
	}
	return (moves);
}

int	push_swap(t_node **a, t_node **b, int size)
{
	int	moves;

	moves = 0;
	if (size-- > 3 && !is_sorted(*a))
		moves += pb(a, b);
	if (size-- > 3 && !is_sorted(*a))
		moves += pb(a, b);
	while (size-- > 3 && !stack_sorted(*a))
	{
		set_nodes(*a, *b, a);
		moves += a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_nodes(*a, *b, b);
		moves += b_to_a(a, b);
	}
	set_pos(*a);
	moves += finish_sort(*a);
	return (moves);
}
