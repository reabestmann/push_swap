/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:30:41 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 12:18:41 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*checks if input is in valid syntax*/
int	syntax_error(char *str)
{
	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (1);
	while (*++str)
	{
		if (!(ft_isdigit(*str)))
			return (1);
	}
	return (0);
}

/*checks if any values are duplicates*/
int	duplicate_error(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*frees the input array after usage*/
void	free_array(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
}

/*frees the stack after usage*/
void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

/*frees data and writes an Error message 
	to stderr in case of Errors*/
void	free_error(t_node **a, char **input)
{
	free_array(input);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
