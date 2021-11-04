/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:43:04 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/28 18:43:06 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base [i] == '-' || base[i] == '\r'
			|| base[i] == '\f' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\n' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_c_in_base(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	ft_base_to_int(char nb, char *base)
{
	int	i;

	i = 0;
	while (base[i] != nb)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	i;

	if (!ft_verif_base(base))
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\r' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_c_in_base(str[i], base))
	{
		res = res * ft_strlen(base) + ft_base_to_int(str[i], base);
		i++;
	}
	return (res * sign);
}
