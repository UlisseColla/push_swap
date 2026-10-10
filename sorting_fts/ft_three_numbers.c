/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:44:10 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:45 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_three_numbers(t_stack *a)
{
	t_node	**stack_a;

	stack_a = a->stack;
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index
		< ft_list_last(*stack_a)->index)
		sa(a, 1);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > ft_list_last(*stack_a)->index)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		ra(a, 1);
	else if ((*stack_a)->next->index > (*stack_a)->index
		&& (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		return ;
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index < ft_list_last(*stack_a)->index)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > ft_list_last(*stack_a)->index)
		rra(a, 1);
}
