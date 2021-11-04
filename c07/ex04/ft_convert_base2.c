/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:14:55 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/28 17:33:38 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);
int	ft_verif_base(char *base);

char	*ft_concat(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((ft_strlen(str) + 2));
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = c;
	i++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_putnbr_base(char *res, unsigned int nbr, char *base)
{
	unsigned int	len;
	char			*res2;
	char			*res1;

	if (ft_verif_base(base))
	{
		len = ft_strlen(base);
		if (nbr < len)
		{
			res2 = ft_concat(res, base[nbr]);
		}	
		else
		{
			res1 = ft_putnbr_base(res, nbr / len, base);
			res2 = ft_concat(res1, base[nbr % len]);
		}
		return (res2);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_old_base;
	char	*nbr_new_base;

	nbr_old_base = ft_atoi_base(nbr, base_from);
	if (nbr_old_base < 0)
		nbr_new_base = ft_putnbr_base("-", -nbr_old_base, base_to);
	else
		nbr_new_base = ft_putnbr_base("", nbr_old_base, base_to);
	return (nbr_new_base);
}
