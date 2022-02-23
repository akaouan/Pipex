/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:34:47 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/22 23:34:49 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	wait_all(t_elems *elems)
{
	int	i;

	i = 0;
	while (i < elems->size - 3)
		waitpid(elems->pids[i++], 0, 0);
}

void	freeing(t_elems *elems)
{
	int	i;

	i = 0;
	while (elems->paths[i])
		free(elems->paths[i++]);
	free(elems->paths);
	i = 0;
	while (i < elems->size - 3)
		free(elems->pipes[i++]);
	free(elems->pipes);
	free(elems->pids);
}
