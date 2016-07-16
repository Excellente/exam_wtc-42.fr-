/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:05:17 by exam              #+#    #+#             */
/*   Updated: 2016/07/16 09:56:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	toupper(char *s)
{
	if (*s >= 97 && *s <= 122)
		*s = *s - 32;
}

void	tolower(char *s)
{
	if (*s >= 65 && *s <= 90)
		*s = *s + 32;
}

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	rcapitalizer(int argc, char **argv)
{
	int i;
	int index;

	i = 1;
	index = 0;
	while (argv[i] != '\0')
	{
		while ((argv[i][index] == 9 || argv[i][index] == 32) && argv[i][index] != '\0')
			index++;
		while (argv[i][index] != 9 && argv[i][index] != 32 && argv[i][index] != '\0')
		{
			tolower(&argv[i][index]);
			index++;
		}
		toupper(&argv[i][index - 1]);
		if (argv[i][index] == '\0')
		{
			index = 0;
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rcapitalizer(argc, argv);
	else
		write(1, "\n", 1);
	return (0);
}
