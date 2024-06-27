/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:54:09 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 14:50:31 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] != '\0' && n > i)
	{
		while (big [i + j] == little[j] && n > i + j)
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	#include <string.h>
	#include <stdio.h>
	char	big[] = "Hello there, this is big\0";
	char	little[] = "";
	int	search = 10;
	char	*result;

	result = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	printf("%s", result);
}*/