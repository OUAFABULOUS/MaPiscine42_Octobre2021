/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:52:57 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/04 22:09:50 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_op	ft_get_op(char *str)
{
	if (!*str || ft_strlen(str) != 1)
		return (op_null);
	if (*str == '+')
		return (op_sum);
	if (*str == '-')
		return (op_sub);
	if (*str == '/')
		return (op_div);
	if (*str == '*')
		return (op_mul);
	if (*str == '%')
		return (op_mod);
	return (op_null);
}

int	main(int argc, char **argv)
{
	void	(*ft_calc[5])(int, int);
	t_op	op;

	ft_calc[op_sum] = &ft_sum;
	ft_calc[op_sub] = &ft_sub;
	ft_calc[op_div] = &ft_div;
	ft_calc[op_mul] = &ft_mul;
	ft_calc[op_mod] = &ft_mod;
	if (argc == 4)
	{
		op = ft_get_op(argv[2]);
		if (op == op_null)
			ft_putnbr(0);
		else
			ft_calc[op](ft_atoi(argv[1]), ft_atoi(argv[3]));
		ft_putchar('\n');
	}
	return (0);
}
