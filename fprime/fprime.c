/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:54:39 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/16 04:08:40 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int res;
int original;

int		isfactor(int nbr, int verify)
{
	if (nbr % verify == 0)
		return (1);
	return (0);
}

int		isprime(int c)
{
	int i;

	i = 2;
	if (c < 2)
		return (0);
	while (i < c)
	{
		if (c % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_power(int base, int exp)
{
	int res;

	res = 1;
	if (exp == 0)
		return (1);
	while (exp-- > 0)
		res *= base;
	return (res);
}

void	fprime(nbr)
{
	int i;
	int tmp;

	i = 0;
	original = nbr;
	if (isprime(nbr) || nbr == 1)
	{
		printf("%d", nbr);
		return;
	}
	else
	{
		while (i < nbr)
		{
			if (isprime(i) && isfactor(nbr, i))
			{
				res *= i;
				printf("%d*", i);
				tmp = nbr / i;
				if (res == original)
					t
				if (isprime(tmp))
				{
					printf("%d", tmp);
					return;
				}
				else
					fprime(tmp);
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
