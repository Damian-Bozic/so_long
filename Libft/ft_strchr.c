/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:03:34 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 12:21:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!c && !str[i])
		return ((char *)&str[i]);
	return (0);
}
/* int	main(void)
{
#include <string.h>
#include <stdio.h>
	int	c = 0;
	char	str1[] = "tripouille";
	char	str2[] = "tripouille";
	char	*ptr;

	ptr = ft_strchr(str1, c);
	printf("%s", ptr);

	ptr = strchr(str2, c);
	printf("\n%s", ptr);
} */