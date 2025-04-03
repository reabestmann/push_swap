/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:05 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/03 17:49:09 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_cal(
int	find_cheapest_move(t_node *stack_a, t_node *stack_b)
{
	int	moves;
	int	min_moves;
	int	best_num;

	min_moves = INT_MAX;
	best_num = -1;
	while (stack_a)
	{
		moves = calculate_moves(stack_a->value, stack_a, stack_b);
		if (moves < min_moves)
		{
			min_moves = moves;
			best_num = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return (best_num);
}	
