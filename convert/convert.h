/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:43:32 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:59:55 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
#include "../libft/libft.h"

char	*ft_int_convert(char *str, int nb);
char	*ft_char_convert(char *str, int nb);
char	*ft_hexa_convert(char *str, unsigned int nb, char conv);
char	*ft_pointer_convert(char *str, unsigned int nb);
char	*ft_sint_convert(char *str, int nb);
char	*ft_unsint_convert(char *str, unsigned int nb);
char	*ft_string_convert(char *str, char *s);
char	*ft_from_deci(int nb, char conv);

#endif
