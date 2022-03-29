/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:07:55 by acarneir          #+#    #+#             */
/*   Updated: 2021/07/30 21:07:55 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	char_c;

	str = (unsigned char *) s;
	char_c = (unsigned char) c;
	while (*str != '\0')
	{
		if (*str == char_c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (char_c == '\0')
		return ((char *)str);
	return (NULL);
}
