#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4000
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


char *get_next_line(int fd);

#endif