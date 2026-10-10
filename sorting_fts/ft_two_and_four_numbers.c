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

void	ft_two_numbers(t_stack *a)
{
	t_node	**stack_a;

	stack_a = a->stack;
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(a, 1);
}

int	ft_find_smallest(t_node *stack)
{
	int		min_value;
	int		current_value;
	t_node	*tmp;

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

void	push_smallest(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*a;
	t_node	*b;

	i = 0;
	a = *(stack_a->stack);
	while (a)
	{
		b = *(stack_a->stack);
		if (a->value == ft_find_smallest(b))
			break ;
		a = a->next;
		i++;
	}
	if (i <= stack_a->size / 2)
	{
		while (--i >= 0)
			ra(stack_a, 1);
	}
	else
	{
		while (++i <= stack_a->size)
			rra(stack_a, 1);
	}
	pb(stack_b, stack_a, 1);
}

void	ft_four_numbers(t_stack *a, t_stack *b)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = a->stack;
	stack_b = b->stack;
	push_smallest(a, b);
	ft_three_numbers(a);
	pa(a, b, 1);
}
