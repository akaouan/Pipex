/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:35:41 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/23 15:35:42 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	paths_error(char *cmd, char **paths)
{
	if (!is_path(cmd, paths))
	{
		perror(cmd + 1);
		exit(0);
	}
}

int	**init_ends(int **ends, int size)
{
	int	i;

	i = 0;
	ends = malloc(sizeof(int *) * size);
	if (!ends)
		exit(1);
	while (i < size)
	{
		ends[i] = malloc(sizeof(int) * 2);
		if (!ends[i])
			exit(1);
		i++;
	}
	return (ends);
}

void	close_unused_pipes(t_elems *elems, int used_in, int used_out)
{
	int	i;

	i = 0;
	while (i < elems->size - 4)
	{
		if (elems->pipes[i][1] != used_out)
			close(elems->pipes[i][1]);
		if (elems->pipes[i][0] != used_in)
			close(elems->pipes[i][0]);
		i++;
	}
}

void	piping(t_elems *elems, int f1, int f2)
{
	int	id;

	id = fork();
	if (!id)
	{
		close_unused_pipes(elems, f1, f2);
		if (dup2(f1, 0) == -1)
			exit(1);
		if (dup2(f2, 1) == -1)
			exit(1);
		execute(elems->av[elems->cmd], elems->paths);
	}
	elems->pids[elems->i_pids++] = id;
	elems->cmd++;
	return ;
}

void	pipex(t_elems *elems)
{
	int	i;

	i = 0;
	piping(elems, elems->f1, elems->pipes[i++][1]);
	while (elems->cmd < elems->size - 2)
	{
		piping(elems, elems->pipes[i - 1][0], elems->pipes[i][1]);
		i++;
	}
	piping(elems, elems->pipes[i - 1][0], elems->f2);
	close_unused_pipes(elems, 0, 1);
}
