/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:21:33 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/02 21:21:33 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	char_c;
	int				pos;

	str = (unsigned char *)s;
	char_c = (unsigned char)c;
	pos = 0;
	while (str[pos] != '\0')
	{
		pos++;
	}
	while (pos >= 0)
	{
		if (str[pos] == char_c)
		{
			return (((char *)str) + pos);
		}
		pos--;
	}
	return (NULL);
}
