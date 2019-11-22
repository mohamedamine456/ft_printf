/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:39:48 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:25:56 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_hexa_convert(char *str, va_list *param, char conv)
{
	char			*s;
	unsigned int	nb;

	nb = va_arg(*param, unsigned int);
	s = ft_from_deci(nb, conv);
	//s = ft_apply_hexa_flags(s);
	return (s);
}
