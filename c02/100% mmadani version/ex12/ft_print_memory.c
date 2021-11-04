/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:47:55 by momadani          #+#    #+#             */
/*   Updated: 2021/11/04 20:09:52 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEX_BASE "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char octet)
{
	ft_putchar(HEX_BASE[octet / 16]);
	ft_putchar(HEX_BASE[octet % 16]);
}

void	ft_putaddr(void *addr)
{
	int	i;

	i = 64;
	while (i > 0)
	{
		i -= 8;
		ft_puthex(((unsigned long int)(addr) >> i) & 0xff);
	}
}

void	ft_putdata(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (!(i % 2))
			ft_putchar(32);
		if (i < size)
			ft_puthex(str[i]);
		else
			write(1, "  ", 2);
		i++;
	}
	ft_putchar(32);
	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putaddr((addr + i));
		ft_putchar(':');
		ft_putdata((char *)(addr + i), (size - i));
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

int	main(void)
{
	char *str;

	str = "Bonjour bonsoir peti test";
	ft_print_memory(str, 150);
}
