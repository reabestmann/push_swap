/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_explained.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/03/29 14:27:37 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//only valid input can join our stack. This function checks if all arguments are digits or signs.

int	check_numbers(int params, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < params) //go through all arguments
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+') //allow signs before digits
			j++;
		if (!argv[i][j]) //if no digit follows, its invalid
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ') //not a number? Error!
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//this function checks if any number appears more than once

int	has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current) //go through each node
	{
		checker = current->next; //compare it with the rest of the list
		while (checker)
		{
			if (current->value == checker->value) //found a duplicate!
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0); //no duplicates!
}

//this function reads input, converts it into numbers, and builds the stack.

t_node	*parse_input(int params, char **argv)
{
	t_node	*stack;
	char	**numbers;
	int	i;
	int	j;

	stack = NULL;
	i = 0;
	while (i < params) //go through all inut strings
	{
		numbers = ft_split(argv[i], ' '); //split each argument into numbers
		j = 0;
		while (numbers[j])
		{
			append_node(&stack, ft_atoi(numbers[j])); //convert & add to stack
			free(numbers[j]); //free after use
			j++;
		}
		free(numbers); //free array itself
		i++;
	}
	return (stack); //stack is ready!

}
