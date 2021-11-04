/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:59:44 by klaurier          #+#    #+#             */
/*   Updated: 2021/10/24 22:27:59 by klaurier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	num_of_visible_rectangles(char *array_to_test)
{
	char	c;
	char	max;
	 int	j;

	c = '1';
	j = 0;
	max = '0';
	while (j < 4)
	{
		if (max < array_to_test[j])
			max = array_to_test[j];
		if (array_to_test[j] == '4')
			return (c);
		if (j < 3 && array_to_test[j + 1]
			> array_to_test[j] && array_to_test[j + 1] > max)
			c++;
		j++;
	}
	return (c);
}

char	*extract_grid(char *res)
{
	char	*input;
	 int	i;
	char	column_i[4];

	input = malloc((16 + 1) * sizeof(char));
	i = 0;
	while (i < 4)
	{
		column_i[0] = res[i];
		column_i[1] = res[i + 4];
		column_i[2] = res[i + 8];
		column_i[3] = res[i + 12];
		input[i] = num_of_visible_rectangles(column_i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		column_i[0] = res[i + 12];
		column_i[1] = res[i + 8];
		column_i[2] = res[i + 4];
		column_i[3] = res[i];
		input[i + 4] = num_of_visible_rectangles(column_i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		column_i[0] = res[0 + 4 * i];
		column_i[1] = res[1 + 4 * i];
		column_i[2] = res[2 + 4 * i];
		column_i[3] = res[3 + 4 * i];
		input[i + 8] = num_of_visible_rectangles(column_i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		column_i[0] = res[3 + 4 * i];
		column_i[1] = res[2 + 4 * i];
		column_i[2] = res[1 + 4 * i];
		column_i[3] = res[0 + 4 * i];
		input[i + 12] = num_of_visible_rectangles(column_i);
		i++;
	}
	input[16] = '\0';
	return (input);
}

int	compare_arrays(char *array_1, char *array_2)
{
	int	i;

	i = 0;
	while (i < 16 && array_1[i] && array_1[i] == array_2[i])
	{
		i++;
	}
	if (i == 16)
		return (1);
	return (0);
}

int	check_repetitive(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 16)
	{
		j = 0;
		c = str[i + j];
		while (i + j < 16)
		{
			if (j == 0)
				j += 4;
			if (c == str[i + j])
			{	
				return (0);
			}
			else
				j += 4;
		}
		i++;
	}
	i = 0;
	while (i < 16)
	{
		j = 0;
		c = str[i + j];
		while (j < 4 )
		{
			if (j == 0)
				j++;
			if (c == str[i + j])
			{
				return (0);
			}
			else
				j++;
		}
		i += 4;
	}
	return (1);
}

int	ft_check(char *matrix, char *input)
{
	char	*extracted_input;

	extracted_input = extract_grid(matrix);
	if (check_repetitive(matrix) && compare_arrays(extracted_input, input))
	{
		free(extracted_input);
		return (1);
	}
	free(extracted_input);
	return (0);
}
