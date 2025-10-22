/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:49:32 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:44:45 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*mem_s1;
	const unsigned char	*mem_s2;
	size_t				i;
	int					diff;

	mem_s1 = (const unsigned char *)s1;
	mem_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && mem_s1[i] == mem_s2[i]
		&& mem_s1[i] != '\0' && mem_s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	diff = mem_s1[i] - mem_s2[i];
	return (diff);
}

/*int main(void)
{
	char *s1 = "aBCz";
	char *s2 = "aBC";
	unsigned int n = 4;
	int diff = ft_strncmp(s1, s2, n);
	printf("%d", diff);
	printf("%s", "\n");
	return (0);
}*/