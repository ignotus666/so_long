/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:18 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:41:50 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem_s1;
	unsigned char	*mem_s2;
	size_t			i;

	mem_s1 = (unsigned char *)s1;
	mem_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (mem_s1[i] != mem_s2[i])
			return (mem_s1[i] - mem_s2[i]);
		i++;
	}
	return (0);
}
