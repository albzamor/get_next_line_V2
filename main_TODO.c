#include "get_next_line.h"
#include <stdio.h>

int	main ( int argc, char **argv )
{
	int		fd;
	int 	i;

	i = 1;
	if (argc != 2)
		return (-1);
	printf("argv %s \n\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	while (i < 50)
	{
		printf("\033[0;31m %i linea: 🚀\033[0;37m%s\n", i, get_next_line(fd));
		i++;
	}
	//system("leaks a.out");
}
	/* get_next_line(fd, &line);
	printf("\033[0;31mprimera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	//printf("line: %s\n", get_next_line(1) );
	//system("leaks a.out");
	//return (0);*/
