/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:29:28 by ucolla            #+#    #+#             */
/*   Updated: 2026/10/10 18:07:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	counter_rr_rrr(t_operator *operator)
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

static void	moves_counter_helper(int *ids, t_node *a, int index)
{
	ids[0] = find_smallest_after_index(a, index);
	ids[1] = find_biggest(a);
	ids[2] = find_biggest_before_index(a, index);
}

int	moves_counter(int moves, t_node *a, int index)
{
	int	ids[3];

	moves_counter_helper(ids, a, index);
	if (index > ids[1])
	{
		while (a->next && a->index != ids[2])
		{
			moves++;
			a = a->next;
		}
		if (a->index == ids[2])
		{
			moves++;
			a = a->next;
		}
	}
	else
	{
		while (a->next && a->index != ids[0])
		{
			moves++;
			a = a->next;
		}
	}
	return (moves);
}
