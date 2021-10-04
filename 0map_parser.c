/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0map_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:20:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/04 11:26:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : create char array 2D in heap from linked list.
 * 1. Allocate memory for pointers. If array will have 8 files,
 * then 8 pointers are needed.
 * 2. Allocate mem for each string using string duplicate. */
char	**fix_map(t_list *list_map, t_vector dimensions)
{
	int		j;
	char	**map;

	map = ft_calloc(dimensions.y, sizeof(char *));
	if (!map)
		ft_shutdown(); //seria un return NULL y leugo hacer un full shut.
	j = -1;
	while (++j < dimensions.y)
	{
		map[j] = ft_strdup(list_map->content);
		list_map = list_map->next;
	}
	return (map);
}

/** PURPOSE : Obtain array dimensions from linked list. */
t_vector	get_dimensions(t_list *list_map)
{
	t_vector	dimensions;

	dimensions.y = ft_lstsize(list_map);
	dimensions.x = ft_strlen(list_map->content);
	return (dimensions);
}

/** PURPOSE : init 42minilibx and open window.
 * 1. It is fundamental to set pointer list map to NULL.
 * Otherwise, trash values can interfere with the program.
 * 2. Open file.
 * 3. Use get next line to read from file and load it to list.
 * 4. If GNL fails, free allocated memory.
 * 5. Close file. */
t_list	*read_map(void)
{
	t_list	*list_map;
	char	*line;
	int		fd;
	int		gnl;

	list_map = NULL;
	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		ft_shutdown();
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		ft_lstadd_back(&list_map, ft_lstnew(line));
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
	{
		while (list_map)
		{
			ft_fullclear(list_map);
			return (NULL); //o quiza hcer shutdown directo
		}
	}
	//si falla rl gnl poner condicion de liberar tambien game.
	close(fd);
	return (list_map);
}
