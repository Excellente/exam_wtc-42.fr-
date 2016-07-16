/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:09:43 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/16 01:49:32 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		last_word(char *str)
{
	int i;
	int index;;

	i = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while ((str[index] == '	' || str[index] == ' ')  && str[index] != '\0')
				index++;
		while (str[index] != '	' && str[index] != ' ' && str[index] != '\0')
		{
			index++;
			i = index - 1;
		}
	}
	return (i);
}

void	expand_str(char *str)
{
	int i;
	int j;
	int index;
	char expanded[1024];

	i = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while ((str[index] == '	' || str[index] == ' ')  && str[index] != '\0')
			index++;
		while (str[index] != 9 && str[index] != 32 && str[index] != '\0')
			expanded[i++] = str[index++];
		if (index < last_word(str))
		{
			j = 0;
			while (j++ < 1)
				expanded[i++] = ' ';
		}
	}
	expanded[i] = '\0';
	write(1, expanded, ft_strlen(expanded));
}

int	main(int argc, char **argv)
{
	if (argc > 0)
	if (argc == 2 && ft_strlen(argv[1]) > 0)
		expand_str(argv[1]);
	write(1, "\n", 1);
}
