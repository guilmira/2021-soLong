/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2map_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:20:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 15:10:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Obtain array dimensions from linked list. */
t_vector	get_dimensions(t_list *list_map)
{
	t_vector	dimensions;

	dimensions.y = ft_lstsize(list_map);
	dimensions.x = ft_strlen(list_map->content);
	return (dimensions);
}

/** PURPOSE : create char array 2D in heap from linked list.
 * 1. Allocate memory for pointers. If array will have 8 files,
 * then 8 pointers are needed.
 * 2. Allocate mem for each string using string duplicate.
 * IMPORTANT : if mem alloc fails, function returns NULL.
 * IMPORTANT2 : when using calloc, sizeof(char **) works pefectly,
 * meanhwile sizeof(**map) will eventually give seg-fault
 * Full-shutdown and freeing memory will be executed in main. */
char	**fix_map(t_list *list_map, t_vector dimensions)
{
	int		j;
	char	**map;

	map = ft_calloc(dimensions.y, sizeof(char **));
	if (!map)
		return (NULL);
	j = -1;
	while (++j < dimensions.y && list_map)
	{
		map[j] = ft_strdup(list_map->content);
		if (!(map[j]))
			return (NULL);
		list_map = list_map->next;
	}
	return (map);
}

/** PURPOSE : init 42minilibx and open window.
 * 1. It is fundamental to set pointer list map to NULL.
 * Otherwise, trash values can interfere with the program.
 * 2. Open file.
 * 3. Use get next line to read from file and load it to list.
 * 4. Close file.
 * IMPORTANT : if open file fails, or GNL files, reutrn will be NULL.
 * Shutdown will be executed in main program.
 * IMPORTANT2 : after reading the file, gen next line is exxecuted one last time
 * and gives the zero value. that execution allocates memory for line, therfore
 * line must be freed after loop in order to prevent a mem-leak. */
t_list	*read_map(char *file_name)
{
	t_list	*list_map;
	char	*line;
	int		fd;
	int		gnl;

	list_map = NULL;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		ft_lstadd_back(&list_map, ft_lstnew(line));
		gnl = get_next_line(fd, &line);
	}
	free(line);
	if (gnl == -1)
	{
		if (list_map)
			ft_fullclear(list_map);
		return (NULL);
	}
	close(fd);
	return (list_map);
}

/** PURPOSE : Check that there is at least one of each item. */
int	check_items(char **map, t_vector dimensions, char z)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	j = -1;
	counter = 0;
	while (++i < dimensions.y)
	{
		while (++j < dimensions.x)
		{
			if (map[i][j] == z)
				counter++;
		}
		j = -1;
	}
	if (!counter)
		return (1);
	return (0);
}
