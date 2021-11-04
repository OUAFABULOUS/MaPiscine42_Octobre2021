/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:49:14 by omoudni           #+#    #+#             */
/*   Updated: 2021/10/31 23:23:43 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char			**ft_split(char *str, char *charset);
char			*ft_stock_dict(char *dict);
char			**create_table(char *str);
int				ft_strlen(char *str);
int				ft_tab_zise(char **tab);
int				ft_atoi(char *str);
char			*ft_concat(char *str, char c);
char			*ft_itoa(int i);
int				*tab_char_to_int(char **tab_char);
int				ft_strcmp(char *str1, char *str2);
int				ft_find_in_dict(char *str, char **dict);
void			ft_putstr(char *str);
void			ft_handle_2_digits(char *str, char **dict);
void			ft_handle_1_digit(char *str, char **dict);
int				ft_char_in_charset(char *str, char c);
int				ft_word_count(char *str, char *charset);
int				t_word_count(char *str, char *charset);
char			**ft_split(char *str, char *charset);
int				ceil_div_3(int i);
char			**ft_char_to_blocks(char *str);
void			ft_from_tab_to_str(char **str, char **dict, int size);
char			*ft_concat_2(char c, char *str);
int				ft_iterative_power(int nb, int power);
long long int	ft_atoi_2(char *str);

#endif
