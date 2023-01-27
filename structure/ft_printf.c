/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:22:19 by gbump             #+#    #+#             */
/*   Updated: 2021/01/11 18:25:55 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

t_flag		input_flags(void)
{
	t_flag flag;

	flag.zero = 0;
	flag.minus = 0;
	flag.star = 0;
	flag.dot = -1;
	flag.type = 0;
	flag.width = 0;
	return (flag);
}

int			readstr(const char *s, va_list a)
{
	int			i;
	int			done;
	t_flag		flag;
	int			mistake;

	done = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
			done += ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			flag = input_flags();
			i++;
			i = read_flags(s, i, &flag, a);
			if ((ft_type(s[i])) == 1)
			{
				if ((mistake = ft_setupper((char)flag.type, flag, a)) == -1)
					return (-1);
				done += mistake;
			}
		}
	}
	return (done);
}

int			read_flags(const char *s, int i, t_flag *flag, va_list a)
{
	while (s[i])
	{
		if ((s[i] != '.') && (s[i] != '*') && (s[i] != '0') && (s[i] != '-')
		&& (!ft_type(s[i])) && (!ft_isdigit(s[i])))
			break ;
		if (s[i] == '-' && flag->width == 0 && flag->zero == 0)
			flag->minus = 1;
		if (s[i] == '0' && flag->width == 0 && flag->minus == 0
		&& s[i + 1] != '-' && s[i - 1] != '-')
			flag->zero = 1;
		if (s[i] == '.')
			i = ft_dot(s, i, flag, a);
		if (s[i] == '*')
			*flag = ft_width_star(a, *flag);
		if (ft_isdigit(s[i]))
			*flag = ft_width_number(*flag, s[i]);
		if (ft_type(s[i]))
		{
			flag->type = s[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		a;
	int			done;

	done = 0;
	if (format == NULL)
		return (-1);
	va_start(a, format);
	done += readstr(format, a);
	va_end(a);
	return (done);
}
