/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:03:20 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/04 20:55:47 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sum(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_div(int a, int b)
{
	if (b)
		ft_putnbr(a / b);
	else
		ft_putstr("Stop: division par zero");
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(int a, int b)
{
	if (b)
		ft_putnbr(a % b);
	else
		ft_putstr("Stop: modulo by zero");
}
