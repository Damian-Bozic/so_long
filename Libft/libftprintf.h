/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:46 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/14 15:10:35 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);
int		ft_printf_c(char c);
int		ft_printf_s(char *str);
int		ft_printf_p(void *ptr);
int		ft_printf_d(int d);
int		ft_printf_u(unsigned int u);
int		ft_printf_xx(int d, int x);

#endif
