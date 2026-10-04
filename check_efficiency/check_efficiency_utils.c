/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:29:28 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 15:30:53 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	counter_rr_rrr(t_operator **operator)
{
	if ((*operator)->ra < (*operator)->rb)
	{
		(*operator)->rr = (*operator)->ra;
		(*operator)->rb -= (*operator)->ra;
		(*operator)->ra = 0;
	}
	else
	{
		(*operator)->rr = (*operator)->rb;
		(*operator)->ra -= (*operator)->rb;
		(*operator)->rb = 0;
	}
	if ((*operator)->rra < (*operator)->rrb)
	{
		(*operator)->rrr = (*operator)->rra;
		(*operator)->rrb -= (*operator)->rra;
		(*operator)->rra = 0;
	}
	else
	{
		(*operator)->rrr = (*operator)->rrb;
		(*operator)->rra -= (*operator)->rrb;
		(*operator)->rrb = 0;
	}
}

int	moves_counter(int moves, t_stack *stack_a, int index)
{
	if (index > find_biggest(stack_a))
	{
		while (stack_a->next
			&& stack_a->index != find_biggest_before_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
		if (stack_a->index == find_biggest_before_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	else
	{
		while (stack_a->next
			&& stack_a->index != find_smallest_after_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	return (moves);
}
