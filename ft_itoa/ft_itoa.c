/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 15:01:17 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/21 15:52:25 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_int_len(int nbr)
{
	int len;
	int tmp;

	len = 0;
	tmp = nbr;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (nbr == 0)
		len++;
	return (len);
}

char	*ft_itoa(int nbr)
{
	int			len;
	int			tmp;
	int			neg;
	char		*str;
	int			min_int;

	neg = 0;
	tmp = 0;
	min_int = -2147483648;
	if (nbr < 0 && nbr == min_int)
		return ("-2147483648");
	len = get_int_len(nbr);
	if((str = (char *)malloc(sizeof(int) * (len + 2))) == 0)
		return (str);
	if (nbr < 0)
		neg = 1;
	if (neg == 1)
	{
		tmp = -nbr;
		str[0] = '-';
	}
	if (neg && nbr != 0)
		str[len + 1] = '\0';
	else
		str[len] = '\0';
	if (!neg && nbr != 0)
	{
		tmp = nbr;
		len--;
	}
	while (tmp)
	{
		str[len--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (nbr == 0)
		str[--len] = '0';
	return (str);
}
