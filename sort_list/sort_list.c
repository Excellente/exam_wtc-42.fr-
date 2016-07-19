/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:42:47 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/19 10:49:21 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *p;
	t_list *prev;

	prev = lst;
	while (prev)
	{
		p = prev->next;
		while (p)
		{
			if ((*cmp)(prev->data, p->data) == 0)
				swap(&prev->data, &p->data);
			p = p->next;
		}
		prev = prev->next;
	}
	return (lst);
}
