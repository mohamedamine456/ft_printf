/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:46:37 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/19 14:33:42 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list param;
	int		nb_car;

	nb_car = 0;
	va_start(param, str);
	ft_printf_helper(str, &param, &nb_car);
	va_end(param);
	return (nb_car);
}

int		ft_printf_helper(const char *str, va_list *param, int *nb_car)
{
	char	conv;

	while (*str)
	{
		if (*str == '%' && (conv = ft_isconvertion(str + 1)))
			ft_convert(&str, param, conv, nb_car);
		else
		{
			ft_putchar(*str);
			(*nb_car)++;
		}
		str++;
	}
	return (*nb_car);
}
