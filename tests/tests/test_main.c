/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:11 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/08 17:44:02 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

int     main(int params, char **argv)
{
        t_node  *a;

        a = NULL;
        if (params < 2)
                return (0);
        if (!input_valid(params, argv))
        {
                ft_printf("Error\n");
                return (1);
        }
        parse_input(&a, params, argv);
        if (has_duplicates(a))
        {
                ft_printf("Error\n");
                free_stack(&a);
                return (1);
        }
//only for testing, take out later
	test_operations(params, argv);
	free_stack(&a);
        return (0);
}
