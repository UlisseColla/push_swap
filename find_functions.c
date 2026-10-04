/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:14:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 15:11:32 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	min_value;
	int	current_value;

	min_value = INT_MAX;
	while (stack)
	{
		current_value = stack->index;
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

int	find_biggest(t_stack *stack)
{
	int	max_value;
	int	current_value;

	max_value = INT_MIN;
	while (stack)
	{
		current_value = stack->index;
		if (current_value > max_value)
			max_value = current_value;
		stack = stack->next;
	}
	return (max_value);
}

int	find_smallest_after_index(t_stack *stack, int index)
{
	int	current_value;
	int	min_value;

	min_value = INT_MAX;
	while (stack)
	{
		current_value = stack->index;
		if (current_value < min_value && current_value > index)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

int	find_biggest_before_index(t_stack *stack, int index)
{
	int	current_value;
	int	max_value;

	max_value = INT_MIN;
	while (stack)
	{
		current_value = stack->index;
		if (current_value > max_value && current_value < index)
			max_value = current_value;
		stack = stack->next;
	}
	return (max_value);
}
