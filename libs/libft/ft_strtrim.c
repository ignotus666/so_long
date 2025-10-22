/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:49:51 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 13:00:38 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_trimmed(void)
{
	char	*trimmed;

	trimmed = (char *) malloc(sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';
	return (trimmed);
}

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	l_index;
	size_t	t_index;
	size_t	i;

	l_index = 0;
	while (is_in_set(s1[l_index], set))
		l_index++;
	t_index = ft_strlen(s1);
	if (t_index == 0)
		return (empty_trimmed());
	t_index--;
	while (t_index >= l_index && is_in_set(s1[t_index], set))
		t_index--;
	if (l_index > t_index)
		return (empty_trimmed());
	trimmed = (char *) malloc(sizeof(char) * (t_index - l_index + 2));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (l_index <= t_index)
		trimmed[i++] = s1[l_index++];
	trimmed[i] = '\0';
	return (trimmed);
}
