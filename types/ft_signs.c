/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:30:23 by gbump             #+#    #+#             */
/*   Updated: 2021/01/12 20:34:45 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int		ft_print_percent(t_flag flag)
{
	char	itoa[2];
	int		count;
	int		j;
	int		str;

	count = 0;
	itoa[0] = '%';
	itoa[1] = 0;
	str = 1;
	j = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, itoa, str);
	else if (flag.minus == 1)
	{
		count = dotadder(j, count, flag);
		count += ft_flagminus(icounter(flag, j), itoa, str, flag);
	}
	return (count);
}

int		ft_print_s(char *a, t_flag flag)
{
	int count;
	int j;
	int str;

	count = 0;
	if (a == NULL)
	{
		a = "(null)";
		count = 1;
	}
	str = (flag.dot == 0 ? 0 : ft_strlen(a));
	j = flag.dot;
	if (str > j && j != -1 && j != 0)
		str = j;
	count = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, a, str);
	else if (flag.minus == 1)
		count += ft_flagminus(icounter(flag, j), a, str, flag);
	return (count);
}

int		ft_print_c(char a, t_flag flag)
{
	char	itoa[2];
	int		count;
	int		j;
	int		str;

	count = 0;
	itoa[0] = a;
	itoa[1] = 0;
	str = ft_strlen(itoa);
	if (a == 0)
		str += 1;
	if ((j = flag.dot - ft_strlen(itoa) - 1) < 0)
		j = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, itoa, str);
	else if (flag.minus == 1)
	{
		count = dotadder(j, count, flag);
		count += ft_flagminus(icounter(flag, j), itoa, str, flag);
	}
	return (count);
}
