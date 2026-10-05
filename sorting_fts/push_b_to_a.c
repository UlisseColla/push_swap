/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:15:40 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 17:38:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_operations_b(t_node **b, t_node **a, t_operator operator)
{
	while (operator.rr > 0)
	{
		rr(a, b, 1);
		operator.rr--;
	}
	while (operator.rb > 0)
	{
		rb(b, 1);
		operator.rb--;
	}
	while (operator.ra > 0)
	{
		ra(a, 1);
		operator.ra--;
	}
}

void	rr_operations_b(t_node **b, t_node **a, t_operator operator)
{
	while (operator.rrr > 0)
	{
		rrr(a, b, 1);
		operator.rrr--;
	}
	while (operator.rrb > 0)
	{
		rrb(b, 1);
		operator.rrb--;
	}
	while (operator.rra > 0)
	{
		rra(a, 1);
		operator.rra--;
	}
}

void	push_b_to_a(t_node **stack_b, t_node **stack_a)
{
	t_operator	operator;

	check_efficiency(*stack_b, *stack_a, &operator);
	r_operations_b(stack_b, stack_a, operator);
	rr_operations_b(stack_b, stack_a, operator);
	pa(stack_a, stack_b, 1);
	if ((*stack_a)->index == find_biggest(*stack_a))
		ra(stack_a, 1);
}
