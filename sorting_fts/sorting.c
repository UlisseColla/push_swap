/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 15:58:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_smallest_on_top(t_node **stack)
{
	while ((*stack)->index != find_smallest(*stack))
	{
		if (find_eff(*stack, find_smallest(*stack)) > (ft_list_size(stack) / 2))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}

int	ft_check_push(t_node *stack, int c_1, int c_2)
{
	while (stack)
	{
		if (stack->chunk == c_1 || stack->chunk == c_2)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_eff(t_node *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a;
	t_node	*b;

	a = stack_a->stack;
	b = stack_b->stack;
	while (ft_list_size(&a) > 3 && ft_check_push(a, 1, 4) == 0)
		push_a_to_b(&a, &b, 1, 4);
	while (ft_list_size(&a) > 3 && ft_check_push(a, 2, 3) == 0)
		push_a_to_b(&a, &b, 2, 3);
	ft_three_numbers(&a);
	while (b->next)
		push_b_to_a(&b, &a);
	push_b_to_a(&b, &a);
	ft_smallest_on_top(&a);
}
