/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 18:14:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **stack, int i)
{
	t_node	*node;

	if (ft_list_size(stack) < 2)
		return ;
	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack, int i)
{
	t_node	*node;

	if (ft_list_size(stack) < 2)
		return ;
	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b, int i)
{
	if (ft_list_size(stack_a) < 2 || ft_list_size(stack_b) < 2)
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_node **stack, t_node **node, int i, t_ls *ls)
{
	t_node	*tmp_node;

	if (!(*node))
		return ;
	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ls->list_a++;
	ls->list_b--;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*tmp_node;
	t_node	*a;
	t_node	*b;

	a = stack_a->stack;
	b = stack_b->stack;
	if (!(*node))
		return ;
	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	if (i == 1)
		write(1, "pb\n", 3);
}
