/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:42:06 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 23:28:55 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h" 

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_char_in_charset(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	sep;
	int	word_count;

	i = 0;
	sep = 1;
	word_count = 0;
	while (str[i])
	{
		if (ft_char_in_charset(charset, str[i]))
			sep = 1;
		if (sep == 1 && !ft_char_in_charset(charset, str[i]))
		{
			word_count += 1;
			sep = 0;
		}
		i++;
	}
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		word_count;
	char	**tab;

	i = 0;
	j = 0;
	k = -1;
	word_count = ft_word_count(str, charset);
	tab = malloc ((word_count + 1) * sizeof(char *));
	while (++k < word_count)
	{
		while (str[i] && ft_char_in_charset(charset, str[i]))
			i++;
		j = i;
		while (str[i] && !ft_char_in_charset(charset, str[i]))
			i++;
		tab[k] = malloc ((i - j + 1) * sizeof(char));
		ft_strncpy(tab[k], str + j, i - j + 1);
	}
	if (word_count > 1 && !ft_strlen(tab[1]))
		return (NULL);
	tab[k] = 0;
	return (tab);
}
