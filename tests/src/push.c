/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:31:50 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/07 19:00:25 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node *top;

	if(!src || !(*src))
		return ;

	top = *src;
	*src = (*src)->next;
	top->next = *dst;
	*dst = top;
}

int pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
	return (1);
}

int pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
	return (1);
}
