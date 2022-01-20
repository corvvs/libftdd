#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 33);
	const char	*str1 = "hello";
	const char	*str2 = "willpower";

	printf("[case 1: memcmp(\"hello\", \"willpower\", 0); // should return 0. ]\n");
	printf("%d\n", dd_memcmp(str1, str2, 0));

	printf("[case 2: memcmp(\"hello\", \"willpower\", 1)]\n");
	printf("%d\n", dd_memcmp(str1, str2, 1));

	printf("[case 3: memcmp(\"hello\", \"willpower\", INT_MAX)]\n");
	printf("%d\n", dd_memcmp(str1, str2, INT32_MAX));

	printf("[case 4: memcmp(\"hello\", \"willpower\", INT_MAX + 1)]\n");
	printf("%d\n", dd_memcmp(str1, str2, (size_t)INT32_MAX + 1));

	printf("[case 5: memcmp(\"hello\", \"willpower\", UINT_MAX)]\n");
	printf("%d\n", dd_memcmp(str1, str2, UINT32_MAX));

	printf("[case 6: memcmp(\"hello\", \"willpower\", UINT_MAX + 1); // should NOT return 0.]\n");
	printf("%d\n", dd_memcmp(str1, str2, (size_t)UINT32_MAX + 1));

	printf("[case 7: memcmp(\"hello\" + 2, \"willpower\" + 2, 2)]\n");
	printf("%d\n", dd_memcmp(str1 + 2, str2 + 2, 2));

	printf("[case 8: memcmp(\"hello\" + 2, \"willpower\" + 2, 10)]\n");
	printf("%d\n", dd_memcmp(str1 + 2, str2 + 2, 10));

	char	*null1 = calloc(10, sizeof(char));
	char	*null2 = calloc(10, sizeof(char));
	null1[7] = '1';
	null2[7] = '2';

	printf("[case 9: memcmp(null1, null2, 1))]\n");
	printf("%d\n", dd_memcmp(null1, null2, 1));

	printf("[case 10: memcmp(null1, null2, 7))]\n");
	printf("%d\n", dd_memcmp(null1, null2, 7));

	printf("[case 11: memcmp(null1, null2, 8)); // should NOT return 0.]\n");
	printf("%d\n", dd_memcmp(null1, null2, 8));

	printf("[case 12: memcmp(null1, null2, 9)); // should NOT return 0.]\n");
	printf("%d\n", dd_memcmp(null1, null2, 9));
	return (0);
}
