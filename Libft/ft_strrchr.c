/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:24:37 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 12:32:17 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (!c)
		return ((char *) &str[i]);
	while (i-- > 0)
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
	}
	return (0);
}
/* int	main(void)
{
#include <string.h>
#include <stdio.h>
	char	c = 'e';
	char	str1[] = "well then, that was easy";
	char	str2[] = "well then, that was easy";
	char	*ptr;

	ptr = ft_strrchr(str1, c);
	printf("%s", ptr);

	ptr = strrchr(str2, c);
	printf("\n%s", ptr);
} */