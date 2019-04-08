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

int		test_isdigit(void)
{
	int i;
	int real;
	int mine;

	i = 0;
	while (i < 128)
	{
		mine = ft_isdigit(i);
		real = isdigit(i);
		if (mine != real)
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	printf("%d\n", test_isdigit());
	return 0;
}
