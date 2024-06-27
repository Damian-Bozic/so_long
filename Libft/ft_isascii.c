/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:15:12 by dbozic            #+#    #+#             */
/*   Updated: 2024/02/27 13:20:59 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int	main(void)
{
#include <ctype.h>
#include <stdio.h>
	int	i;
	char	c;

	c = 127;
	i = 2;
	i = ft_isascii(c);
	//db_printint(i);
	printf("%d", i);

	c = 127;
	i = 2;
	i = isascii(c);
	//db_printint(i);
	printf("\n%d", i);
}*/
//Value returned is nonzero if c falls into the tested class