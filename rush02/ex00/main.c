/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:17:55 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 23:26:49 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	**dict; 
	char	**tab_input;

	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
		{
			dict_file = ft_stock_dict("./numbers.dict");
			if (ft_atoi_2(argv[1]) >= 0)
				tab_input = ft_char_to_blocks(ft_itoa(ft_atoi(argv[1])));
			else
				write(1, "Error\n", 6);
		}
		if (argc == 3)
		{
			dict_file = ft_stock_dict(argv[1]);
			if (ft_atoi_2(argv[2]) >= 0)
				tab_input = ft_char_to_blocks(ft_itoa(ft_atoi(argv[2])));
			else
				write (1, "Error\n", 6);
		}
		dict = create_table(dict_file);
		ft_from_tab_to_str(tab_input, dict, ft_tab_zise(tab_input));
	}
	return (0);
}
