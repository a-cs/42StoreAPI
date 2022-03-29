/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:43:26 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/04 21:43:26 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		pos1;
	int		pos2;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	pos1 = 0;
	pos2 = 0;
	while (s1[pos1] != '\0')
	{
		str[pos1] = s1[pos1];
		pos1++;
	}
	while (s2[pos2] != '\0')
	{
		str[pos1 + pos2] = s2[pos2];
		pos2++;
	}
	return (str);
}
