/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:56:45 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/13 22:22:39 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	second_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

int	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_node **a, t_node **b, t_node *cheapest)
{
	int	moves;

	moves = 0;
	while (*b != cheapest->target && *a != cheapest)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_printf("rrr\n");
		moves++;
	}
	set_pos(*a);
	set_pos(*b);
	return (moves);
}
