/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:35:07 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/22 23:35:09 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	**init_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	pipes = malloc(sizeof(int *) * size);
	if (!pipes)
		exit(1);
	while (i < size)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (pipes);
}

int	**create_pipes(int size)
{
	int	**pipes;
	int	i;

	i = -1;
	pipes = NULL;
	pipes = init_pipes(pipes, size - 3);
	while (++i < size - 4)
		pipe(pipes[i]);
	return (pipes);
}

void	file_error(t_elems *elems)
{
	if (elems->f1 == -1)
		perror(elems->av[1]);
}

t_elems	*init_elems(t_elems *elems, char **av, char **env, int ac)
{
	elems = malloc(sizeof(t_elems));
	if (!elems)
		exit(1);
	elems->av = av;
	elems->env = env;
	elems->size = ac;
	elems->cmd = 2;
	elems->f1 = open(av[1], O_RDWR);
	file_error(elems);
	elems->f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	elems->paths = get_paths(env);
	elems->pids = malloc(sizeof(int) * elems->size - 3);
	if (!elems->pids)
		exit(1);
	elems->i_pids = 0;
	elems->pipes = create_pipes(elems->size);
	return (elems);
}

int	main(int ac, char **av, char **env)
{
	t_elems	*elems;

	elems = NULL;
	if (ac > 4)
	{
		elems = init_elems(elems, av, env, ac);
		pipex(elems);
		wait_all(elems);
		freeing(elems);
	}
	return (0);
}
