/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:37:30 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 12:08:45 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	string_lis(char *s)
{
	int			i;

	i = 0;
	if (s[0] == '\0')
		ft_display_exit();
	if ((s[0] == '+' || s[0] == '-') \
	&& (s[1] > '0' && s[1] <= '9'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			ft_display_exit();
	}
	attttoi(s);
}

void	string_char(char *s, char **av)
{
	int			i;
	int			k;

	i = 0;
	k = -1;
	if (s[0] == '\0')
		ft_display_exit();
	if ((s[0] == '+' || s[0] == '-') \
	&& (s[1] > '0' && s[1] <= '9'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
		{
			while (av[++k] != NULL)
				free(av[k]);
			free(av);
			ft_display_exit();
		}
	}
	atttoi(s, av);
}
