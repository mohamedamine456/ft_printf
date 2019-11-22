/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sint_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:48:09 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:29:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_sint_convert(char *str, va_list *param)
{
	char	*s;
	int		nb;

	nb = va_arg(*param, int);
	s = ft_itoa(nb);
	return (s);
}
