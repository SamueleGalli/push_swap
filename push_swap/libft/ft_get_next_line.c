/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:50:46 by sgalli            #+#    #+#             */
/*   Updated: 2023/03/14 11:03:34 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (s == 0)
	{
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (new == 0)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(s);
	return (new);
}

char	*ft_read_line_gnl(int fd, char *dst)
{
	int		len;
	char	buf;

	len = 1;
	while (len != 0 && buf != '\n')
	{
		len = read(fd, &buf, 1);
		if (len == -1)
		{
			return (NULL);
		}
		dst = ft_strjoin_gnl(dst, buf);
	}
	if (dst[0] == '\n')
	{
		return ("\n");
	}
	if (dst[1] == 0)
	{
		return (NULL);
	}
	return (dst);
}

char	*ft_get_next_line_gnl(int fd)
{
	char	*dst;

	if (fd < 0)
	{
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * 1);
	if (dst == 0)
	{
		return (NULL);
	}
	dst[0] = '\0';
	dst = ft_read_line_gnl(fd, dst);
	if (dst == 0)
	{
		return (NULL);
	}
	return (dst);
}
