/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:48:40 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:58:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_pointer_convert(char *str,  unsigned int nb)
{
	char	*s;

	s = ft_from_deci(nb, 'x');
	//s = ft_apply_flags(s);
	return (s);
}
