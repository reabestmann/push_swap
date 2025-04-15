/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:31:50 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/15 10:46:26 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*top;

	if (!*src)
		return ;
	top = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top->prev = NULL;
	if (!*dst)
	{
		*dst = top;
		top->next = NULL;
	}
	else
	{
		top->next = *dst;
		top->next->prev = top;
		*dst = top;
	}
}

int	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
	return (1);
}
