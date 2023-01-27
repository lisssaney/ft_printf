/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:29:01 by gbump             #+#    #+#             */
/*   Updated: 2021/01/13 16:25:01 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int		ft_print_u(unsigned int a, t_flag flag)
{
	char	*itoa;
	int		count;
	int		j;
	int		str;

	count = 0;
	itoa = ft_itoa(a);
	str = (flag.dot == 0 && a == 0 ? 0 : ft_strlen(itoa));
	if ((j = flag.dot - ft_strlen(itoa)) < 0)
		j = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, itoa, str);
	else if (flag.minus == 1)
	{
		count = dotadder(j, count, flag);
		count += ft_flagminus(icounter(flag, j), itoa, str, flag);
	}
	free(itoa);
	return (count);
}

int		ft_print_x(unsigned int a, t_flag flag)
{
	char	itoa[8];
	int		count;
	int		j;
	char	copy[8];
	int		str;

	count = -1;
	j = (int)a;
	while (a > 0 || (j == 0 && flag.dot != 0))
	{
		copy[++count] = ft_translator(a, '\0', flag);
		a /= 16;
		j += 1;
	}
	j = -1;
	while (count >= 0)
		itoa[++j] = copy[count--];
	str = j + 1;
	count = 0;
	if ((j = flag.dot - str) <= 0)
		j = 0;
	count += numberchanger(flag, j, itoa, str);
	return (count);
}

int		ft_print_p(unsigned long long a, t_flag flag)
{
	char					itoa[20];
	int						count;
	unsigned long long		j;
	char					copy[20];
	int						str;

	count = -1;
	j = a;
	while (a > 0 || (j == 0 && flag.dot != 0))
	{
		copy[++count] = ft_translator(a, '\0', flag);
		a /= 16;
		j += 1;
	}
	copy[++count] = 'x';
	copy[++count] = '0';
	j = -1;
	while (count >= 0)
		itoa[++j] = copy[count--];
	str = j + 1;
	count = 0;
	count += numberchanger(flag, j, itoa, str);
	return (count);
}

int		numberchanger(t_flag flag, int j, char *itoa, int str)
{
	int count;

	count = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, itoa, str);
	else if (flag.minus == 1)
	{
		count = dotadder(j, count, flag);
		count += ft_flagminus(icounter(flag, j), itoa, str, flag);
	}
	return (count);
}

int		ft_print_di(int a, t_flag flag)
{
	char	*itoa;
	int		count;
	int		j;
	int		str;

	count = 0;
	itoa = ft_itoa(a);
	str = (flag.dot == 0 && a == 0 ? 0 : ft_strlen(itoa));
	if ((j = flag.dot - (ft_strlen(itoa) - (a < 0 ? 1 : 0))) <= 0)
		j = 0;
	if (flag.minus == 0)
		count += ft_flagnotminus(flag, j, itoa, str);
	else if (flag.minus == 1)
	{
		if (itoa[0] == '-' && (flag.type == 'd' || flag.type == 'i'))
			count += checknumber(itoa, flag);
		count = dotadder(j, count, flag);
		count += ft_flagminus(icounter(flag, j), itoa, str, flag);
	}
	free(itoa);
	return (count);
}
