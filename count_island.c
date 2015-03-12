/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:11:18 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:58:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

char	**set_tab(void)
{
	char	**tab;
	int		k;

	k = 0;
	tab = malloc(sizeof(char *) * 256);
	while (k < 256)
	{
		tab[k] = malloc(sizeof(char) * (1024 + 1));
		k++;
	}
	return (tab);
}

int		get_line(char *arg, t_tool *toto)
{
	int		fd;
	int		j;
	char	*buf;
	int		flag;

	flag = 0;
	buf = malloc(sizeof(char) * (10));
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putchar('\n');
		return (1);
	}
	while ((j = read(fd, buf, 10)) > 0)
	{
		buf[j] = '\0';
		if (flag == 0)
		{
			toto->line = ft_strdup(buf);
			flag++;
		}
		else
			toto->line = ft_strjoin(toto, buf);
	}
	return (0);
}

void	print_tab(t_tool *toto)
{
	int i;
	int j;

	i = 0;
	while (i < toto->nb_line)
	{
		j = 0;
		while (toto->tab[i][j])
		{
			ft_putchar(toto->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_tool	toto;

	toto.tab = set_tab();
	if (ac == 2)
	{
		if (get_line(av[1], &toto) == 1)
			return (0);
		if (get_tab(&toto) == 1)
			return (0);
		fill_tab(&toto);
		print_tab(&toto);
	}
	else
		ft_putchar('\n');
	return (0);
}
