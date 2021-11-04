/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:46:41 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/22 11:44:50 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	**min;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (j < size)
			min = &tab[j];
		while (j < size - 1)
		{
			if (ft_strcmp(tab[j + 1],*min) < 0)
			{
				min = &tab[j + 1];
			}
			j++;
		}
		if (ft_strcmp(tab[i],*min) > 0)
		{
			ft_swap(min, &tab[i]);
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		argv++;
		ft_sort_tab(argv, argc - 1);
		i = 0;
		while (i < argc - 1)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
