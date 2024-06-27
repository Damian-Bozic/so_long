/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:23 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 16:16:40 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	#include <ctype.h>
	int	i;
	char	c;

	c = '2';
	i = ft_isdigit(c);
	db_printint(i);

	c = '2';
	i = isdigit(c);
	db_printint(i);
}*/
//Value returned is nonzero if c falls into the tested class