/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:41:19 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/21 15:41:42 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

/* int	main(void)
{
	int	src1 = 42;
	int src2 = 21;
	int	j;
	t_list *main_list = ft_lstnew(&src1);

	if (!main_list)
		write(1, "malloc error", 12);
	ft_lstadd_front(&main_list, ft_lstnew(&src2));

	t_list *current = ft_lstlast(main_list);
	j = *(int*)current->content;
	ft_putnbr_fd(j, 1);
	return (0);
} */