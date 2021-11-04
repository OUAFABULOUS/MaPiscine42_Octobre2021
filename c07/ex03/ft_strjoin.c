/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:57:57 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/29 00:42:39 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_ultimate_strcpy(char *res, char **strs, char *sep, int i)
{
	ft_strcpy(res, strs[i]);
	res += ft_strlen(strs[i]);
	ft_strcpy(res, sep);
	res += ft_strlen(sep);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*res;
	char	*res2;

	i = -1;
	len = 0;
	if (size == 0)
	{
		res2 = malloc(1);
		*res2 = '\0';
	}
	else
	{
		while (++i < size)
			len += ft_strlen(strs[i]);
		res = malloc((len + (ft_strlen(sep) * (size - 1)) + 1) * sizeof(char));
		res2 = res;
		i = -1;
		while (++i < size - 1)
			res = ft_ultimate_strcpy(res, strs, sep, i);
		res = ft_strcpy(res, strs[i]);
		*res = '\0';
	}
	return (res2);
}
