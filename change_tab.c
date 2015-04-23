/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 12:21:45 by exam              #+#    #+#             */
/*   Updated: 2015/04/23 18:05:54 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int		get_tab(t_tool *toto)
{
	int i;
	int j;

	i = 0;
	j = 0;
	toto->nb_line = 0;
	while (toto->line[i++])
	{
		i = 0;
		while (toto->line[i] != '\n')
			i++;
		if (j)
		{
			if (j != i)
			{
				ft_putchar('\n');
				return (1);
			}
		}
		j = i;
		ft_strsub(toto, i);
		toto->nb_line++;
		toto->line = &toto->line[i + 1];
	}
	return (0);
}

void	change_tab(t_tool *toto, int count, int i, int j)
{
	if (toto->tab[i][j] == 'X')
	{
		toto->tab[i][j] = (count + '0');
		if (toto->tab[i][j + 1] && toto->tab[i][j + 1] == 'X')
			change_tab(toto, count, i, j + 1);
		if (((i + 1) < toto->nb_line) && toto->tab[i + 1][j] == 'X')
			change_tab(toto, count, i + 1, j);
		if (j > 0 && toto->tab[i][j - 1] == 'X')
			change_tab(toto, count, i, j - 1);
		if (i > 0 && toto->tab[i - 1][j] == 'X')
			change_tab(toto, count, i - 1, j);
	}
}

void	fill_tab(t_tool *toto)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < toto->nb_line)
	{
		j = 0;
		while (toto->tab[i][j])
		{
			if (toto->tab[i][j] == 'X')
			{
				change_tab(toto, count, i, j);
				count++;
			}
			j++;
		}
		i++;
	}
}
