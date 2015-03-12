/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:11:36 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:58:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_tool
{
	char		*line;
	char		**tab;
	int			nb_line;
}				t_tool;

char			**set_tab(void);
int				get_line(char *arg, t_tool *toto);
int				get_tab(t_tool *toto);
void			fill_tab(t_tool *toto);
void			change_tab(t_tool *toto, int count, int i, int j);
void			print_tab(t_tool *toto);
void			ft_putchar(char c);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(t_tool *toto, char *s2);
void			ft_strsub(t_tool *toto, int i);

#endif
