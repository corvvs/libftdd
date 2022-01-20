#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 33);
	char *str = (char *)malloc(n * sizeof(char));

	printf("[case 1: memset(*, '\\0', 100)]\n");
	dd_memset(str, '\0', 100);
	printf("%s\n", str);

	printf("[case 2: memset(*, 'A', 0)]\n");
	dd_memset(str, 'A', 0);
	printf("%s\n", str);

	printf("[case 3: memset(*, 'A', 1)]\n");
	dd_memset(str, 'A', 1);
	printf("%s\n", str);

	printf("[case 4: memset(*, 'B', 10)]\n");
	dd_memset(str, 'B', 10);
	printf("%s\n", str);

	printf("[case 5: memset(*, 'C', 4)]\n");
	dd_memset(str, 'C', 4);
	printf("%s\n", str);

	printf("[case 6: memset(*, 'C', INT_MAX + 2)]\n");
	dd_memset(str, 'X', (1ull << 31) - 1 + 2);
	printf("'%c'\n", str[(1ull << 31) - 1 + 1]);

	printf("[case 7: memset(*, INT_MAX, 10)]\n");
	dd_memset(str, INT32_MAX, 10);
	write(STDOUT_FILENO, str, 10);
	printf("\n");

	printf("[case 8: memset(*, INT_MIN, 10)]\n");
	dd_memset(str, INT32_MIN, 10);
	write(STDOUT_FILENO, str, 10);
	printf("\n");

	free(str);
	return (0);
}
