/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:25 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/03 22:28:30 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		***ft_convert(char **tab_str, int nb_lignes, char *s);
char	**ft_split(char *str, char *charset);
char	*ft_open_store(char *argv);
char	*ft_extract_symb(char *str);
char	*ft_get_stdin(void);
int		*ft_extract_dim(char **str);
int		*ft_find(int ***tab, int *taille);
int		ft_strlen(char *str);
int		ft_print_error(char *str);
void	ft_print_tab(int ***tab, int *t, char *c, int *s);
void	ft_print_tab_advanced(int ***tab, int *t);
void	ft_putstr_fd(char *c, int fd);
void	ft_putstr(char *c);
void	ft_ultimate_putstr(char *c);
void	ft_putnbr(int nb);
void	ft_free_int_3(int ***n, int t1, int t2);
void	ft_free_int_2(int **n, int t1);
void	ft_free_char_2(char **n, int t1);
int		ft_check_table(char **str);

#endif
