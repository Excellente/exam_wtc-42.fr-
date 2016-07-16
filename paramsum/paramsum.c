/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parasum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 04:16:11 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/16 04:38:13 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr  < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	main(int argc, char **argv)
{
	int i;

	i = argc - 1;;
	if (argc > 1)
	{
		while (*argv++)
			;
		ft_putnbr(i);
	}
	else
	{
		ft_putchar(48);
	}
	ft_putchar('\n');
	return (0);
}
