/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:48:40 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:28:01 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_pointer_convert(char *str, va_list *param)
{
	char			*s;
	unsigned int	nb;

	nb = va_arg(*param, unsigned int);
	s = ft_from_deci(nb, 'x');
	//s = ft_apply_flags(s);
	return (s);
}
