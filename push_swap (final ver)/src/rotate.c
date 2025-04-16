/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:48:51 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 12:35:08 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotates the top node of a stack to be at the
	last position of the same stack*/
static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

int	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
	return (1);
}

/*combines the rotations of a node and its target
	until either is on top of its stack*/
int	rr(t_node **a, t_node **b, t_node *cheapest)
{
	int	moves;

	moves = 0;
	while (*b != cheapest->target && *a != cheapest)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
		moves++;
	}
	set_pos(*a);
	set_pos(*b);
	return (moves);
}
