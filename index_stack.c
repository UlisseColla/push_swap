/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:26:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/05 11:00:00 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_find_smallest(t_node **stack)
{
	int		min_value;
	int		current_value;
	t_node	*tmp;

	min_value = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value && tmp->has_index == false)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	index_stack_init(t_node **stack, int i, int c)
{
	int		tmp;
	int		list_size;
	int		smallest;
	t_node	*b;
	t_node	*target;

	tmp = 1;
	list_size = ft_list_size(stack);
	b = *stack;
	while (i <= list_size)
	{
		smallest = index_find_smallest(&b);
		target = ft_list_find_node(b, smallest); 
		target->index = i;
		target->has_index = true;
		target->chunk = c;
		if (tmp == list_size / 4)
		{
			c++;
			tmp = 0;
		}
		i++;
		tmp++;
	}
}
