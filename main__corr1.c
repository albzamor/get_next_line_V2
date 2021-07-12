#include "get_next_line.h"
#include <stdio.h>

int	main ( int argc, char **argv )
{
	int		fd;

	if (argc != 2)
		return (-1);
	printf("argv %s \n\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("\033[0;31mprimera linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31msegunda linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31mtercera linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31mcuarta  linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31mquienta linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31msexta   linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31mseptima linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31moctava  linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	printf("\033[0;31moctava  linea: 🚀\033[0;37m%s\n", get_next_line(fd));
	//system("leaks a.out");
}
	/* get_next_line(fd, &line);
	printf("\033[0;31mprimera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	//printf("line: %s\n", get_next_line(1) );
	//system("leaks a.out");
	//return (0);*/
