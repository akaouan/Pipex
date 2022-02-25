/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:34:23 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/22 23:34:30 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pipex.h>

int	is_path(char *arg, char **path)
{
	int		i;
	int		sign;
	char	*cmd;
	int		paths;

	paths = ft_len(path);
	i = 0;
	sign = 0;
	arg = ft_strjoin("/", arg);
	while (path[i])
	{
		cmd = ft_strjoin(path[i], arg);
		if (access(cmd, F_OK) == -1)
			sign++;
		free(cmd);
		i++;
	}
	if (sign >= paths)
		return (0);
	return (1);
}

int	qouts(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 39)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	else if (count > 1)
		exit(1);
	return (0);
}

char	**get_paths(char **en)
{
	char	*str;
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(en[i], "PATH", 4))
		i++;
	str = ft_substr(en[i], 5, ft_strlen(*en));
	path = ft_split(str, ':');
	free(str);
	return (path);
}

int	get_index(char *arg, char c)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	execute(char *arg, char **paths)
{
	char	**pars;
	char	*cmd;
	char	*to_free;
	int		i;

	i = -1;
	if (qouts(arg))
		pars = ft_split(arg, 39);
	else
		pars = ft_split(arg, ' ');
	cmd = ft_substr(arg, 0, get_index(arg, ' '));
	to_free = cmd;
	cmd = ft_strjoin("/", cmd);
	free(to_free);
	paths_error(cmd, paths);
	while (paths[++i])
	{
		to_free = ft_strjoin(paths[i], cmd);
		execve(to_free, pars, NULL);
		free(to_free);
	}
}
