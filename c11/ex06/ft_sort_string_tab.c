/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:30:10 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/04 22:08:09 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	**min;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		j = i + 1;
		if (tab[j])
			min = &tab[j];
		while (tab[j] && tab [j + 1])
		{
			if (ft_strcmp(tab[j + 1], *min) < 0)
				min = &tab[j + 1];
			j++;
		}
		if (ft_strcmp(tab[i], *min) > 0)
			ft_swap(min, &tab[i]);
		i++;
	}
}
