/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:03:52 by gbump             #+#    #+#             */
/*   Updated: 2021/01/12 19:27:31 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int				ft_setupper(int c, t_flag flag, va_list a)
{
	int done;

	done = 0;
	if (c == 'd' || c == 'i')
		done += ft_print_di(va_arg(a, int), flag);
	else if (c == 'u')
		done += ft_print_u(va_arg(a, unsigned int), flag);
	if (c == 'c')
		done += ft_print_c(va_arg(a, int), flag);
	else if (c == 's')
		done += ft_print_s(va_arg(a, char *), flag);
	else if (c == 'x' || c == 'X')
		done += ft_print_x(va_arg(a, unsigned int), flag);
	else if (c == 'p')
		done += ft_print_p(va_arg(a, unsigned long long), flag);
	else if (c == '%')
		done += ft_print_percent(flag);
	return (done);
}

static int		len1(unsigned int a)
{
	unsigned int b;

	b = 0;
	while (a >= 10)
	{
		a /= 10;
		b++;
	}
	return (b + 1);
}

char			*ft_itoa(long int n)
{
	char			*a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;

	d = 0;
	c = (n < 0 ? -n : n);
	b = len1(c);
	if (!(a = (char *)malloc(sizeof(char) * b + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		a[d] = '-';
		b++;
	}
	d = b - 1;
	while (c >= 10)
	{
		a[d--] = c % 10 + '0';
		c /= 10;
	}
	a[d] = c % 10 + '0';
	a[b] = '\0';
	return (a);
}

char			ft_translator(unsigned int a, char itoa, t_flag flag)
{
	if ((a % 16) >= 10 && (flag.type == 'x' || flag.type == 'p'))
		itoa = (a % 16) + 55 + 32;
	else if ((a % 16) >= 10 && flag.type == 'X')
		itoa = (a % 16) + 55;
	else if ((a % 16) < 10)
		itoa = (a % 16) + 48;
	return (itoa);
}
