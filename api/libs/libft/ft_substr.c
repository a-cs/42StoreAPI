/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:52:49 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/04 20:52:49 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	count;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		count = 1;
	else if (ft_strlen(s) > (start + len))
		count = len + 1;
	else
		count = ft_strlen(s) - start + 1;
	substr = (char *)ft_calloc(count, sizeof(char));
	if (!substr)
		return (NULL);
	if (count > 1)
	{
		count = 0;
		while (s[start + count] != '\0' && count < len)
		{
			substr[count] = s[start + count];
			count++;
		}
	}
	return (substr);
}
