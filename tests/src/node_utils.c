/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:05 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/14 04:46:43 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_better_target(t_node *src, t_node *dst, t_node *best, char name)
{
	if (name == 'a')
	{
		if (dst->value > src->value)
		{
			if (!best || dst->value < best->value)
				return (1);
		}
	}
	else
	{
		if (dst->value < src->value)
		{
			if (!best || dst->value > best->value)
				return (1);
		}
	}
	return (0);
}

static void	set_target(t_node *src, t_node *dst, char name)
{
	t_node	*current_src;
	t_node	*current_dst;
	t_node	*best;

	current_src = src;
	while (current_src)
	{
		best = NULL;
		current_dst = dst;
		while (current_dst)
		{
			if (is_better_target(current_src, current_dst, best, name))
				best = current_dst;
			current_dst = current_dst->next;
		}
		if (!best)
		{
			if (name == 'a')
				best = find_smallest(dst);
			else
				best = find_biggest(dst);
		}
		current_src->target = best;
		current_src = current_src->next;
	}
}

/*static void	set_target_b(t_node *src, t_node *dst)
{
	t_node	*current_dst;
	t_node	*target;
	long	match;

	while (src)
	{
		current_dst = dst;
		match = LONG_MAX;
		target = find_smallest(a);
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
			if (current_dst->value < src->value && dst->value > match)
			{
				match = current_dst->value;
				target = current_dst;
			}
			current_dst = current_dst->next;
		}
		src->target = target;
		src = src->next;
	}
}*/

static void	set_price(t_node *src, t_node *dst)
{
	while (src)
	{
		src->price = src->pos;
		if (!(src->upper_half))
			src->price = stack_size(src) - (src->pos);
		if (src->target->upper_half)
			src->price += src->target->pos;
		else
			src->price += stack_size(dst) - (src->target->pos);
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

void	set_nodes(t_node *a, t_node *b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b, 'a');
	set_price(a, b);
	set_target(b, a, 'b');
}
