#include "libfts.h"

#define RM(file) (system("rm -f " file))

int		test_bzero(void)
{
	int i;
	char *s1;
	char *s2;
	int tab[]= {10, 5, 65, 4, 0, 845, -1};

	i = 0;
	while (tab[i] != -1)
	{
		s1 = (char*)malloc(sizeof(char) * 1001);
		memset(s1, 1, 1000);
		s1[1000] = 0;
		s2 = strdup(s1);
		ft_bzero(s1, tab[i]);
		bzero(s2, tab[i]);
		if (strncmp(s1, s2, 1000) != 0)
			return (1);
		i++;
	}
	ft_bzero(NULL, tab[i]);
	return (0);
}

int		test_cat(void)
{
	char	cmd[128];
	int		i;
	int		fd;
	int		mine;
	int		stdout;
	char	*files[] = {
		"Makefile",
		"/bin/ls",
		"/dev/null",
		"/usr/bin/python",
		"/usr/bin/audiodevice",
		NULL
	};

	stdout = dup(1);
	i = 0;
	while (files[i])
	{
		fd = open(files[i], O_RDONLY);
		mine = open("mine", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(mine, 1);
		ft_cat(fd);
		close(fd);
		close(mine);
		dup2(stdout, 1);
		bzero(cmd, 128);
		strcat(cmd, "diff ");
		strcat(cmd, files[i]);
		strcat(cmd, " mine >> diff_file");
		if (system(cmd) != 0)
			return (1);
		i++;
	}
	return (0);
}

int		test_isalnum(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isalnum(i) != isalnum(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_isalpha(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isalpha(i) != isalpha(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_isascii(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isascii(i) != isascii(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_isdigit(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isdigit(i) != isdigit(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_islower(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_islower(i) != islower(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_isprint(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isprint(i) != isprint(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_isupper(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_isupper(i) != isupper(i))
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

int		test_puts(void)
{
	char	buf[1024];
	int		i;
	int		mine;
	int		stdout;
	char	*tab[] = {
		"hello world",
		"",
		"foobarbaz",
		"qwertyuiopasdfghjklzxcvbnm",
		"1234567890-=!@#$%^&*()_+[]\\|{};':\",./<>?",
		"echo toto       tata    ",
		"one last simple test...",
		NULL
	};

	stdout = dup(1);
	i = 0;
	while (tab[i])
	{
		mine = open("mine", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(mine, 1);
		ft_puts(tab[i]);
		close(mine);
		dup2(stdout, 1);
		bzero(buf, 1024);
		mine = open("mine", O_RDONLY);
		read(mine, buf, 1023);
		close(mine);
		if (strcmp(buf, tab[i]) != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		test_strcat(void)
{
	int	i;
	char *a;
	char *b;
	char *ret;
	char *tab[] = {
		"hgsiufgussgf",
		"",
		"a",
		"trfghikolp[hb 53 540 8h8t 0 35g0ffbayw ufrjguaf \5 \10 fjsdihgisd]",
		"NULL",
		NULL
	};

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		a = (char*)malloc(sizeof(char) * 1001);
		bzero(a, 1001);
		memcpy(a, tab[i], strlen(tab[i]));
		b = (char*)malloc(sizeof(char) * 1001);
		bzero(b, 1001);
		memcpy(b, tab[i], strlen(tab[i]));
		ret = ft_strcat(a, tab[i + 1]);
		strcat(b, tab[i + 1]);
		if (ret != a || strncmp(a, b, 1001) != 0)
			return (1);
		i++;
	}
	a = NULL;
	ret = ft_strcat(a, "sdgyusdf");
	if (ret != a)
		return (1);
	a = "fgsdfgsdfgdsuf";
	ret = ft_strcat(a, NULL);
	if (ret != a)
		return (1);
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

int		test_tolower(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_tolower(i) != tolower(i))
			return (1);
		i++;
	}
	return (0);
}

int		test_toupper(void)
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (ft_toupper(i) != toupper(i))
			return (1);
		i++;
	}
	return (0);
}

int		main(void)
{
	int		i;
	s_test	tests[] = {
		{&test_bzero, "bzero"},
		{&test_cat, "cat"},
		{&test_isalnum, "isalnum"},
		{&test_isalpha, "isalpha"},
		{&test_isascii, "isascii"},
		{&test_isdigit, "isdigit"},
		{&test_islower, "islower"},
		{&test_isprint, "isprint"},
		{&test_isupper, "isupper"},
		{&test_memcpy, "memcpy"},
		{&test_memset, "memset"},
		{&test_puts, "puts"},
		{&test_strcat, "strcat"},
		{&test_strdup, "strdup"},
		{&test_strlen, "strlen"},
		{&test_tolower, "tolower"},
		{&test_toupper, "toupper"},
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
	RM("mine");
	RM("diff_file");
	return (0);
}
