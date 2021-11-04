/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:35 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/13 23:20:39 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	k;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		k = nb % 10;
		nb /= 10;
		ft_putnbr(nb);
		ft_putchar(k + '0');
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 < 100)
	{
		n2 = n1 + 1;
		while (n2 < 100)
		{
			if (n1 < 10 )
				ft_putnbr(0);
			ft_putnbr(n1);
			ft_putchar(' ');
			if (n2 < 10)
				ft_putnbr(0);
			ft_putnbr(n2);
			if (n1 != 98)
			{
				write(1, ", ", 2);
			}
			n2++;
		}
		n1++;
	}
}
