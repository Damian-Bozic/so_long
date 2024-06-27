/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:52 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 11:18:46 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinfilter(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	rtn;
	int	sign;

	rtn = 0;
	sign = 1;
	if (!*nptr)
		return (0);
	while (isinfilter(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		rtn = rtn * 10 + ((*nptr) - '0');
		nptr++;
	}
	return (rtn * sign);
}

/*int	main(void)
{
	#include <stdlib.h>
	#include <stdio.h>
	char	str[] = "-821s341";
	int		i;
	int		j;

	i = atoi(str);
	printf("%d", i);
	j = ft_atoi(str);
	printf("\n%d\n", j);
	printf("%s\n", str);

	if (i == j)
		printf("Pass");
	else
		printf("Fail");
}*/