/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <plefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:47:30 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/03 22:15:30 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_tab(int ***tab, int *t, char *c, int *s)
{
	int	x;
	int	y;

	y = -1;
	while (++y < t[1])
	{
		x = -1;
		while (++x < t[0])
		{
			if (!tab[y][x][0])
				write(1, c + 1, 1);
			else
			{
				if (x >= s[0] && x < s[0] + s[2]
					&& y >= s[1] && y < s[1] + s[2])
					ft_ultimate_putstr(c);
				else
					write(1, c, 1);
			}
		}
		write(1, "\n", 1);
	}
	free(c);
}

void	ft_print_tab_advanced(int ***tab, int *t)
{
	int	x;
	int	y;
	int	k;

	y = -1;
	while (++y < t[1])
	{
		k = -1;
		while (++k < 2)
		{
			x = -1;
			while (++x < t[0])
			{
				if (!tab[y][x][0])
					ft_putstr("\033[31m");
				ft_putnbr(tab[y][x][k]);
				ft_putstr("\033[0m");
				write(1, "  ", 2);
			}
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
	}
}

int	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}
