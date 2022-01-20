#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 32) + 1000;
	char	*buf1 = calloc(n, sizeof(char));
	char	*buf2 = calloc(n, sizeof(char));

	strcpy(buf2, "musashi-koganei");

	printf("[case 0: initial buf1 and buf2)]\n");
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 1: memcpy(buf1, buf2, 0))]\n");
	dd_memcpy(buf1, buf2, 0);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 2: memcpy(buf1, buf2, 10))]\n");
	dd_memcpy(buf1, buf2, 10);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 3: memcpy(buf1, buf2, strlen(buf2)))]\n");
	dd_memcpy(buf1, buf2, strlen(buf2));
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 4: koganei-koganei]\n");
	dd_memcpy(buf1, buf1 + 8, 7);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 5: memcpy(buf2, buf2, SIZE_MAX)]\n");
	dd_memcpy(buf2, buf2, SIZE_MAX);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 6: memcpy(buf1, buf2, 0)]\n");
	dd_memcpy(buf2, buf2, 0);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 7: overwrapping - left to right]\n");
	memcpy(buf1, buf2, strlen(buf2) + 1);
	dd_memcpy(buf1 + 5, buf1, 10);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("[case 8: overwrapping - right to left]\n");
	memcpy(buf1, buf2, strlen(buf2) + 1);
	dd_memcpy(buf1, buf1 + 5, 10);
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);

	buf2[n - 10] = 'X';
	printf("[case 9: very long]\n");
	dd_memcpy(buf1, buf2, n);
	printf("buf1[%zu]: '%c'\n", n - 10, buf1[n - 10]);
	printf("buf2[%zu]: '%c'\n", n - 10, buf2[n - 10]);
	return (0);
}
