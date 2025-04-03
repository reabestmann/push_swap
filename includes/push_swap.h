/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:38:40 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/02 14:56:31 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_node
{
	int		value;
	struct s_node	*next;
}	t_node;

//parsing & validation (input_handling.c)
int	check_numbers(int params, char **argv);
int	has_duplicates(t_node *stack);
t_node	*parse_input(int argc, char **argv);

//stack operations (stack_utils.c)
void	free_stack(t_node **stack);
void	append_node(t_node **stack, int value);
t_node	*new_node(int value);
void	print_stack(t_node *stack); //delete later!

//swap (swap.c)
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

//push (push.c)
void	push(t_node **src, t_node **dest);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

//rotate (rotate.c)
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

//reverse rotate (reverse_rotate.c)
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

//test function - delete later
void	test_operations(int params, char **argv);

#endif
