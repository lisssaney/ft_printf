/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_incl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:15:58 by gbump             #+#    #+#             */
/*   Updated: 2021/01/12 19:16:02 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/ft_printf.h"

int		checknumber(char *itoa, t_flag flag)
{
	int i;

	i = 0;
	if (itoa[i] == '-' && (flag.type == 'd' || flag.type == 'i'))
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

int		ft_type(char a)
{
	if ((a == 'd') || (a == 'i') || (a == 'u') || (a == 'c')
	|| (a == 's') || (a == 'p') || (a == 'x') || (a == 'X') || (a == '%'))
		return (1);
	return (0);
}

int		ft_dot(const char *s, int i, t_flag *flag, va_list a)
{
	int j;

	j = i;
	j++;
	if (s[j] == '*')
	{
		if ((flag->dot = va_arg(a, int)) < 0)
			flag->dot = -1;
		j++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(s[j]))
		{
			flag->dot = (flag->dot * 10) + (s[j] - 48);
			j++;
		}
	}
	return (j);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
