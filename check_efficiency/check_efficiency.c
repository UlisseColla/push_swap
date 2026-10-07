/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:02:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 15:56:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_rra_counter_a(t_node *stack_a, int index, t_operator **operator)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(&stack_a);
	moves = 0;
	if ((index > find_biggest(stack_a)
			&& find_biggest(stack_a) == ft_list_last(stack_a)->index)
		|| (index < find_smallest(stack_a)
			&& find_smallest(stack_a) == stack_a->index))
	{
		(*operator)->rra = 0;
		(*operator)->ra = 0;
		return ;
	}
	moves = moves_counter(0, stack_a, index);
	(*operator)->rra = stack_size - moves;
	(*operator)->ra = moves;
}

void	rb_rrb_counter_b(t_node *stack_b, int index, t_operator **operator)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(&stack_b);
	moves = 0;
	if (stack_b->index == index)
	{
		(*operator)->rrb = 0;
		(*operator)->rb = 0;
		return ;
	}
	while (stack_b->index != index && stack_b->next)
	{
		moves++;
		stack_b = stack_b->next;
	}
	(*operator)->rrb = stack_size - moves;
	(*operator)->rb = moves;
}

void	eff_counter(t_node *a, t_node *b, int index, t_operator **operator)
{
	int	r_moves;
	int	rr_moves;

	r_moves = 0;
	rr_moves = 0;
	rb_rrb_counter_b(b, index, operator);
	ra_rra_counter_a(a, index, operator);
	counter_rr_rrr(operator);
	r_moves += (*operator)->ra + (*operator)->rb + (*operator)->rr;
	rr_moves += (*operator)->rra + (*operator)->rrb + (*operator)->rrr;
	if (r_moves < rr_moves)
	{
		(*operator)->rra = 0;
		(*operator)->rrb = 0;
		(*operator)->rrr = 0;
	}
	else
	{
		(*operator)->ra = 0;
		(*operator)->rb = 0;
		(*operator)->rr = 0;
	}
}

/* Check double useless double pointers for t_operator */

/** Pass t_helper instead of single node to be able to pass the size value. 
 * Safe to do it this way cause I only need to read the size value. 
 * */
void	check_efficiency(t_helper *h_b, t_helper *h_a, t_operator *operator)
{
	t_helper	temp_a;
	t_helper	temp_b;
	int			min_moves;
	int			current_moves;
	int			index_min_value;

	min_moves = INT_MAX;
	temp_a = (t_helper){h_a->node, h_a->size};
	temp_b = (t_helper){h_b->node, h_b->size};
	while (h_b->node)
	{
		current_moves = eff_counter_no_save(&temp_a, &temp_b, h_b->node->index);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			index_min_value = h_b->node->index;
		}
		h_b->node = h_b->node->next;
	}
	eff_counter(temp_a, temp_b, index_min_value, &operator);
}
