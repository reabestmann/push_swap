/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_explained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:48:51 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 12:39:01 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//think of rotate as SHINee changing the order of their lineup for a new choreography.
//the first person moves to the back, everyone else stays
//initial order: [Onew] -> [Key] -> [Minho] - [Taemin] -> NULL

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack; //identify the first in line (Onew)
	last = *stack;
	while (last->next)
		last = last->next; //identify the last in line (Taemin)
	*stack = first->next; //the second in line (Key) becomes first
	last->next = first; //the last in line (Taemin) now stands in front of Onew
	first->next = NULL; //Onew stands in front of noone
}

//new order: [Key] -> [Minho] -> [Taemin] -> [Onew] -> NULL

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
