/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:18:55 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/16 00:00:51 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;
	int	d;

	c = *a;
	d = *b;
	*b = c;
	*a = d;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*min;

	i = 0;
	min = &tab[i];
	while (i < size)
	{
		j = i + 1;
		if (j < size)
			min = &tab[j];
		while (j < size - 1)
		{
			if (tab[j + 1] < *min)
			{
				min = &tab[j + 1];
			}
			j++;
		}
		if (tab[i] > *min)
		{
			ft_swap(min, &tab[i]);
		}
		i++;
	}
}
