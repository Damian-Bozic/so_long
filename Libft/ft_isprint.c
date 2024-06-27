/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:23 by dbozic            #+#    #+#             */
/*   Updated: 2024/02/27 13:55:38 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
#include <ctype.h>
#include <stdio.h>
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i <= 127)
	{
	if (ft_isprint(i) == 0)
		printf("0");
	else
		printf("1");
	i++;
	}

	printf("\n\n");
	i = 0;
	while (i <= 127)
	{
	if (isprint(i) == 0)
		printf("0");
	else
		printf("1");
	i++;
	}
}*/
//Value returned is nonzero if c falls into the tested class
