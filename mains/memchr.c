#include "h.h"

void	work(char *mem, int c, size_t m)
{
	char	*rv = dd_memchr(mem, c, m);
	if (rv == 0)
		printf("not found\n");
	else
		printf("ptr_diff: %zu\n", rv - mem);
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 33) + 1000;
	char			*mem = malloc((n + 1) * sizeof(char));
	size_t			i = 0;
	char			*rv;

	const size_t	m = n / 10000;
	while (i < m)
	{
		mem[i] = i % 255;
		i += 1;
	}
	int c = -1000;
	while (c <= 1000)
	{
		printf("[case %d('%c')]\n", c, c);
		work(mem, c, m);
		c += 1;
	}

	memset(mem, 'x', n - 1);
	mem[n - 1] = 'y';
	mem[n] = '\0';

	printf("[special case 1: very long found]\n");
	work(mem, 'y', n);

	printf("[special case 2: very long not found]\n");
	work(mem, 'z', n);

	return (0);
}
