/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:01:28 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 12:07:31 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	atttoi(char *s, char **av)
{
	long long	j;
	int			i;

	i = 0;
	j = ft_atoi(s);
	if (j >= 2147483647 || j <= -2147483648)
	{
		while (av[i] != NULL)
		{
			free(av[i]);
			i++;
		}
		free(av);
		ft_display_exit();
	}
	return ;
}
