/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:23 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/08 10:54:29 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int	main(void)
{
#include <ctype.h>
	int	i;
	char	c;

	c = 'n';
	i = 2;
	i = ft_isalpha(c);
	db_printint(i);

	c = 'n';
	i = 2;
	i = isalpha(c);
	db_printint(i);
}*/
//Value returned is nonzero if c falls into the tested class