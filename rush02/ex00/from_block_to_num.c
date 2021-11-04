/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_block_to_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:38:55 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 23:34:05 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return(str1[i] - str2[i]);
}

int	ft_find_in_dict(char *str, char **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (!ft_strcmp(str, dict[i]))
		{
			if (dict[i + 1])
				return (i + 1);
		}
		i++;
	}
	return (-1);
}

void	ft_putstr(char *str)
{
	int i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_handle_2_digits(char *str, char **dict)
{
	int	a;
	int	b;

	if ((str[0] == '1') || (str[1] == '0'))
	{
		if (ft_find_in_dict(str, dict) >= 0)
			ft_putstr(dict[ft_find_in_dict(str, dict)]);
	}
	else
	{
		a = ft_find_in_dict((ft_itoa((ft_atoi(str) / 10) * 10)),dict); 
		if (str[0] != '0' && a >= 0)
		{	
			ft_putstr(dict[a]);
			ft_putstr(" ");
		}
		b =  ft_find_in_dict((ft_itoa(ft_atoi(str) % 10)),dict);
		if (str[1] && b >= 0)
			ft_putstr(dict[b]);
	}
}

void	ft_handle_1_digit(char *str, char **dict)
{
	int		i;

	i = ft_find_in_dict(str, dict);
	if (i)
		ft_putstr(dict[i]);
}
