/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:14:40 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:44:34 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*s_mem;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	s_mem = (char *) malloc(sizeof (char) * (s_len + 1));
	if (!s_mem)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s_mem[i] = f(i, s[i]);
		i++;
	}
	s_mem[i] = '\0';
	return (s_mem);
}
