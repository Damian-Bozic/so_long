/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:44:28 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 11:29:40 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;

	ptr = malloc(ft_strlen(str) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str, 1 + ft_strlen(str));
	return (ptr);
}

/* int	main(void)
{
	#include <string.h>
	#include <stdio.h>

	char *ptr;
	char str[19] = "Hello memory leaks\0";
  	
	ptr = ft_strdup(str);
	printf("%s", ptr);
	free (ptr);

	ptr = strdup(str);
	printf("\n%s", ptr);
	free (ptr);
	return 0;
} */