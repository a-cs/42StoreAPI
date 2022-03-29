/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:03:11 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/04 23:03:11 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	if (s)
	{
		pos = 0;
		while (s[pos] != '\0')
		{
			ft_putchar_fd(s[pos], fd);
			pos++;
		}
	}
}
