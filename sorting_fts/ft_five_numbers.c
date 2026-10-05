/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:25 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_biggest_index(t_node *stack)
{
	int		max_value;
	int		current_value;
	t_node	*tmp;

	max_value = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->index;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
	}
	return (max_value);
}

void	push_biggest(t_node **stack_a, t_node **stack_b, int value)
{
	int		i;
	t_node	*a;

	i = 0;
	a = *stack_a;
	while (a)
	{
		if (a->index == value)
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(stack_a) / 2)
		while (--i >= 0)
			ra(stack_a, 1);
	else
		while (++i <= ft_list_size(stack_a))
			rra(stack_a, 1);
	pb(stack_b, stack_a, 1);
}

void	ft_five_numbers(t_node **stack_a, t_node **stack_b)
{
	push_biggest(stack_a, stack_b, find_biggest_index(*stack_a) - 1);
	push_biggest(stack_a, stack_b, find_biggest_index(*stack_a));
	ft_three_numbers(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
	ra(stack_a, 1);
	ra(stack_a, 1);
}
