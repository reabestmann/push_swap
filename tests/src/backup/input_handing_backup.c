/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/13 18:16:26 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_error(int params, char **argv)
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

int	duplicate_error(t_node *stack)
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

void	free_array(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

void	parse_input(t_node **a, int params, char **argv)
{
	char	**numbers;

	if (params == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	create_stack(a, params, numbers);
	if (a && params == 2)
		free_array(numbers);
	if (check_duplicates(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
	}
}
