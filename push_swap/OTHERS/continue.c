/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:54:49 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 11:32:37 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freear(int k, char **av, t_list **s_a, int i)
{
	if (k == 1)
	{
		if (i == 0)
			free(av);
		ft_sa(s_a);
		ft_lst_delete(s_a);
		exit(0);
	}
	else
	{
		ft_sa(s_a);
		return ;
	}
}

void	attttoi(char *s)
{
	long long	j;

	j = ft_atoi(s);
	if (j >= 2147483647 || j <= -2147483648)
	{
		ft_display_exit();
	}
	return ;
}
