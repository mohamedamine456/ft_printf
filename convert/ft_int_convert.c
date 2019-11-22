/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:56:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:26:58 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_int_convert(char *str, va_list *param)
{
	char	*s;
	int		nb;

	nb = va_arg(*param, int);
	s = ft_itoa(nb);
	//s = ft_apply_int_flags(s);
	return (s);
}

/*char	*check_flags(char *str)
{

}*/
