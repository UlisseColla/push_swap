/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:15:40 by aconciar          #+#    #+#             */
/*   Updated: 2026/10/10 18:16:12 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_operations_b(t_stack *b, t_stack *a, t_operator *operator)
{
	while (operator->rr > 0)
	{
		rr(a, b, 1);
		operator->rr--;
	}
	while (operator->rb > 0)
	{
		rb(b, 1);
		operator->rb--;
	}
	while (operator->ra > 0)
	{
		ra(a, 1);
		operator->ra--;
	}
}

static void	rr_operations_b(t_stack *b, t_stack *a, t_operator *operator)
{
	while (operator->rrr > 0)
	{
		rrr(a, b, 1);
		operator->rrr--;
	}
	while (operator->rrb > 0)
	{
		rrb(b, 1);
		operator->rrb--;
	}
	while (operator->rra > 0)
	{
		rra(a, 1);
		operator->rra--;
	}
}

void	push_b_to_a(t_stack *s_b, t_stack *s_a)
{
	t_operator	operator;
	t_node		**stack_a;
	t_node		**stack_b;
	t_helper	h_a;
	t_helper	h_b;

	stack_a = s_a->stack;
	stack_b = s_b->stack;
	h_a = (t_helper){(*stack_a), s_a->size};
	h_b = (t_helper){(*stack_b), s_b->size};
	check_efficiency(&h_b, &h_a, &operator);
	r_operations_b(s_b, s_a, &operator);
	rr_operations_b(s_b, s_a, &operator);
	pa(s_a, s_b, 1);
	if ((*stack_a)->index == find_biggest(*stack_a))
		ra(s_a, 1);
}
