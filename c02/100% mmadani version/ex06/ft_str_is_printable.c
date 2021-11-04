/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:15:41 by momadani          #+#    #+#             */
/*   Updated: 2021/10/17 19:46:16 by momadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(char c)
{
	return (c > 31 && c < 127);
}

int	ft_str_is_printable(char *str)
{
	while (ft_char_is_printable(*str))
		str++;
	return (!(*str));
}
