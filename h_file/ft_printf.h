/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:55:07 by gbump             #+#    #+#             */
/*   Updated: 2021/01/12 20:50:53 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flag
{
	int		zero;
	int		minus;
	int		star;
	int		dot;
	int		type;
	int		width;
}					t_flag;

t_flag				input_flags(void);
int					readstr(const char *s, va_list a);
int					read_flags(const char *s, int i, t_flag *flag, va_list a);
int					ft_printf(const char *format, ...);
int					ft_putchar(int c);
int					ft_isdigit(int c);
t_flag				ft_width_number(t_flag flag, char a);
t_flag				ft_width_star(va_list a, t_flag flag);
int					ft_type(char a);
int					ft_dot(const char *s, int i, t_flag *flag, va_list a);
int					ft_setupper(int c, t_flag flag, va_list a);
int					ft_print_di(int a, t_flag flag);
char				*ft_itoa(long int n);
int					ft_strlen(char *str);
int					ft_flagminus(int i, char *itoa, int str, t_flag flag);
int					ft_flagnotminus(t_flag flag, int j, char *itoa, int str);
int					dotadder(int j, int count, t_flag flag);
int					checknumber(char *itoa, t_flag flag);
int					ft_print_u(unsigned int a, t_flag flag);
int					ft_print_c(char a, t_flag flag);
int					ft_print_s(char *a, t_flag flag);
int					ft_print_x(unsigned int a, t_flag flag);
char				ft_translator(unsigned int a, char itoa, t_flag flag);
int					ft_print_p(unsigned long long a, t_flag flag);
int					ft_print_percent(t_flag flag);
int					addersmth(int len, t_flag flag);
int					icounter(t_flag flag, int j);
int					numberchanger(t_flag flag, int j, char *itoa, int str);
#endif
