/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <plefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:18:29 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/03 21:44:03 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	**ft_convert_line(char *line, int l, char *s)
{
	int	i;
	int	**t;
	int	lo;
	int	*tab;

	lo = -1;
	t = malloc(l * sizeof(int *));
	if (!t || !line)
		return (0);
	i = -1;
	while (++i < l)
	{
		tab = malloc(2 * sizeof(int));
		if (!tab || (s[0] != line[i] && s[1] != line[i]))
			return (0);
		if (*(line + i) == *(s + 1))
			lo = i;
		if (!*(line + i))
			return (0);
		tab[1] = i - lo;
		t[i] = tab;
	}
	if (*(line + l))
		return (0);
	return (t);
}

void	ft_calc_y(int ***tab, int ty, int tx)
{
	int	x;
	int	y;
	int	lo;

	x = 0;
	while (x < tx)
	{
		lo = -1;
		y = 0;
		while (y < ty)
		{
			if (tab[y][x][1] == 0)
				lo = y;
			tab[y][x][0] = y - lo;
			y++;
		}
		x++;
	}
}

int	ft_check_char(char *s)
{
	if (ft_strlen(s) != 3 || *s == *(s + 1)
		|| *s == *(s + 2) || *(s + 1) == *(s + 2))
	{
		free(s);
		return (0);
	}
	return (1);
}

int	***ft_convert(char **tab_str, int nb_lignes, char *s)
{
	int	***tab;
	int	i;
	int	l;

	if (!ft_check_char(s))
		return (0);
	l = ft_strlen(*tab_str);
	tab = malloc(nb_lignes * sizeof(int **));
	if (!tab)
		return (0);
	i = 0;
	while (i < nb_lignes)
	{
		tab[i] = ft_convert_line(*(tab_str + i), l, s);
		if (!tab[i])
			return (0);
		i++;
	}
	free(s);
	ft_calc_y(tab, nb_lignes, l);
	return (tab);
}
