/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:56 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/01 12:52:50 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	int	min;
	int	precision;
	int	left;
	int	zero;
	int	form;
	int	space;
	int	plus;
}	t_flags;


# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	in_set(const char *set, char c);
int	put_char(char c);
int	put_str(char *s);
int	put_ptr(void *ptr);
int	put_num(long int n);
int	put_unum(unsigned int n);
int	put_lhex(unsigned int n);
int	put_uhex(unsigned int n);

#endif
