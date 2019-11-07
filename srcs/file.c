#include "../inc/ft_ssl.h"

char			*handle_file(char *filepath)
{
	int		fd;
	char	*to_hash;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		printf("(debug): open error %s\n", strerror(errno));
		return (NULL);
	}
	if ((to_hash = get_content(fd)) == NULL)
	{
		printf("(debug) error while reading the file\n");
		return (NULL);
	}
	return (to_hash);
}

void			handle_files_aux(t_handler *handler, char **filespath, unsigned int i)
{
	if (filespath[i] == NULL)
		return ;
	handler->processes = push_process(handler->processes, filespath[i], H_FILE);
	handle_files_aux(handler, filespath, i + 1);
}

void			handle_files(t_handler *handler, char **filespath)
{
	handle_files_aux(handler, filespath, 0);
}
