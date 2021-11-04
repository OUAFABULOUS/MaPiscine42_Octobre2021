/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:36:54 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/20 22:33:24 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_sign(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (1);
		str++;
	}
	return (0);
}

int	ft_verif_base(char *str)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	if (len < 2 || ft_is_sign(str))
		return (0);
	while (str[i] && i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	out;
	unsigned int	len;

	if (ft_verif_base(base))
	{
		len = ft_strlen(base);
		if (nbr < 0)
		{
			out = -nbr;
			ft_putchar('-');
		}
		else
			out = nbr;
		if (out < len)
			ft_putchar(base[out]);
		else
		{
			ft_putnbr_base(out / len, base);
			ft_putchar(base[out % len]);
		}
	}
}
