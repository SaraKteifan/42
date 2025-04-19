/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:56 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 13:58:09 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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

int		ft_printf(const char *s, ...);
int		in_set(const char *set, char c);
int		put_char(char c);
int		put_str(char *s);
int		put_ptr(void *ptr);
int		put_num(long int n);
int		put_unum(unsigned int n);
int		put_lhex(unsigned int n);
int		put_uhex(unsigned int n);
t_flags	*flags_set(char *s);
int		check_flags_exist(t_flags	*flags);
int		handle_flags(va_list ap, t_flags *flags, char c);
int		get_min_width(char *flags);
int		get_precision(char *flags);
int		get_zero(char *s);
int		handle_zero_flag(t_flags *flags, int len);
int		strlength(char	*s);
int		count_num(long long n);
int		count_hex(unsigned long long n);
int		which_is_bigger(int i, int j);
int		put_char_flags(char c, t_flags *flags);
int		put_str_flags(char *s, t_flags *flags);
int		put_ptr_flags(void *ptr, t_flags *flags);
int		put_num_flags(long int n, t_flags *flags);
int		put_unum_flags(unsigned int n, t_flags *flags);
int		put_lhex_flags(unsigned int n, t_flags *flags);
int		put_uhex_flags(unsigned int n, t_flags *flags);

#endif
