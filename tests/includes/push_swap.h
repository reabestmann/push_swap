/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:38:40 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/14 05:22:22 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				pos;
	int				price;
	bool			upper_half;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

/*create_stack.c*/
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	parse_input(t_node **a, char **argv);
/*sort_stack.c*/
int		push_swap(t_node **a, t_node **b, int size);
int		sort_three(t_node **a);
/*error_utils.c*/
int		syntax_error(char *str);
int		duplicate_error(t_node *a, int n);
void	free_array(char **input);
void	free_stack(t_node **stack);
void	free_error(t_node **a, char **input);
/*find_nodes.c*/
t_node	*find_last(t_node *stack);
t_node	*find_cheapest(t_node *stack);
t_node	*find_smallest(t_node *stack);
t_node	*find_biggest(t_node *stack);
/*node_utils.c*/
void	set_nodes(t_node *a, t_node *b);
void	set_pos(t_node *stack);
/*push.c*/
int		pa(t_node **a, t_node **b);
int		pb(t_node **a, t_node **b);
/*reverse_rotate.c*/
int		rra(t_node **a);
int		rrb(t_node **b);
int		rrr(t_node **a, t_node **b, t_node *cheapest);
/*rotate.c*/
int		ra(t_node **a);
int		rb(t_node **b);
int		rr(t_node **a, t_node **b, t_node *cheapest);
/*swap.c*/
int		sa(t_node **a);
int		sb(t_node **b);
int		ss(t_node **a, t_node **b);

#endif
