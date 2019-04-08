#include "libfts.h"

int		test_strlen(void)
{
	size_t	mine;
	size_t	real;

	mine = ft_strlen("uvghbjnk");
	real = strlen("uvghbjnk");
	if (mine != real)
		return (1);
	return (0);
}

int main(void)
{
	if (test_strlen())
		printf("FAIL strlen\n");
	else
		printf("SUCCESS strlen\n");
}
