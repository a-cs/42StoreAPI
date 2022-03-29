/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:33:35 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/02 23:33:35 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char *set)
{
	int	pos;
	int	start;

	start = 0;
	pos = 0;
	while (set[pos] != '\0')
	{
		if (s1[start] == set[pos])
		{
			start++;
			pos = 0;
		}
		else
			pos++;
	}
	return (start);
}

int	ft_atoi(const char *str)
{
	int	signal;
	int	number;

	str += ft_find_start(str, " 	\t\n\r\v\f");
	signal = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	number = 0;
	while ((ft_isdigit(*str)))
	{
		number *= 10;
		number += signal * (*str - '0');
		str++;
	}
	return (number);
}
