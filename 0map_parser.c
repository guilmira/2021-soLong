/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0map_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:20:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/08 12:13:59 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Obtain array dimensions from linked list.
 * 1. Also handles a bit of map parser. */
t_vector	get_dimensions(t_list *list_map)
{
	t_vector	dimensions;

	dimensions.y = ft_lstsize(list_map);
	dimensions.x = ft_strlen(list_map->content);
	return (dimensions);
}

static int	check_items(char **map, t_vector dimensions)
{
	int	i;
	int	j;
	int	array[3];

	i = -1;
	while (++i < 3)
		array[i] = 0;
	i = -1;
	j = -1;
	while (++i < dimensions.y)
	{
		while (++j < dimensions.x)
		{
			if (map[i][j] == CHARACTER)
				array[0]++;
			if (map[i][j] == COLLECTABLE)
				array[1]++;
			if (map[i][j] == EXIT)
				array[2]++;
		}
		j = -1;
	}
	i = -1;
	while (++i < 3)
	{
		if (!array[i])
			return (1);
	}
	return (0);
}

/** PURPOSE : main parser. Checks the following
 * 1. Dimensions are not bigger than given size.
 * 2. Dimensions are not 0.
 * 3. Map is indeed a rectangle. No file has an altered size.
 * 4. Maps are surrounded by walls, i.e. '1'.
 * 5. At least one exit, character and collectible are present. */
int	parser_map(char **map, t_vector dimensions)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (dimensions.y > MAX_HEIGHT || dimensions.x > MAX_WIDTH)
		return (6);
	if (dimensions.y == 0 || dimensions.x == 0)
		return (6);
	while (++i < dimensions.y)
	{
		if ((int) ft_strlen(map[i]) != dimensions.x)
			return (5);
		while (++j < dimensions.x)
		{
			if (i == 0 || i == dimensions.y - 1)
				if (map[i][j] != '1')
					return (4);
			if (j == 0 || j == dimensions.x - 1)
				if (map[i][j] != '1')
					return (4);
		}
		j = -1;
	}
	if (check_items(map, dimensions))
		return (4);
	return (0);
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
t_list	*read_map(void)
{
	t_list	*list_map;
	char	*line;
	int		fd;
	int		gnl;

	list_map = NULL;
	line = NULL;
	fd = open(PATH_MAP, O_RDONLY);
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
