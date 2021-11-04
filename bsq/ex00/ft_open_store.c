/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_store.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:03:35 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 19:53:48 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_count(char *argv)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		count++;
	close(fd);
	return (count);
}

char	*ft_open_store(char *argv)
{
	char	*f_stored;
	char	c;
	int		count;
	int		i;
	int		fd;

	i = 0;
	count = ft_count(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	f_stored = malloc(sizeof(char) * (count + 1));
	if (!f_stored)
		return (NULL);
	while (read(fd, &c, 1) > 0)
	{
		f_stored[i] = c;
		i++;
	}
	f_stored[i] = '\0';
	return (f_stored);
}

void	ft_strcat(char *dest, char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(dest + i))
		i++;
	while (*(src + j) && (j < n || n == -1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
}

int	ft_init_malloc(int s, char **ss)
{
	*ss = malloc(s);
	if (!*ss)
		return (0);
	**ss = 0;
	return (1);
}

char	*ft_get_stdin(void)
{
	char	*s;
	char	*ss;
	char	buf[1024];
	int		size;
	int		ret;

	ret = read(0, buf, 1024);
	if (!ft_init_malloc(1, &s))
		return (NULL);
	size = 0;
	while (ret)
	{	
		size += ret;
		ss = malloc(size + 1);
		if (!ft_init_malloc(size + 1, &ss))
			return (NULL);
		ft_strcat(ss, s, -1);
		ft_strcat(ss, buf, ret);
		free(s);
		s = ss;
		ret = read(0, buf, 1024);
	}
	return (s);
}
