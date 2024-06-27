/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:29:11 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/13 14:29:16 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			j++;
		i++;
	}
	return (j);
}

static char	**free_all(char **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_strlenc(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**rtn;

	i = 0;
	j = 0;
	rtn = (char **)ft_calloc(1 + wordcount(str, c), sizeof(char *));
	if (!rtn)
		return (0);
	while (str[i] && str[i] == c)
		i++;
	while (j < wordcount(str, c))
	{
		rtn[j] = ft_substr(str, i, ft_strlenc(&str[i], c));
		if (!rtn[j])
			return (free_all(rtn, j));
		while (str[i] != c && str[i])
			i++;
		while (str[i] && str[i] == c)
			i++;
		j++;
	}
	return (rtn);
}

/*  int	main(void)
{
	int		i;
	int		j;
	char	check = ' ';
	char	str[] = "  nothing NO WAY THIS WORKS! ";
	char	**array;

	i = 0;
	j = 1 + wordcount(str, check);
	ft_putnbr_fd(j, 1);
	write(1, "\n", 1);
	array = ft_split(str, check);
	//ft_putnbr_fd(ft_strlen(array[11]), 1);
	while (i < (j))
	{
		ft_putnbr_fd(i, 1);
		write (1, " ", 1);
		if(array[i])
			ft_putstr_fd(array[i], 1);
		else
			write(1, "NULL", 4);
		write(1, "\n", 1);
		free(array[i]);
		i++;
	}
	free(array);
}  */