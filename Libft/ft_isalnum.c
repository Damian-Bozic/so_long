/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:23 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/01 18:17:21 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	#include <ctype.h>
	int	i;
	char	c;

	i = 2;
	c = '+';
	i = ft_isalnum(c);
	db_printint(i);

	i = 2;
	c = '+';
	i = isalnum(c);
	db_printint(i);
}*/
//Value returned is nonzero if c falls into the tested class
