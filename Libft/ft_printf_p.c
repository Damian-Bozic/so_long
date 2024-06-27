/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:23 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/25 13:21:25 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	intdec_to_hexchar(int i)
{
	if (i >= 0 && i <= 9)
		i = i + '0';
	else if (i >= 10 && i <= 15)
		i = i + 87;
	return ((char)i);
}

static int	printnil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_printf_p(void *ptr)
{
	int				i;
	unsigned long	address;
	int				temp;
	char			output[21];

	i = 0;
	if (!ptr)
		return (printnil());
	address = (unsigned long)ptr;
	ft_bzero(output, 20);
	write(1, "0x", 2);
	while (address != 0)
	{
		temp = address % 16;
		output[i] = intdec_to_hexchar(temp);
		address /= 16;
		i++;
	}
	temp = ft_strlen(output) + 2;
	while (i--)
		ft_putchar_fd(output[i], 1);
	return (temp);
}
