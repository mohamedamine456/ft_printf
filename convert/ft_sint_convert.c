/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sint_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:48:09 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:15:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_sint_convert(char *str, int nb)
{
	char	*s;
	long nbs;

	nbs = nb;
	s = ft_itoa(nbs);
	return (s);
}
