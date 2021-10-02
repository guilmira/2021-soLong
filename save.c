/* int		fd;
	t_list	*list_map;
	char	*path_map = "./0images/map.ber";
	char	*line;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		ft_shutdown();
	while (get_next_line(fd, &line))//si falla rl gnl poner condicion y hay que liberar
	{
		ft_lstadd_back(&list_map, ft_lstnew(line));
		printf("%s\n", list_map->content);
	}
	close(fd); */
