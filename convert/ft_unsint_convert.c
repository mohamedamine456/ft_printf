/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:19:39 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:44:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_unsint_convert(char *str, unsigned int nb)
{
	char	*s;
	long	nbs;

	nbs = nb;
	s = ft_itoa(nbs);
	return (s);
}
