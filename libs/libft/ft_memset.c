/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:39 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:42:07 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_s;
	unsigned char	mem_c;
	size_t			i;

	mem_s = (unsigned char *)s;
	mem_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		mem_s[i] = mem_c;
		i++;
	}
	return (s);
}
