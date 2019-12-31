/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:38:12 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 20:38:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

void	ft_char_convert(char *str, va_list *param, int *nb_car)
{
	t_flags	flag;
	char	s;

	initialize(&flag);
	check_flags(str, &flag, param);
	s = va_arg(*param, int);
	apply_char_flags(s, flag, nb_car);
}

void	apply_char_flags(char s, t_flags flag, int *nb_car)
{
	char	*space;
	int		len;

	if (1 < flag.width)
		len = flag.width;
	else
		len = 1;
	space = malloc(len);
	if (flag.sign)
	{
		ft_putchar(s);
		ft_memset(space, ' ', len - 1);
		space[len - 1] = '\0';
		ft_putstr(space);
	}
	else
	{
		ft_memset(space, ' ', len - 1);
		space[len - 1] = '\0';
		ft_putstr(space);
		ft_putchar(s);
	}
	(*nb_car) += ft_strlen(space) + 1;
	free(space);
}
