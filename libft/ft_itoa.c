/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:31:47 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/02 15:53:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_sign(char *n_str, int *i, long long *nn)
{
	if (*nn < 0)
	{
		*nn *= -1;
		n_str[*i] = '-';
		*i = *i + 1;
	}
}

char	*ft_itoa(long long nn)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char *)malloc(ft_nsize(nn) + 1);
	if (n_str == 0)
		return (0);
	if (nn < 0)
		check_sign(n_str, &i, &nn);
	while (nn > 9)
	{
		n_str[i] = (nn % 10) + 48;
		nn /= 10;
		i++;
	}
	n_str[i] = nn + 48;
	n_str[i + 1] = '\0';
	if (n_str[0] == '-')
		ft_strrev(n_str + 1);
	else
		ft_strrev(n_str);
	return (n_str);
}
