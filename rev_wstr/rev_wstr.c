/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 17:51:35 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/16 18:44:23 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	get_max_len(char *s)
{
	int i;
	int end;
	int start;
	int max_len;

	i = 0;
	end = 0;
	start = 0;
	max_len = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == 9 || s[i] == 32 ) && s[i] != '\0')
			i++;
		start = i;
		while ((s[i] != 9 && s[i] != 32 ) && s[i] != '\0')
		{
			i++;
			end = i;
		}
		if ((end - start) > max_len)
			max_len = end - start;
	}
	return (max_len);
}

int	get_word_count(char *s)
{
	int i;
	int word_count;
	
	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == 9 || s[i] == 32 ) && s[i] != '\0')
			i++;
		if ((s[i] != 9 && s[i] != 32 ) && s[i] != '\0')
			word_count++;
		while ((s[i] != 9 && s[i] != 32 ) && s[i] != '\0')
		i++;
	}
	return (word_count);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int index;
	char *word;
	char **s;

	i = 0;
	j = 0;
	s = (char **)malloc(sizeof(char *) * (get_word_count(str) + 1));
	while (str[i] != '\0')
	{
		index = 0;
		while ((str[i] == 9 || str[i] == 32 ) && str[i] != '\0')
			i++;
		word = (char *)malloc(sizeof (char ) * (get_max_len(str) + 1));
		while (str[i] != 9 && str[i] != 32 && str[i] != '\0')
		{
			word[index] = str[i];
			i++;
			index++;
		}
		word[index] = '\0';
		s[j] = word;
		j++;
	}
	s[j] = 0;
	return (s);
}

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	rev_wstr(char *s)
{
	int size;
	char **ptr;

	size = get_word_count(s);
	ptr = ft_split(s);
	while (size > 1)
	{
		write(1, ptr[size - 1], ft_strlen(ptr[size - 1]));
		write(1, " ", 1);
		size--;
	}
	write(1, ptr[size - 1], ft_strlen(ptr[size - 1]));
	size = 0;
	while (ptr[size] != '\0')
	{
		free(ptr[size]);
		size++;
	}
	free(ptr);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
}
