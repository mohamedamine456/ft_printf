/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:39:48 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:54:48 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_hexa_convert(char *str, unsigned int nb , char conv)
{
	char	*s;

	s = ft_from_deci(nb , conv);
	//s = ft_apply_hexa_flags(s);
	return (s);
}
