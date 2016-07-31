/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 13:34:15 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/31 14:51:36 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_intlen(int value, int base)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = value;
	if (value == 0)
		return (1);
	while (tmp)
	{
		len++;
		tmp /= base;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	int				len;
	char			*str;
	long	int		tmp;
	char	digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	tmp = (long int)value;
	if (value == 0)
		return ("0");
	len = get_intlen(value, base);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (value < 0)
	{
		tmp *= -1;
		if (base == 10)
		{
			str[0] = '-';
			str[len + 1] = '\0';
		}
		else
			str[len--] = '\0';
	}
	else
		str[len--] = '\0';
	while (tmp)
	{
		str[len--] = digits[(tmp % base)];
		tmp /= base;
	}
	return (str);
}
