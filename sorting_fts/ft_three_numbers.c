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

void	ft_three_numbers(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index
		< ft_list_last(*stack_a)->index)
		sa(stack_a, 1);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > ft_list_last(*stack_a)->index)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index > (*stack_a)->index
		&& (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		return ;
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index < ft_list_last(*stack_a)->index)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > ft_list_last(*stack_a)->index)
		rra(stack_a, 1);
}
