/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:47:56 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 13:08:12 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nmemb_size;
	void	*p;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	nmemb_size = nmemb * size;
	p = malloc(nmemb_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb_size);
	return (p);
}
