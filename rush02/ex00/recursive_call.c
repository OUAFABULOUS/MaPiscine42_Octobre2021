/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:57:27 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 23:33:12 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
void	ft_from_tab_to_str(char **str, char **dict, int size)
{
	int	i;
	int	power;

	i = 0;
	if (ft_strlen(str[i]) == 2)
	{
		ft_handle_2_digits(str[i], dict);
		power = ft_iterative_power(1000, size -1);
		if (power > 1)
		{
			ft_putstr(" ");
			ft_putstr(dict[ft_find_in_dict(ft_itoa(power), dict)]);
			printf(" ");
		}
		if (size > 1)
			ft_putstr(" ");
		i ++;
		size--;
	}
	if (str[i] && ft_strlen(str[i]) == 1)
	{
		ft_handle_1_digit(str[i], dict);
		power = ft_iterative_power(1000, size - 1);
		if (power > 1)
		{
			ft_putstr(" ");
			ft_putstr(dict[ft_find_in_dict(ft_itoa(power), dict)]);
		}
		if (size > 1)
			ft_putstr(" ");
		i++;
		size--;
	}
	while (str[i] && size)
	{
		if (str[i][0] != '0')
		{
			char d1[2];
			d1[0] = str[i][0];
			d1[1] = '\0';
			ft_handle_1_digit(d1, dict);
			ft_putstr(" hundred");
			ft_putstr(" ");
		}
		if ((str[i][1] != '0' || str[i][2] != '0'))
		{
			char	d2[3];
			d2[0] = str[i][1];
			d2[1] = str[i][2];
			d2[2] = 0;
			ft_handle_2_digits(d2, dict);
		}	
		power = ft_iterative_power(1000, size - 1);
		if (power > 1 && (str[i][0] != '0'|| str[i][1] != '0'|| str[i][2] != '0'))
		{
			ft_putstr(" ");
			ft_putstr(dict[ft_find_in_dict(ft_itoa(power), dict)]);
		}
		if (size > 1)
			ft_putstr(" ");
		size--;
		i++;
	}
		write(1, "\n", 1);
}
