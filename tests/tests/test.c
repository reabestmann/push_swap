/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:45:32 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/03 15:58:17 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	test_operations(int params, char **argv)
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

//parse input and create stack
	stack_a = parse_input(params, argv);
	if (!stack_a)
	{
		ft_printf("Error: Invalid Input!\n");
		return ;
	}
	ft_printf("Initial Stack A:\n(Size: %i)\n", stack_size(stack_a));
	print_stack(stack_a);
	ft_printf("\n");
/*//Test swap (sa)
	ft_printf("\nAfter sa (swap the first two elements of A):\n");
	sa(&stack_a);
	print_stack(stack_a);
//Test push
	ft_printf("\nAfter pb (push top of A to B):\n");
	pb(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	print_stack(stack_a);
	ft_printf("Stack B:\n");
	print_stack(stack_b);
	ft_printf("\nAfter pa (push top of B to A):\n");
        pa(&stack_a, &stack_b);
        ft_printf("Stack A:\n");
        print_stack(stack_a);
        ft_printf("Stack B:\n");
        print_stack(stack_b);

//Test rotate (ra)
	ft_printf("\nAfter ra (rotate A up by 1):\n");
	ra(&stack_a);
	print_stack(stack_a);
//Test reverse rotate (rra)
	ft_printf("\nAfter rra (reverse rotate A down by 1):\n");
	rra(&stack_a);
	print_stack(stack_a);*/
//Test sorting
	ft_printf("\nNumber of operations: %i\n", sort_stack(&stack_a));
	ft_printf("\nAfter Sorting:\n");
	print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
