/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:45 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 11:20:29 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*mem_s;
	unsigned char	mem_c;
	int				i;

	mem_s = (unsigned char *)s;
	mem_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (mem_s[i] == mem_c)
			return ((char *)&mem_s[i]);
		i++;
	}
	if (mem_s[i] == mem_c)
		return ((char *)&mem_s[i]);
	else
		return (NULL);
}
