/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:09:19 by momadani          #+#    #+#             */
/*   Updated: 2021/10/18 14:57:04 by momadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_wdlowcase(char *str)
{
	while (*str && ft_char_is_alphanumeric(*str))
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (ft_char_is_alphanumeric(*tmp))
		{
			if (*tmp >= 'a' && *tmp <= 'z')
				*tmp -= 32;
			tmp = ft_wdlowcase(++tmp);
		}
		else
			tmp++;
	}
	return (str);
}
