/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:33 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:42:01 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*mem_dest;
	const unsigned char	*mem_src;
	size_t				i;

	mem_dest = (unsigned char *)dest;
	mem_src = (const unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			mem_dest[i] = mem_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			mem_dest[i] = mem_src[i];
	}
	return (dest);
}
