/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:42 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 12:20:49 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns last node of the stack*/
t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*returns the 'cheapest' node of a stack*/
t_node	*find_cheapest(t_node *stack)
{
	long	cheapest_price;
	t_node	*cheapest;

	if (stack == NULL)
		return (NULL);
	cheapest_price = LONG_MAX;
	cheapest = NULL;
	while (stack)
	{
		if (stack->price < cheapest_price)
		{
			cheapest_price = stack->price;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

/*returns the node with the smallest value of a stack*/
t_node	*find_smallest(t_node *stack)
{
	long	smallest_value;
	t_node	*smallest;

	smallest_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

/*returns the node with the biggest value of a stack*/
t_node	*find_biggest(t_node *stack)
{
	long	biggest_value;
	t_node	*biggest;

	biggest_value = LONG_MIN;
	while (stack)
	{
		if (stack->value > biggest_value)
		{
			biggest_value = stack->value;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}
