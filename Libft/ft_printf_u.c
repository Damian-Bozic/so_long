/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:41 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/25 13:21:43 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_u(unsigned int u)
{
	int				i;
	unsigned int	unbr;
	char			str[11];

	i = 0;
	unbr = u;
	if (!u)
	{
		write(1, "0", 1);
		return (1);
	}
	while (unbr)
	{
		str[i] = (unbr % 10);
		unbr /= 10;
		i++;
	}
	unbr = (unsigned int) i--;
	while (i >= 0)
		ft_putnbr_fd(str[i--], 1);
	return ((int)unbr);
}
