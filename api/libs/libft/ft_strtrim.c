/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:33:06 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/06 20:33:06 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char const *set)
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

static int	ft_find_len(char const *s1, char const *set)
{
	int	pos;
	int	len;

	len = ft_strlen(s1) - 1;
	pos = 0;
	while (set[pos])
	{
		while (s1[len] == set[pos] && len >= 0)
		{
			len--;
			pos = 0;
			continue ;
		}
		pos++;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		start;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	len = ft_find_len(s1 + start, set);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + start, len);
	return (str);
}
