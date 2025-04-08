/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:48:51 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/07 18:37:03 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
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

int	rr(t_node **a, t_node **b, t_node *cheapest)
{
	int	moves;

	moves = 0;
	while (*a != cheapest->target && *b != cheapest)
	{
		rotate(a);
		rotate(b);
		moves++;
	}
	set_pos(*a);
	set_pos(*b);
	ft_printf("rr\n");
	return (moves);
}
