/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:19:39 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:30:48 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_unsint_convert(char *str, va_list *param)
{
	char			*s;
	unsigned int	nb;

	nb = va_arg(*param, unsigned int);
	s = ft_itoa(nb);
	return (s);
}
