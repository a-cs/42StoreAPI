/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 22:02:31 by acarneir          #+#    #+#             */
/*   Updated: 2021/07/29 22:02:31 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	pos;

	if (!dst || !src)
		return (0);
	pos = 0;
	if (size > 0)
	{
		while (pos < (size - 1) && src[pos])
		{
			dst[pos] = src[pos];
			pos++;
		}
		dst[pos] = '\0';
	}
	pos = 0;
	while (src[pos] != '\0')
		pos++;
	return (pos);
}
