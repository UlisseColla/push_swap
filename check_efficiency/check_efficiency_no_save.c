/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_no_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:26:07 by aconciar          #+#    #+#             */
/*   Updated: 2026/10/10 18:02:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	counter_a(t_node *stack_a, int s, int index, t_operator *operator)
{
	int	moves;
	int	biggest;
	int	smallest;

	biggest = find_biggest(stack_a);
	smallest = find_smallest(stack_a);
	if ((index > biggest
			&& biggest == ft_list_last(stack_a)->index)
		|| (index < smallest
			&& smallest == stack_a->index))
	{
		operator->rra = 0;
		operator->ra = 0;
		return ;
	}
	moves = moves_counter_no_save(0, stack_a, index);
	operator->rra = s - moves;
	operator->ra = moves;
}

static void	counter_b(t_node *stack_b, int s, int index, t_operator *operator)
{
	int	moves;

	moves = 0;
	if (stack_b->index == index)
	{
		operator->rrb = 0;
		operator->rb = 0;
		return ;
	}
	while (stack_b->index != index && stack_b->next)
	{
		moves++;
		stack_b = stack_b->next;
	}
	operator->rrb = s - moves;
	operator->rb = moves;
}

static void	check_operator_rr_rrr(t_operator *operator)
{
	if (operator->ra < operator->rb)
	{
		operator->rr = operator->ra;
		operator->rb -= operator->ra;
		operator->ra = 0;
	}
	else
	{
		operator->rr = operator->rb;
		operator->ra -= operator->rb;
		operator->rb = 0;
	}
	if (operator->rra < operator->rrb)
	{
		operator->rrr = operator->rra;
		operator->rrb -= operator->rra;
		operator->rra = 0;
	}
	else
	{
		operator->rrr = operator->rrb;
		operator->rra -= operator->rrb;
		operator->rrb = 0;
	}
}

int	eff_counter_no_save(t_helper *h_a, t_helper *h_b, int index)
{
	int			r_moves;
	int			rr_moves;
	t_operator	operator;

	r_moves = 0;
	rr_moves = 0;
	counter_b(h_b->node, h_b->size, index, &operator);
	counter_a(h_a->node, h_a->size, index, &operator);
	check_operator_rr_rrr(&operator);
	r_moves += operator.ra + operator.rb + operator.rr;
	rr_moves += operator.rra + operator.rrb + operator.rrr;
	if (r_moves < rr_moves)
	{
		operator.rra = 0;
		operator.rrb = 0;
		operator.rrr = 0;
		return (r_moves);
	}
	else
	{
		operator.ra = 0;
		operator.rb = 0;
		operator.rr = 0;
		return (rr_moves);
	}
}
