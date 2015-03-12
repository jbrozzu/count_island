/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:14:30 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:25:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = ft_strlen(str);
	ret = malloc(sizeof(char) * (i + 1));
	while (str[j])
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoin(t_tool *toto, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(toto->line) +
				ft_strlen(s2) + 1));
	while (toto->line[i])
	{
		ret[i] = toto->line[i];
		i++;
	}
	while (s2[j])
	{
		ret[i] = s2[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_strsub(t_tool *toto, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		toto->tab[toto->nb_line][j] = toto->line[j];
		j++;
	}
	toto->tab[toto->nb_line][j] = '\0';
}
