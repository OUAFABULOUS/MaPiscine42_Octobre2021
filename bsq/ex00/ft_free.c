/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <plefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:31:41 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/03 21:12:35 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_int_3(int ***n, int t1, int t2)
{
	int	i;

	i = 0;
	while (i < t1)
	{
		ft_free_int_2(n[i], t2);
		i++;
	}
	free(n);
}

void	ft_free_int_2(int **n, int t1)
{
	int	i;

	i = 0;
	while (i < t1)
	{
		free(n[i]);
		i++;
	}
	free(n);
}

void	ft_free_char_2(char **n, int t1)
{
	int	i;

	i = 0;
	while (i < t1 + 1)
	{
		free(n[i]);
		i++;
	}
	free(n);
}
