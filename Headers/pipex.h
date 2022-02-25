/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:35:22 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/22 23:35:23 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list{
	int		f1;
	int		f2;
	int		cmd;
	int		size;
	char	**av;
	char	**env;
	char	**paths;
	int		**pipes;
	int		*pids;
	int		i_pids;
}t_elems;

int		ft_len(char **str);
void	wait_all(t_elems *elems);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strrchr2(const char *s, int c);
int		is_path(char *arg, char **path);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
int		get_input(char *end);
char	**get_paths(char **en);
void	execute(char *arg, char **paths);
void	paths_error(char *cmd, char **paths);
void	pipex(t_elems *elems);
void	freeing(t_elems *elems);
#endif
