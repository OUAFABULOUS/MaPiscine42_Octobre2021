/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:30 by omoudni           #+#    #+#             */
/*   Updated: 2021/11/04 21:00:23 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

typedef enum s_op
{
	op_sum,
	op_sub,
	op_div,
	op_mul,
	op_mod,
	op_null,
}		t_op;

void	ft_sum(int a, int b);
void	ft_sub(int a, int b);
void	ft_div(int a, int b);
void	ft_mul(int a, int b);
void	ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif
