/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_explained.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:31:50 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 12:33:51 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//imagine SHINee is standing in line for two photoshoots: group shooting (stack a) and individual shooting (stack b). Every member respresents a node in a linked list.
//Group Photoshoot (Stack A): [Onew] -> [Key] -> [Minho] -> NULL
//Member Photoshoot (Stack B): [Taemin] -> [Jonghyun] -> NULL
//if we call pa, Taemin joins the line for group photoshoot (Stack A)

void	push(t_node **src, t_node **dst)
{
	t_node *top;

	if(!src || !(*src))
		return ;

	top = *src; //identify the first in line (Taemin)
	*src = top->next; //make the second in line (Jonghyun) first
	top->next = *dst; //make Taemin stand in front of Onew (first in stack a)
	*dst = top; //now Taemin is first in stack a
}

//new order (group shoot/stack a): [Taemin] -> [Onew] -> [Key] -> [Minho] -> NULL
//(member shoot/ stack b): [Jonghyun] -> NULL

void pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
