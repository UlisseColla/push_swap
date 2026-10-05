/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 18:04:23 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **stack, int i)
{
	t_node	*value;

	if (ft_list_size(stack) < 2)
		return ;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack, int i)
{
	t_node	*value;

	if (ft_list_size(stack) < 2)
		return ;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, int i)
{
	if (ft_list_size(stack_a) < 2 || ft_list_size(stack_b) < 2)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
