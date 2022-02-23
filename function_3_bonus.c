/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:35:47 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/23 15:35:51 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

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

int	get_input(char *end)
{
	char	*str;
	char	*to_free;
	int		fd;

	fd = open("/tmp/.temp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	str = get_next_line(0);
	while (ft_strncmp(str, end, ft_strlen(end)))
	{
		to_free = str;
		ft_putstr_fd(str, fd);
		str = get_next_line(0);
		free(to_free);
	}
	free(str);
	free(end);
	close(fd);
	return (open("/tmp/.temp", O_RDWR));
}
