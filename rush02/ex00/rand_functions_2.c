/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:24:20 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 19:47:14 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_concat_2(char c, char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc((ft_strlen(str) + 2) * sizeof(char));
	res[i] = c;
	i++;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	res = 1;
	i = power;
	while (i)
	{
		res *= nb;
		i--;
	}
	return (res);
}
