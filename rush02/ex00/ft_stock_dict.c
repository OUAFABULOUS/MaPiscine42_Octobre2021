/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_store_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:52:13 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 14:18:51 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_stock_dict(char *dict)
{

	int		fd;
	char	*buf;

	fd = open(dict, O_RDONLY);
	buf = malloc(1000000);
	read(fd, buf, 1000000);
	close (fd);
	return (buf);
}
