/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:49 by acarneir          #+#    #+#             */
/*   Updated: 2021/07/30 19:03:49 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if ((s1[pos] != s2[pos]) || (s1[pos] == '\0' || s2[pos] == '\0'))
		{
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
		}
		pos++;
	}
	return (0);
}
