/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:13 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 10:50:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Aggiungo un elemento all'inizio della lista, passando un pointer ad essa */

void	ft_list_addfront(t_stack **list, t_stack *new)
{
	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		(*list)->prev = NULL;
		(*list)->next = NULL;
		return ;
	}
	(*list)->prev = new;
	new->prev = NULL;
	new->next = (*list);
	if ((*list)->prev != NULL)
		(*list)->prev = new;
	*list = new;
}
