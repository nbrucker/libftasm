#ifndef LIBFTS_H
# define LIBFTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct	s_test
{
	int			(*ptr)();
	char		*name;
}				s_test;

int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

#endif
