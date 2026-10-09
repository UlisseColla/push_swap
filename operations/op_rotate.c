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

void	ra(t_stack *s, int i)
{
	t_node	*value;
	t_node	**stack;

	if (s->size < 2)
		return ;
	stack = s->stack;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *s, int i)
{
	t_node	*value;
	t_node	**stack;

	if (s->size < 2)
		return ;
	stack = s->stack;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
