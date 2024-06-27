/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:48:28 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 13:53:56 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char *)str1)[i] == ((unsigned char *)str2)[i]
			&& (n > 1))
	{
		n--;
		i++;
	}
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}

/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	char	c = 'n';
	char	str1[] = {0, 0, 127, 0};
	char	str2[] = {0, 0, 42, 0};
	size_t	size = 4;
	int		i;

	i = 0;
	i = ft_memcmp(str1, str2, size);
	printf("%d", i);

	i = 0;
	i = memcmp(str1, str2, size);
	printf("\n%d", i);
}*/
