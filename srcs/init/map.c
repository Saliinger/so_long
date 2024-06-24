#include "../../include/so_long.h"

static int width(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    return (i);
}

void	ft_map_chequer(t_map *map, char **argv)
{
	size_t	i;
	char	*line;
    t_map *temp;

	i = 0;
    temp = map;
    temp->y = open_fd(argv, map);
	temp->map = (char **)malloc(sizeof(char *) * (temp->y + 1));
	if (temp->map == NULL)
		return ;
	line = get_next_line(temp->fd);
    temp->x = width(line);
	while (line)
	{
		temp->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(temp->fd);
		i++;
	}
    temp->map[i] = NULL;
	free(line);
}