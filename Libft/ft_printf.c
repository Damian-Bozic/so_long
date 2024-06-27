/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:50:29 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/22 14:51:20 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_selected(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(args, int)));
	if (c == 's')
		return (ft_printf_s(va_arg(args, char *)));
	if (c == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printf_d(va_arg(args, int)));
	if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_printf_xx(va_arg(args, int), c));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (0);
}
// Our implementation of %i tells us just use base 10

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rtn;
	va_list	args;

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			rtn += print_selected(str[i], args);
		}
		else if (str[i])
		{
			ft_putchar_fd(str[i], 1);
			rtn++;
		}
		i++;
	}
	va_end(args);
	return (rtn);
}

/* int main(void)
{
	#include "stdio.h"
	int	j;
	void *ptr = &j;

	j = 0;
	j = ft_printf("a\0l");
	printf("\n%d\n", j);

	j = 0;
	j = printf("a\0l");
	printf("\n%d", j);
}  */

// %d assumes base 10 while %i autodetects other bases
// Base 10 if a number that doesn’t start with 0 or 0x.
// Base 8 (octal) if the number starts with 0.
// Base 16 (hexadecimal) if the number starts with 0x or 0X.
// test for %%d
//'\0' stops printf but %c '\0' doesnt;
//each call to va_arg advances the list;
//data_type variable = va_arg(args, data_type);
//int value = va_arg(args, int);