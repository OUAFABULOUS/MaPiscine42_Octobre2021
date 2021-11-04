/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:46:19 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 23:27:28 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_tab_zise(char **tab)
{
	int	i;

	i = 0;
	while (tab[i][0])
		i++;
	return(i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

char	*ft_concat(char *str, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc((ft_strlen(str) + 2) * sizeof(char));
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int i)
{
	char	*res;
	char	*res_int;

	if (i < 10)
		res = ft_concat("", (i + 48));
	else
	{
		res_int = ft_itoa(i / 10);
		res = ft_concat(res_int, ((i % 10) + 48));
	}
	return (res);
}

int	*tab_char_to_int(char **tab_char)
{
	int		*tab_int;
	int		i;

	tab_int = malloc((ft_tab_zise(tab_char) + 1) * sizeof(int));
	i = 0;
	while (tab_char[i])
	{
		tab_int[i] = ft_atoi(tab_char[i]);
		i++;
	}
	tab_int[i] = '\0';
	return (tab_int);
}
