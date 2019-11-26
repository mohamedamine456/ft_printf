/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:56:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/26 03:06:46 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_int_convert(char *str, va_list *param)
{
	char	*s;
	int		nb;
	t_flags	flag;

	s = ft_strdup("");
	initialize(&flag);
	nb = va_arg(*param, int);
	s = ft_itoa(nb);
	s = apply_int_flags(s, flag);
	return (s);
}
