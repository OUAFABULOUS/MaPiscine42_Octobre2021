/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:37:36 by momadani          #+#    #+#             */
/*   Updated: 2021/11/04 19:50:58 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	if ((c / 16) <= 9)
		ft_putchar((c / 16) + '0');
	else
		ft_putchar((c / 16) - 10 + 'a');
	if ((c % 16) <= 9)
		ft_putchar((c % 16) + '0');
	else
		ft_putchar((c % 16) - 10 + 'a');
}

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_char_is_printable(str[i])))
		{
			ft_putchar('\\');
			ft_puthex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
