/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:15:25 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/18 19:59:26 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char*s2, unsigned int n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*s1 - *s2);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		len;

	len = ft_strlen(to_find);
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find && !ft_strncmp(str, to_find, len))
			return (str);
		str++;
	}
	return (NULL);
}
