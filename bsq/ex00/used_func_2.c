/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:21:29 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 23:08:12 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_table(char **str)
{
	int	len_tab;

	len_tab = 0;
	while (str[len_tab])
		len_tab++;
	if (len_tab < 2)
		return (0);
	if (ft_strlen(str[0]) < 4 || ft_strlen(str[1]) < 1)
		return (0);
	return (1);
}
