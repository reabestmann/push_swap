/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_explained.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:16:08 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 12:23:21 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//imagine SHINee is standing in a line for a photoshoot. Each member represents a node in a linked list.
//initial order: [Onew] -> [Key] -> [Minho] -> [Taemin] -> NULL

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack; //identify the first in line (Onew)
	second = first->next; //identify the second in line (Key)
	first->next = second->next; //put Onew in front of the third in line (Minho)
	second->next = first; //put Key in front of the first in line (Onew)
	*stack = second; //Key is now first in line
}

//order after swapping: [Key] -> [Onew] -> [Minho] -> [Taemin] -> NULL

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
