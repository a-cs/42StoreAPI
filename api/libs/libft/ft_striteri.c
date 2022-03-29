/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:33:14 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/06 19:33:14 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	pos;

	if (!s || !f)
		return ;
	pos = 0;
	while (s[pos] != '\0')
	{
		f(pos, &s[pos]);
		pos++;
	}
}
