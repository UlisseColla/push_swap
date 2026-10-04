/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:57 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 10:50:52 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Aggiungo un elemento in fondo alla lista, passando un pointer ad essa */

void	ft_list_addback(t_stack **list, t_stack *new)
{
	t_stack	*tmp;

	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}
