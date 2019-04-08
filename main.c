#include "libfts.h"

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

int		test_memset(void)
{
	char	*a;
	void	*ret;

	a = strdup("aaaaaaaa");
	printf("%p\n", a);
	ret = ft_memset(a, 'b', 3);
	printf("%p\n", a);
	printf("%p\n", ret);
	printf("%s\n", a);
	return (0);
}

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

int		main(void)
{
	int		i;
	s_test	tests[] = {
		{&test_isdigit, "isdigit"},
		{&test_memset, "memset"},
		{&test_strlen, "strlen"},
		{NULL, NULL}
	};

	i = 0;
	while (tests[i].ptr)
	{
		if (tests[i].ptr())
			printf("\x1b[31mFAIL %s\x1b[0m\n", tests[i].name);
		else
			printf("\x1b[32mSUCCESS %s\x1b[0m\n", tests[i].name);
		i++;
	}
	return (0);
}
