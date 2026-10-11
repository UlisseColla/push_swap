/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:44:10 by aconciar          #+#    #+#             */
/*   Updated: 2026/10/11 14:18:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_three_numbers(t_stack *a)
{
	if ((*a->stack)->index > (*a->stack)->next->index && (*a->stack)->index
		< ft_list_last(*a->stack)->index)
		sa(a, 1);
	else if ((*a->stack)->index > (*a->stack)->next->index
		&& (*a->stack)->next->index > ft_list_last(*a->stack)->index)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if ((*a->stack)->index > (*a->stack)->next->index
		&& (*a->stack)->next->index < ft_list_last(*a->stack)->index)
		ra(a, 1);
	else if ((*a->stack)->next->index > (*a->stack)->index
		&& (*a->stack)->next->index < ft_list_last(*a->stack)->index)
		return ;
	else if ((*a->stack)->index < (*a->stack)->next->index
		&& (*a->stack)->index < ft_list_last(*a->stack)->index)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if ((*a->stack)->index < (*a->stack)->next->index
		&& (*a->stack)->index > ft_list_last(*a->stack)->index)
		rra(a, 1);
}
