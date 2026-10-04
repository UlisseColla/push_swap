/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:49:12 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 10:50:48 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_list_find_node(t_stack *list, int value)
{
	while (list)
	{
		if (list->value == value)
		{
			return (list);
		}
		list = list->next;
	}
	return (NULL);
}

t_stack	*ft_list_find_index(t_stack *list, int index)
{
	while (list)
	{
		if (list->index == index)
			return (list);
		list = list->next;
	}
	return (NULL);
}
