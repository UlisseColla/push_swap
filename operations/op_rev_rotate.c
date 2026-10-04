/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:14:30 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 18:01:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack, int i)
{
	t_stack	*value;
	t_stack	*seclast_node;

	if (ft_list_size(stack) < 2)
		return ;
	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_list_addfront(stack, value);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack, int i)
{
	t_stack	*value;
	t_stack	*seclast_node;

	if (ft_list_size(stack) < 2)
		return ;
	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_list_addfront(stack, value);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (ft_list_size(stack_a) < 2 || ft_list_size(stack_b) < 2)
		return ;
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
