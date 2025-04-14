/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/14 02:57:58 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	append_node(t_node **stack, int value)
{
	t_node	*node;
	t_node	*current;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	parse_input(t_node **a, char **argv)
{
	char	**input;
	long	n;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		input = ft_split(argv[i], ' ');
		while (input[j])
		{
			if (syntax_error(input[j]))
				free_error(a, input);
			n = ft_atol(input[j]);
			if (n > INT_MAX || n < INT_MIN)
				free_error(a, input);
			if (duplicate_error(*a, (int)n))
				free_error(a, input);
			append_node(a, (int)n);
			j++;
		}
		free_array(input);
		i++;
	}
}
