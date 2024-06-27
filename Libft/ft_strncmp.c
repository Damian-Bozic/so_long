/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:33:52 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/01 18:13:02 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str1[i] == str2[i] && n > i + 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	char	str1[] = "well \0 then, +hat was easy";
	char	str2[] = "well \135 then, that was easy";
	size_t	size = 24;
	int		i;

	i = 0;
	i = ft_strncmp(str1, str2, size);
	printf("%d", i);

	i = 0;
	i = strncmp(str1, str2, size);
	printf("\n%d", i);
}*/