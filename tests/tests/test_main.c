/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:11 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/02 18:14:30 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

int     main(int params, char **argv)
{
        t_node  *stack;

        stack = NULL;
        if (params < 2)
                return (0);
        if (!check_numbers(params, argv))
        {
                ft_printf("Error\n");
                return (1);
        }
        stack = parse_input(params, argv);
        if (has_duplicates(stack))
        {
                ft_printf("Error\n");
                free_stack(&stack);
                return (1);
        }
//only for testing, take out later
	test_operations(params, argv);
//when testing function is taken out, put this line back in:    free_stack(&stack);
        return (0);
}
