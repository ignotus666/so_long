/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:15:00 by dhanlon           #+#    #+#             */
/*   Updated: 2025/09/22 10:41:39 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_zero(void)
{
	char	*char_str;

	char_str = (char *) malloc(sizeof (char) + 1);
	if (!char_str)
		return (NULL);
	char_str[0] = '0';
	char_str[1] = '\0';
	return (char_str);
}

static size_t	count_digits(long num)
{
	size_t	dig_cnt;
	long	tmp_num;

	tmp_num = num;
	dig_cnt = 0;
	while (tmp_num > 0)
	{
		tmp_num = tmp_num / 10;
		dig_cnt++;
	}
	return (dig_cnt);
}

static char	*conv_str(size_t dig_cnt, long num, int is_neg)
{
	size_t	i;
	char	*char_str;

	char_str = (char *) malloc(dig_cnt + is_neg + 1);
	if (!char_str)
		return (NULL);
	char_str[dig_cnt + is_neg] = '\0';
	i = dig_cnt + is_neg - 1;
	while (num > 0)
	{
		char_str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (char_str);
}

char	*ft_itoa(int n)
{
	long	num;
	int		is_neg;
	size_t	dig_cnt;
	char	*char_str;

	num = n;
	if (n == 0)
		return (if_zero());
	is_neg = 0;
	if (num < 0)
	{
		num = -num;
		is_neg = 1;
	}
	dig_cnt = count_digits(num);
	char_str = conv_str(dig_cnt, num, is_neg);
	if (is_neg == 1)
		char_str[0] = '-';
	return (char_str);
}
