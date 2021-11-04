/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:48:05 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 18:52:46 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ceil_div_3(int i)
{
int	res;

res = (i + 3 - 1) /3;
return (res);
}

char	*ft_strncpy_1(char *dest, char *src,int n)
{
	int	i;

	i = 0;
	while (src[i] && n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}


char	**ft_char_to_blocks(char *str)
{
	int		len;
	char	**res;
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (len <= 3)
	{
		res = malloc(2 * sizeof(char*));
		res[j] = malloc((len + 1) * sizeof(char));
		res[j] = ft_strncpy_1(res[j], str, len);
		j++;
	}
	else
	{
		k = ceil_div_3(len);
		res = malloc((k + 1) * sizeof(char*));
		if ((len % 3))
		{
			res[j] = malloc(((len % 3) + 1) * sizeof(char));
			res[j] = ft_strncpy_1(res[j], str, (len % 3));
			j++;
			i += len % 3;
		}
		while (str[i] && (j < k))
		{
			res[j] = malloc(4 * sizeof(char));
			res[j] = ft_strncpy_1(res[j], (str + i), 3); 
			i += 3;
			j++;
		}
	}
	res[j] = malloc(1);
	res[j][0] = '\0';
	return (res);
}

