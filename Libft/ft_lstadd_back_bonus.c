/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:42:16 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/21 15:43:13 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		lst = &new;
	current = ft_lstlast(*lst);
	current->next = new;
}

/* int	main(void)
{
	int	src1 = 42;
	int src2 = 21;
	int	src3 = 10;
	int	j;
	t_list *main_list = ft_lstnew(&src1);

	if (!main_list)
		write(1, "malloc error", 12);
	ft_lstadd_front(&main_list, ft_lstnew(&src2));
	ft_lstadd_back(&main_list, ft_lstnew(&src3));
	t_list *current = ft_lstlast(main_list);
	j = *(int*)current->content;
	ft_putnbr_fd(j, 1);
	return (0);
}  */