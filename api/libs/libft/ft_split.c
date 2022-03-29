/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:14:28 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/06 22:14:28 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_word_count(char const *s, char c)
{
	size_t	word_count;
	size_t	pos;

	word_count = 0;
	pos = 0;
	if (!s[0])
		return (0);
	while (s[pos] != '\0' && s[pos] == c)
		pos++;
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
		{
			word_count++;
			while (s[pos] != '\0' && s[pos] == c)
				pos++;
			continue ;
		}
		pos++;
	}
	if (s[pos - 1] != c)
		word_count++;
	return (word_count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*ft_save_word(char const *s, size_t len)
{
	size_t	pos;
	char	*word;

	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		word[pos] = s[pos];
		pos++;
	}
	return (word);
}

static void	*ft_clean_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	pos;
	char	**res;

	if (!s)
		return (NULL);
	word_count = ft_find_word_count(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	pos = 0;
	while (pos < word_count)
	{
		if (ft_word_len(s, c))
		{
			res[pos] = ft_save_word(s, ft_word_len(s, c));
			if (!res[pos++])
				return (ft_clean_res(res));
		}
		s += ft_word_len(s, c) + 1;
	}
	res[pos] = NULL;
	return (res);
}
