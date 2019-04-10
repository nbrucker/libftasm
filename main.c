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

int		test_memcpy(void)
{
	char	*a;
	char	*b;
	int		i;
	char	*ret;
	char	*text[] = {
		"hdfgadfg fgbqrg q",
		"                                     ",
		"42",
		"ksdjhfui hfsih siud f h fudffasd fuasdgoui fgadsf   dugf adushfg aduy gfafuyd gldfjgjdf ",
		"voici un texte pour tester le bon fonctionnement de mon strlen en asm 64 bits !",
		NULL
	};
	int		len[] = {
		12,
		5,
		0,
		7,
		23
	};

	a = (char*)malloc(sizeof(char) * 1001);
	memset(a, 1, 1000);
	a[1000] = 0;
	b = strdup(a);

	i = 0;
	while (text[i])
	{
		ret = ft_memcpy(a, text[i], len[i]);
		memcpy(b, text[i], len[i]);
		if (ret != a || strncmp(a, b, 1001) != 0)
			return (1);
		i++;
	}
	ft_memcpy(NULL, "fsfshdf", 2);
	ft_memcpy("fsdfadf", NULL, 2);
	ft_memcpy(NULL, NULL, 2);
	return (0);
}

int		test_memset(void)
{
	int		i;
	int		j;
	char	*a;
	char	*b;
	char	*ret;

	a = (char*)malloc(sizeof(char) * 1001);
	memset(a, 1, 1000);
	a[1000] = 0;
	b = strdup(a);

	i = 0;
	while (i < 1000)
	{
		j = -500;
		while (j < 500)
		{
			ret = ft_memset(a, j, i);
			memset(b, j, i);
			if (ret != a || strncmp(a, b, 1001) != 0)
				return (1);
			j++;
		}
		i++;
	}
	ft_memset(NULL, 10, 10);
	return (0);
}

int		test_strdup(void)
{
	char	*a;
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
		a = ft_strdup(tests[i]);
		if (strcmp(a, tests[i]) != 0)
			return (1);
		i++;
	}
	ft_strdup(NULL);
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
	ft_strlen(NULL);
	return (0);
}

int		main(void)
{
	int		i;
	s_test	tests[] = {
		{&test_isdigit, "isdigit"},
		{&test_memcpy, "memcpy"},
		{&test_memset, "memset"},
		{&test_strdup, "strdup"},
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
