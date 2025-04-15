/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:05 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/15 15:54:31 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *src, t_node *dst)
{
	t_node	*current_dst;
	t_node	*target;
	long	match;

	while (src)
	{
		current_dst = dst;
		match = LONG_MAX;
		target = find_smallest(dst);
		while (current_dst)
		{
			if (current_dst->value > src->value && current_dst->value < match)
			{
				match = current_dst->value;
				target = current_dst;
			}
			current_dst = current_dst->next;
		}
		src->target = target;
		src = src->next;
	}
}

static void	set_target_a(t_node *src, t_node *dst)
{
	t_node	*current_dst;
	t_node	*target;
	long	match;

	while (src)
	{
		current_dst = dst;
		match = LONG_MIN;
		target = find_biggest(dst);
		while (current_dst)
		{
			if (current_dst->value < src->value && current_dst->value > match)
			{
				match = current_dst->value;
				target = current_dst;
			}
			current_dst = current_dst->next;
		}
		src->target = target;
		src = src->next;
	}
}

static void	set_price(t_node *src, t_node *dst)
{
	int	size_a;
	int	size_b;
	int	tmp;

	size_a = stack_size(src);
	size_b = stack_size(dst);
	while (src)
	{
		if (src->upper_half)
			src->price = src->pos;
		else
			src->price = size_a - src->pos;
		if (src->target->upper_half)
			tmp = src->target->pos;
		else
			tmp = size_b - src->target->pos;
		if (src->upper_half == src->target->upper_half)
		{
			if (src->price < tmp)
				src->price = tmp;
		}
		else
			src->price += tmp;
		src = src->next;
	}
}

void	set_pos(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->pos = i;
		if (i <= stack_size(stack) / 2)
			stack->upper_half = true;
		else
			stack->upper_half = false;
		stack = stack->next;
		i++;
	}
}

void	set_nodes(t_node *a, t_node *b, char name)
{
	set_pos(a);
	set_pos(b);
	if (name == 'a')
	{
		set_target_a(a, b);
		set_price(a, b);
	}
	else
		set_target_b(b, a);
}
