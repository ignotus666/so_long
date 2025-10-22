/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:10 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 13:01:37 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem_s;
	unsigned char	mem_c;
	size_t			i;

	mem_s = (unsigned char *)s;
	mem_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (mem_s[i] == mem_c)
			return (mem_s + i);
		i++;
	}
	return (NULL);
}
