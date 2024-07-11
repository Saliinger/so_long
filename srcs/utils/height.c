#include "../../include/so_long.h"

size_t	open_fd(char **argv, t_map *map)
{
	size_t	i;
	char	*line;
	t_map	*temp;

	temp = map;
	temp->fd = open(argv[1], O_RDONLY);
	i = 0;
	line = get_next_line(temp->fd);
	while (line)
	{
		free(line);
		line = get_next_line(temp->fd);
		i++;
	}
	free(line);
	close(temp->fd);
	temp->fd = open(argv[1], O_RDONLY);
	return (i);
}
