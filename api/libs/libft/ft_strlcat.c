/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:42:05 by acarneir          #+#    #+#             */
/*   Updated: 2021/07/30 18:42:05 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*dst != '\0' && len < size)
	{
		dst++;
		len++;
	}
	while (*src != '\0' && len + 1 < size)
	{
		*dst = *src;
		dst++;
		src++;
		len++;
	}
	if (len < size)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		len++;
	}
	return (len);
}
