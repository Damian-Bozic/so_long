/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:21:34 by dbozic            #+#    #+#             */
/*   Updated: 2024/02/27 18:29:27 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*int	main(void)
{
	#include <ctype.h>
	char b = '0';
	char c = '0';
	c = ft_toupper(c);
	write(1, &c,1);
	write(1, "\n", 1);
	b = toupper(b);
	write(1, &b, 1);
}*/