/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:36:56 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/25 17:01:34 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*nxt;

	if (lst && *lst && del)
	{
		current = *lst;
		while (current)
		{
			nxt = current->next;
			del(current->content);
			free(current);
			current = nxt;
		}
	}
	if (lst)
		*lst = NULL;
}
