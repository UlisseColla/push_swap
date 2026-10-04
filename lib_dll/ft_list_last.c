/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:10 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 10:50:45 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_list_last(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
