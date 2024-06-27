/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:48 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/25 13:21:49 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	printhex(int i, int x)
{
	if (i >= 0 && i <= 9)
		i = i + '0';
	else if (i >= 10 && i <= 15 && x == 'X')
		i = i + 55;
	else
		i = i + 87;
	return (i);
}

static int	ft_puthex(size_t	n, int x)
{
	int		i;
	int		temp;
	char	output[9];

	i = 0;
	ft_bzero(output, 9);
	while (n != 0 && i < 8)
	{
		temp = n % 16;
		output[i] = printhex(temp, x);
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar_fd(output[i], 1);
	return (ft_strlen(output));
}

int	ft_printf_xx(int d, int x)
{
	int		n;
	int		rtn;

	n = d;
	rtn = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_puthex((size_t)n, x));
}
