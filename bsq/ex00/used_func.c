/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:55:27 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 23:00:36 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	while (*(c + i))
	{
		write (fd, c + i, 1);
		i++;
	}
}

void	ft_putstr(char *c)
{
	ft_putstr_fd(c, 1);
}

void	ft_ultimate_putstr(char *c)
{
	write(1, c + 2, 1);
}

void	ft_putnbr(int nb)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = (nb / 100 % 10) + '0';
	c2 = (nb / 10) % 10 + '0';
	c3 = nb % 10 + '0';
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
