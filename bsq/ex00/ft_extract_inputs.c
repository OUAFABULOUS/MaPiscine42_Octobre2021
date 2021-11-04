/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:58 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 18:44:55 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_extract_symb(char *str)
{
	int		len;
	char	*symbs;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 3;
	if (len < 4)
		return (NULL);
	symbs = malloc(4 * sizeof(char));
	if (!symbs)
		return (NULL);
	while (i < 3)
	{
		symbs[i] = str[len - j];
		i++;
		j--;
	}
	symbs[3] = 0;
	return (symbs);
}

int	ft_extract_len(char *str)
{
	int		res;
	int		len;
	int		i;

	res = 0;
	len = ft_strlen(str);
	i = 0;
	if (len < 4)
		return (0);
	while (i < len - 3 && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_extract_width(char *str)
{
	int	len;

	len = ft_strlen(str);
	return (len);
}

int	*ft_extract_dim(char **str)
{
	int	*res;

	res = malloc(2 * sizeof(int));
	if (!res)
		return (NULL);
	res[0] = ft_extract_width(str[1]);
	res[1] = ft_extract_len(str[0]);
	return (res);
}
