/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:06:50 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/24 23:37:41 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char *matrix, char *input);
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*concat(char *str1, char *str2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*n_comb(char *argv, char *str1, int level)
{
	char	*res;
	char	*lines[24];
	char	*conc_str;
	 int	j;

	lines = {"1234", "1243", "1324", "1342", "1432", "1423", "2134", "2143",
	"2314", "2341", "2413", "2431", "3124", "3142", "3214", "3241", "3412",
		"3421", "4123", "4132", "4213", "4231", "4312", "4321"};
	j = -1;
	if (level == 0)
		if (ft_check(str1, argv))
			return (str1);
	while (++j < 24)
	{
		conc_str = concat(str1, lines[j]);
		res = n_comb(argv, conc_str, level - 1);
		if (res)
		{
			return (res);
		}
		free(conc_str);
	}
	return (NULL);
}
