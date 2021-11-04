/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:12:52 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/20 15:25:46 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;
	unsigned int	src_index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	offset = d_len;
	src_index = 0;
	if (size > d_len)
	{
		while (*(src + src_index) && offset < (size - 1))
		{
			*(dest + offset) = *(src + src_index);
			offset++;
			src_index++;
		}
		*(dest + offset) = '\0';
		return (d_len + s_len);
	}
	else
		return (size + s_len);
}
