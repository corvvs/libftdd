#include "h.h"

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
		mem[i] = i % 255 + 1;
		i += 1;
	}
	mem[i] = '\0';
	int c = -1000;
	while (c <= 1000)
	{
		printf("[case %d]\n", c);
		rv = dd_strchr(mem, c);
		if (rv == 0)
			printf("not found\n");
		else
			printf("ptr_diff: %zu\n", rv - mem);
		c += 1;
	}

	return (0);
}
