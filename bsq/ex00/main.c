/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:50:22 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 23:22:04 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_do_map(char	**tab, int new_line)
{
	int	*taille;
	int	***tab_2;
	int	*solution;

	if (!tab || !ft_check_table(tab))
		return (ft_print_error("map error\n"));
	taille = ft_extract_dim(tab);
	tab_2 = ft_convert(tab + 1, taille[1], ft_extract_symb(tab[0]));
	if (!tab_2)
		return (ft_print_error("map error\n"));
	solution = ft_find(tab_2, taille);
	ft_print_tab(tab_2, taille, ft_extract_symb(tab[0]), solution);
	ft_free_int_3(tab_2, taille[1], taille[0]);
	ft_free_char_2(tab, taille[1] + 1);
	free(solution);
	free(taille);
	if (new_line)
		ft_putstr("\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tab;
	char	*file_content;

	i = 1;
	if (argc == 1)
	{
		tab = ft_split(ft_get_stdin(), "\n");
		ft_do_map(tab, 0);
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			file_content = ft_open_store(argv[i++]);
			if (!file_content)
				return (-1);
			tab = ft_split(file_content, "\n");
			free(file_content);
			ft_do_map(tab, i < argc);
		}
	}
	return (0);
}
