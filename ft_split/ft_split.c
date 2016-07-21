/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:36:24 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/21 18:33:47 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_word_count(char *s)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == 9 || s[i] == 10 || s[i] == 32) && s[i])
			i++;
		if (s[i] != '\0')
		words++;
		while (s[i] != 9 && s[i] != 10 && s[i] != 32 && s[i])
			i++;
	}
	return (words);
}

int		get_word_len(char *s, int index)
{
	int	end;
	int	start;
	int	word_len;

	end = 0;
	word_len = 0;
	start = index;
	while (s[index] != 9 && s[index] != 10 && s[index] != 32 && s[index])
	{
		index++;
		end = index;
	}
	word_len = end - start;
	return (word_len);
}

int     hasword(char *s)
{
    if (get_word_count(s))
        return (1);
    return (0);
}

char	**ft_split(char *str)
{
	int i;
	int	j;
	int	index;
	char *word;
	char **sptr;

	i = 0;
	j = 0;
	sptr = 0;
	word = 0;
    sptr = (char **)malloc(sizeof(char *) * (get_word_count(str) + 1));
    if (hasword(str))
	{
		while (str[i] != '\0')
		{
			index = 0;
			while ((str[i] == 9 || str[i] == 10 || str[i] == 32) && str[i] != '\0')
				i++;
			if (str[i] != '\0')
			{
				word = (char *)malloc(sizeof(char) * (get_word_len(str, i) + 1));
				while (str[i] != 9 && str[i] != 10 && str[i] != 32 && str[i] != '\0')
				{
					word[index] = str[i];
					i++;
					index++;
				}
				word[index] = '\0';
				sptr[j] = word;
				j++;
			}
		}
	}
	sptr[j] = 0;
	return (sptr);
}
