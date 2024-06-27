/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:16 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/07 17:57:30 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	size_after_trim(const char *str, const char *set)
{
	int		i;
	size_t	rtn;

	i = 0;
	rtn = (ft_strlen(str));
	while (isinset(set, str[i]) == 1)
	{
		if (str[i + 1] == '\0')
			return (0);
		rtn--;
		i++;
	}
	i = (ft_strlen(str) - 1);
	while (isinset(set, str[i]) == 1)
	{
		rtn--;
		i--;
	}
	return (rtn);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	char	*rtn;

	i = 0;
	while (isinset(set, str[i]) == 1)
	{
		if (i + 1 == '\0')
			return (0);
		i++;
	}
	rtn = ft_substr(str, i, size_after_trim(str, set));
	if (!rtn)
		return (0);
	return (rtn);
}

/*int	main(void)
{
	#include "stdio.h"
	char	str[] = " Wow, thats cool.  ";
	char	trim[] = "col. ";
	char	*ptr;

	ptr = ft_strtrim(str, trim);
	printf("%s", ptr);
	free(ptr);
}*/