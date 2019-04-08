#include "libfts.h"

int		test_strlen(void)
{
	int		i;
	char	*tests[] = {
		"fdnjf",
		"",
		"42",
		"ksdjhfui hfsih siud f h fudffasd fuasdgoui fgadsf   dugf adushfg aduy gfafuyd gldfjgjdf ",
		"voici un texte pour tester le bon fonctionnement de mon strlen en asm 64 bits !",
		NULL
	};

	i = 0;
	while (tests[i]) {
		if (ft_strlen(tests[i]) != strlen(tests[i]))
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	if (test_strlen())
		printf("FAIL strlen\n");
	else
		printf("SUCCESS strlen\n");
}
