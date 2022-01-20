#include "h.h"

#define S1 "musashi-kosugi"
#define S2 "musashi-koyama"
#define S3 "shin-maruko"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	const size_t	n = (1ull << 33);
	const char		*str1 = S1;
	const char		*str2 = S2;
	const char		*str3 = S3;
	const char		*str4 = strdup(S1);

	printf("[case 1: strncmp(\"" S1 "\", \"" S3 "\", 10) ]\n");
	printf("%d\n", dd_strncmp(str1, str3, 10));

	printf("[case 2: strncmp(\"" S1 "\", \"" S3 "\", 0) ]\n");
	printf("%d\n", dd_strncmp(str1, str3, 0));

	printf("[case 3: strncmp(\"" S1 "\", \"" S2 "\", 0) ]\n");
	printf("%d\n", dd_strncmp(str1, str2, 0));

	printf("[case 4: strncmp(\"" S1 "\", \"" S2 "\", 1) ]\n");
	printf("%d\n", dd_strncmp(str1, str2, 1));

	printf("[case 5: strncmp(\"" S1 "\", \"" S2 "\", 10) ]\n");
	printf("%d\n", dd_strncmp(str1, str2, 10));

	printf("[case 6: strncmp(\"" S1 "\", \"" S2 "\", UINT_MAX) ]\n");
	printf("%d\n", dd_strncmp(str1, str2, UINT_MAX));

	printf("[case 7: strncmp(\"" S1 "\", \"" S2 "\", UINT_MAX + 1) ]\n");
	printf("%d\n", dd_strncmp(str1, str2, (size_t)UINT_MAX + 1));

	printf("[case 8: strncmp(\"" S1 "\", \"" S1 "\", SIZE_MAX) ]\n");
	printf("%d\n", dd_strncmp(str1, str1, SIZE_MAX));

	printf("[case 9: strncmp(\"" S1 "\", \"" S1 "\"(copied), SIZE_MAX) ]\n");
	printf("%d\n", dd_strncmp(str1, str4, SIZE_MAX));

	return (0);
}
