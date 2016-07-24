/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 17:42:11 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/24 18:36:21 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void	*data_ref, int (*cmp)())
{
	t_list	*p;
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp && cmp(tmp->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
		free(tmp);
		tmp = *begin_list;
	}
	p = *begin_list;
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
		{
			p->next = tmp->next;
			free(tmp);
			tmp = p;
		}
		if (p != tmp)
			p = p->next;
		tmp = tmp->next;
	}
	p = 0;
	tmp = 0;
}
