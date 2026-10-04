/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_and_four_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:58:46 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 17:38:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_two_numbers(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

int	ft_find_smallest(t_stack *stack)
{
	int		min_value;
	int		current_value;
	t_stack	*tmp;

	min_value = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = *stack_a;
	while (a)
	{
		b = *stack_a;
		if (a->value == ft_find_smallest(b))
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(stack_a) / 2)
	{
		while (--i >= 0)
			ra(stack_a, 1);
	}
	else
	{
		while (++i <= ft_list_size(stack_a))
			rra(stack_a, 1);
	}
	pb(stack_b, stack_a, 1);
}

void	ft_four_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest(stack_a, stack_b);
	ft_three_numbers(stack_a);
	pa(stack_a, stack_b, 1);
}
