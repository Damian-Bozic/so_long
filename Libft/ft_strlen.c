/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:57:26 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/26 18:42:09 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	int	i;
	char	str[] = "If I had to guess this should work.";

	i = 2;
	i = ft_strlen(str);
	//db_printint(i);
	printf("%d", i);

	i = 2;
	i = strlen(str);
	//db_printint(i);
	printf("\n%d", i);
}*/
