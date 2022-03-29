/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:13:19 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/04 23:13:19 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(char *digits, int fd)
{
	int	c;

	if (digits[0] == '-')
		ft_putchar_fd('-', fd);
	c = 10;
	while (c >= 0)
	{
		if (digits[c] != '\0' && digits[c] != '-')
			ft_putchar_fd(digits[c], fd);
		c--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		c;
	char	digits[11];

	c = 0;
	while (c <= 10)
	{
		if (n < 0)
		{
			if (c == 0)
				digits[c++] = '-';
			digits[c] = '0' + ((n % 10) * -1);
		}
		else if (n == 0 && c != 0)
			digits[c] = '\0';
		else
			digits[c] = '0' + n % 10;
		n /= 10;
		c++;
	}
	ft_print_nbr(digits, fd);
}
