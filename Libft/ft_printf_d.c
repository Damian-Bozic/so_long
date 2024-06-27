/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:31 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/25 13:21:32 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_d(int d)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = d;
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		i++;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
