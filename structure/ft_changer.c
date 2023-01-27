/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:22:40 by gbump             #+#    #+#             */
/*   Updated: 2021/01/14 19:22:31 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int		ft_flagnotminus(t_flag flag, int j, char *itoa, int str)
{
	int len;
	int count;
	int minus;

	len = 0;
	count = 0;
	minus = 0;
	if (icounter(flag, j) > str)
		len = icounter(flag, j) - str;
	if (flag.dot == -1 && flag.zero == 1 && itoa[0] == '-' && flag.type != 'c')
		minus += checknumber(itoa, flag);
	count += minus;
	count += addersmth(len, flag);
	len = -1;
	if (flag.type == 'd' || flag.type == 'i')
		len = (itoa[0] == '-' ? 0 : -1);
	if (len == 0 && minus == 0)
		count += checknumber(itoa, flag);
	count = dotadder(j, count, flag);
	while (++len < str)
	{
		ft_putchar(itoa[len]);
		count++;
	}
	return (count);
}

int		icounter(t_flag flag, int j)
{
	int i;

	i = 0;
	if (flag.type == 'd' || flag.type == 'i' || flag.type == '%'
	|| flag.type == 'x' || flag.type == 'X' || flag.type == 'u'
	|| flag.type == 'c')
	{
		if ((i = (flag.width - j)) <= 0)
			i = 0;
	}
	if (flag.type == 'p' || flag.type == 's')
	{
		if ((i = flag.width) <= 0)
			i = 0;
	}
	return (i);
}

int		addersmth(int len, t_flag flag)
{
	int count;

	count = 0;
	while (len > 0)
	{
		if ((flag.type == '%' && flag.zero == 1 && flag.width != 0)
				|| (flag.zero == 1 && flag.dot == -1))
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
		len--;
	}
	return (count);
}

int		ft_flagminus(int i, char *itoa, int str, t_flag flag)
{
	int len;
	int count;

	len = -1;
	count = 0;
	if (itoa[0] == '-' && (flag.type == 'd' || flag.type == 'i'))
		len = 0;
	while (++len < str)
	{
		ft_putchar(itoa[len]);
		count++;
	}
	if (i > str)
		len = i - str;
	else
		len = -1;
	while (len > 0)
	{
		ft_putchar(' ');
		len--;
		count++;
	}
	return (count);
}

int		dotadder(int j, int count, t_flag flag)
{
	while ((j > 0 && flag.type != 's' && flag.type != 'p'))
	{
		ft_putchar('0');
		j--;
		count++;
	}
	return (count);
}
