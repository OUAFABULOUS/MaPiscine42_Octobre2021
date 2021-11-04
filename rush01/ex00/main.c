/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:12:34 by dduchang          #+#    #+#             */
/*   Updated: 2021/10/24 23:32:07 by dduchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.io>

int	ft_error(void)
{
	write(1, "Error", 5);
	return (0);
}

void	ft_check_arg(char *argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (argv[i] && i <= 30)
	{
		if (!(argv[i] >= '1' && argv[i] <= '4' && argv[j] == ' '))
			ft_error;
		i + 2;
		j + 2;
	}
}

char	*ft_put_arg_in_tab(char *str)
{
        char    tab[17];

        tab[0] = str[0] - 48;
        tab[1] = str[2] - 48;
        tab[2] = str[4] - 48;
        tab[3] = str[6] - 48;
        tab[4] = str[8] - 48;
        tab[5] = str[10] - 48;
        tab[6] = str[12] - 48;
        tab[7] = str[14] - 48;
        tab[8] = str[16] - 48;
        tab[9] = str[18] - 48;
        tab[10] = str[20] - 48;
        tab[11] = str[22] - 48;
        tab[12] = str[24] - 48;
        tab[13] = str[26] - 48;
        tab[14] = str[28] - 48;
        tab[15] = str[30] - 48;
        tab[16] = '\0';
        return(tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		j++;
		ft_putchar(str[i]);
		i++;
		if (j != 16 && j != 4 && j != 8 && j != 12 && j != 16)
			ft_putchar(' ');
		if (j == 4 || j == 8 || j == 12 || j == 16)
			ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	char	*res;

	if (argc != 2)
		ft_error();
	ft_check_arg(argv[1]);
	res = ncomb(argv[1], 4);
	rush(argv[1]); 
	return (0);
}

