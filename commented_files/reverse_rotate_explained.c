/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_explained.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:56:45 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 12:45:04 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//now the last member moves in front of everyone in the change of lineup, everyone else stays.
//initial lineup: [Jonghyun] -> [Key] -> [Minho] -> [Onew] -> [Taemin] -> NULL

void	reverse_rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	second_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_last = last; //identify the second last in line (Onew)
		last = last->next; //identify the last in line (Taemin)
	}
	second_last->next = NULL; //cut off Taemin from the line, so Onew stands in front of nobody
	last->next = *stack; //make Taemin stand in front of the first in line (Jonghyun)
	*stack = last; //Taemin is now first
}

//after reverse rotate: [Taemin] -> [Jonghyun] -> [Key] -> [Minho] -> [Onew] -> NULL

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
	
