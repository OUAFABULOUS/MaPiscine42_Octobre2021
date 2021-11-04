/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:47:00 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/23 12:41:35 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
