/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:21:34 by dbozic            #+#    #+#             */
/*   Updated: 2024/02/27 18:31:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	#include <ctype.h>
	char b = 'A';
	char c = 'A';
	c = ft_tolower(c);
	write(1, &c,1);
	write(1, "\n", 1);
	b = tolower(b);
	write(1, &b, 1);
}*/