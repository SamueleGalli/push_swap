/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:11 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 11:25:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	i;
	int			s;
	long long	res;

	i = 0;
	s = 1;
	res = 0;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || (str[i] == ' '))
	{
		i++;
	}
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
		{
			s *= -1;
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * s);
}
