/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:05 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/07 18:45:58 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target;
	long	match_value;

	while (b)
	{
		match_value = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < match_value)
			{
				match_value = current->value;
				target = current;
			}
			current = current->next;
		}
		if (match_value == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	while (b)
	{
		b->price = b->pos;
		if (!(b->upper_half))
			b->price = stack_size(b) - (b->pos);
		if (b->target->upper_half)
			b->price += b->target->pos;
		else
			b->price += stack_size(a) - (b->target->pos);
		b = b->next;
	}
}

t_node	*find_cheapest(t_node *b)
{
	long	cheapest_price;
	t_node	*current;

	if (b == NULL)
		return (NULL);
	cheapest_price = LONG_MAX;
	while (b)
	{
		if (b->price < cheapest_price)
		{
			cheapest_price = b->price;
			current = b;
		}
		b = b->next;
	}
	return (current);
}

void	update_nodes(t_node *a, t_node *b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b);
	set_price(a, b);
	find_cheapest(b);
}
