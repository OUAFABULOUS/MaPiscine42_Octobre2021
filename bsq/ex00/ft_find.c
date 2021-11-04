/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <plefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:08:45 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/03 20:51:55 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h" 

int	calc_at(int ***tab, int *p, int *taille, int *max)
{
	int	t;
	int	y;
	int	x;

	x = p[0];
	y = p[1];
	free(p);
	t = 0;
	if (tab[y][x][0] == 0)
		return (0);
	while (t + x < taille[0] && t + y < taille[1]
		&& tab[y + t][x + t][0] > t && tab [y + t][x + t][1] > t)
		t++;
	if (t <= *max)
		return (0);
	*max = t;
	return (1);
}

int	*ft_to_tab(int best_x, int best_y, int max)
{
	int	*tab;

	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (0);
	tab[0] = best_x;
	tab[1] = best_y;
	tab[2] = max;
	return (tab);
}

int	*ft_to_tab_2(int x, int y)
{
	int	*tab;

	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (0);
	tab[0] = x;
	tab[1] = y;
	return (tab);
}

int	*ft_find(int ***tab, int *taille)
{
	int	x;
	int	y;
	int	max;
	int	best_x;
	int	best_y;

	best_x = -1;
	best_y = -1;
	max = -1;
	y = -1;
	while (++y < taille[1])
	{
		x = -1;
		while (++x < taille[0])
		{
			if (calc_at(tab, ft_to_tab_2(x, y), taille, &max))
			{
				best_x = x;
				best_y = y;
			}
		}
	}
	return (ft_to_tab(best_x, best_y, max));
}
