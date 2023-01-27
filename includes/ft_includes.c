/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:38:40 by gbump             #+#    #+#             */
/*   Updated: 2021/01/12 19:18:10 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_flag		ft_width_number(t_flag flag, char a)
{
	flag.width = (flag.width * 10) + (a - 48);
	return (flag);
}

t_flag		ft_width_star(va_list a, t_flag flag)
{
	flag.star = 1;
	if ((flag.width = va_arg(a, int)) < 0)
		flag.minus = 1;
	if (flag.width < 0)
		flag.width *= -1;
	return (flag);
}
