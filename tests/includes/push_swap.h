/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:38:40 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/08 17:43:44 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_node
{
	int		value;
	int		pos;
	int		price;
	bool		upper_half;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

//parsing & validation (input_handling.c)
int	input_valid(int params, char **argv);
int	has_duplicates(t_node *stack);
void	parse_input(t_node **a, int argc, char **argv);
long	ft_atol(const char *str);

//stack operations (stack_utils.c)
void	free_stack(t_node **stack);
void    append_node(t_node **stack, int value);
void	print_stack(t_node *stack); //delete later!

//sorting implementation (sort_stack_helpers.c & sort_stack.c)
int	sort_stack(t_node **a, t_node **b);
int	sort_three(t_node **stack);
int	push_swap(t_node **a, t_node **b, int size);
int	is_sorted(t_node *stack);
int	stack_size(t_node *stack);
t_node	*find_smallest(t_node *stack);

//move calculation (move_calculation.c)
void	update_nodes(t_node *a, t_node *b);
void	set_target(t_node *a, t_node *b);
void	set_price(t_node *a, t_node *b);
t_node	*find_cheapest(t_node *b);
void	set_pos(t_node *stack);

//swap (swap.c)
void	swap(t_node **stack);
int	sa(t_node **a);
int	sb(t_node **b);
int	ss(t_node **a, t_node **b);

//push (push.c)
void	push(t_node **src, t_node **dest);
int	pa(t_node **a, t_node **b);
int	pb(t_node **a, t_node **b);

//rotate (rotate.c)
void	rotate(t_node **stack);
int	ra(t_node **a);
int	rb(t_node **b);
int	rr(t_node **a, t_node **b, t_node *cheapest);

//reverse rotate (reverse_rotate.c)
void	reverse_rotate(t_node **stack);
int	rra(t_node **a);
int	rrb(t_node **b);
int	rrr(t_node **a, t_node **b, t_node *cheapest);

//test function - delete later
void	test_operations(int params, char **argv);

#endif
