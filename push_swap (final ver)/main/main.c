/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:11 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/16 11:48:17 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

/*/for debugging
void    print_stack(t_node *stack)
{
        if (!stack)
        {
                ft_printf("Stack is empty.\n");
                return ;
        }
        while (stack)
        {
                ft_printf("%i\n", stack->value);
                stack = stack->next;
        }
        ft_printf("\n");
}

void	operations_debug(t_node *stack_a, t_node *stack_b)
{
//Test swap (sa)
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
	print_stack(stack_a);
}

int     main(int params, char **argv)
{
        t_node  *a;
        t_node  *b;
	int		moves;
        int             size;

        a = NULL;
        b = NULL;
        if (params == 1 || (params == 2 && !argv[1][0]))
                return (1);
        parse_input(&a, argv + 1);
        if (!a)
                return (1);
        size = stack_size(a);
	ft_printf("\nInitial Stack:\n");
	print_stack(a);
//	operations_debug(a, b);
	moves = 0;
        if (!is_sorted(a))
        {
                if (size == 2)
                        moves += sa(&a);
                else if (size == 3)
                        moves += sort_three(&a);
                else
                        moves += push_swap(&a, &b, size);
        }
	ft_printf("\nStack after sorting:\n");
	print_stack(a);
	ft_printf("Stack size: %i\nMoves: %i\n", size, moves);
        free_stack(&a);
        return (0);
}*/

int	main(int params, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (params < 2 || (params == 2 && !argv[1][0]))
		return (1);
	parse_input(&a, argv + 1);
	if (!a)
		return (1);
	size = stack_size(a);
	if (!is_sorted(a))
	{
		if (size == 2)
			sa(&a);
		else if (size == 3)
			sort_three(&a);
		else
			push_swap(&a, &b, size);
	}
	free_stack(&a);
	return (0);
}
