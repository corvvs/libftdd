#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 33);
	char *str = (char *)malloc(n * sizeof(char));

	printf("[case 1: len = 0]\n");
	str[0] = '\0';
	printf("%zu\n", dd_strlen(str));

	printf("[case 2: len = 1]\n");
	str[0] = 'a';
	str[1] = '\0';
	printf("%zu\n", dd_strlen(str));

	printf("[case 3: len = INT_MAX]\n");
	memset(str, 'x', INT32_MAX);
	str[INT32_MAX] = '\0';
	printf("%zu\n", dd_strlen(str));

	printf("[case 4: len = INT_MAX + 1]\n");
	str[INT32_MAX] = 'y';
	str[(size_t)INT32_MAX + 1] = '\0';
	printf("%zu\n", dd_strlen(str));

	printf("[case 5: len = INT_MAX + 1007]\n");
	memset(str + INT32_MAX, 'z', 1007);
	str[(size_t)INT32_MAX + 1007] = '\0';
	printf("%zu\n", dd_strlen(str));

	return (0);
}
