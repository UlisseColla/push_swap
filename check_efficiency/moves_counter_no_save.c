/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_no_save.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:59:53 by ucolla            #+#    #+#             */
/*   Updated: 2026/10/10 18:00:08 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	moves_counter_no_save_helper(int *ids, t_node *a, int index)
{
	ids[0] = find_biggest(a);
	ids[1] = find_biggest_before_index(a, index);
	ids[2] = find_smallest_after_index(a, index);
}

int	moves_counter_no_save(int moves, t_node *a, int index)
{
	int	ids[3];

	moves_counter_no_save_helper(ids, a, index);
	if (index > ids[0])
	{
		while (a->next && a->index != ids[1])
		{
			moves++;
			a = a->next;
		}
		if (a->index == ids[1])
		{
			moves++;
			a = a->next;
		}
	}
	else
	{
		while (a->next && a->index != ids[2])
		{
			moves++;
			a = a->next;
		}
	}
	return (moves);
}
