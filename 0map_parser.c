/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0map_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:20:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/02 14:26:19 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fix_map(t_list *list_map, t_vector dimensions)
{
	char	**map;

	map = ft_calloc(dimensions.y, sizeof(char *));
	if (!map)
		ft_shutdown();
	int j = -1;
	while (++j < dimensions.y)
	{
		/* map[j] = ft_calloc(dimensions.x, sizeof(char));
		if (!map[j])
			ft_shutdown(); */
		map[j] = list_map->content; //reusando el puntero de la lista. + adelante hacer un strdup y limpiar lista. de momento dejala.
		list_map = list_map->next;
	}
	return (map);
}

t_vector	get_dimensions(t_list *list_map)
{
	t_vector	dimensions;

	dimensions.y = ft_lstsize(list_map);
	dimensions.x = ft_strlen(list_map->content);
	return(dimensions);
}

t_list	*read_map(void)
{
	t_list	*list_map;
	char	*line;
	int		fd;

	list_map = NULL;
	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		ft_shutdown();
	while (get_next_line(fd, &line))//si falla rl gnl poner condicion y hay que liberar
		ft_lstadd_back(&list_map, ft_lstnew(line));
	close(fd);
	return (list_map);
}
