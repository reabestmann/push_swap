/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/08 17:43:32 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int	i;
	int	sign;

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

int	input_valid(int params, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < params)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			j++;
			if (!argv[i][j] || !ft_isdigit(argv[i][j]))
				return (1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

void	parse_input(t_node **a, int params, char **argv)
{
	long	nbr;
	char	**numbers;
	int	i;
	int	j;

	i = 1;
	while (i < params)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;	
		while (numbers[j])
		{
			nbr = ft_atol(numbers[j]);
			ft_printf("num: %i\n", nbr);
			if (nbr > INT_MAX || nbr < INT_MIN)
			{
				while (numbers[j])
					free(numbers[j++]);
				free(numbers);
				return;
			}
			append_node(a, (int)nbr);
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
}
