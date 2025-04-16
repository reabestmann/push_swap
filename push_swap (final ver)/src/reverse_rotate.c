/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:56:45 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 12:32:35 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*command to rotate the last node of a stack
	to the top of the same stack*/
static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
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

/*combines rotations until the node to be pushed 
	or its target is on top of its stack*/
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
