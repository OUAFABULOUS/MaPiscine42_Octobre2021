/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:28:08 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/04 01:44:45 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	d1;
	int	d2;

	i = 1;
	if (length < 3)
		return (1);
	while (i < length && !f(tab[i - 1], tab[i]))
		i++;
	if (i < length)
	{
		d1 = f(tab[i - 1], tab[i]);
		i++;
	}
	while (i < length)
	{
		d2 = f(tab[i - 1], tab[i]);
		if ((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0))
			return (0);
		i++;
	}
	return (1);
}
