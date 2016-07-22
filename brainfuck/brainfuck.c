/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 17:21:19 by emsimang          #+#    #+#             */
/*   Updated: 2016/07/22 17:37:02 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brain(char *str)
{
	int size;
	int bracket;
	char *ptr;

	size = 2047;
	ptr = (char *)malloc(sizeof(char *) * 2048);
	while (size >= 0)
		ptr[size--] = 0;
	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '>')
			ptr++;
		else if (str[size] == '<')
			ptr--;
		else if (str[size] == '+')
			(*ptr)++;
		else if (str[size] == '-')
			(*ptr)--;
		else if (str[size] == '.')
			write(1, ptr, 1);
		else if (str[size] == '[')
		{
			if (*ptr == 0)
			{
				bracket = 0;
				while (str[size])
				{
					if (str[size] == '[')
						bracket++;
					if (str[size] == ']')
						bracket--;
					if (bracket == 0)
						break ;
					size++;
				}
			}
		}
		else if (str[size] == ']')
		{
			if (*ptr != 0)
			{
				bracket = 0;
				while (str[size])
				{
					if (str[size] == '[')
						bracket--;
					if (str[size] == ']')
						bracket++;
					if (bracket == 0)
						break ;
					size--;
				}
			}
		}
		size++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		brain(argv[1]);
	else
		write(1, "\n", 1);
}
