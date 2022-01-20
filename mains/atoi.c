#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	size_t	n = (size_t)INT32_MAX + 10;
	char	*lstr = malloc(n * sizeof(char));
	memset(lstr, '0', n);
	lstr[n] = '\0';
	char	*imax = "2147483647";
	memcpy(lstr + n - strlen(imax), imax, strlen(imax));
	char *strs[] = {
		"",
		"+",
		"-",
		"0",
		"+0",
		"-0",
		"+-1",
		"111",
		"123",
		"-123",
		"--123",
		(char []){23, '1', '\0'},
		(char []){'1', 23, '\0'},
		(char []){1, '1', '\0'},
		(char []){2, '1', '\0'},
		(char []){3, '1', '\0'},
		(char []){4, '1', '\0'},
		(char []){5, '1', '\0'},
		(char []){6, '1', '\0'},
		(char []){7, '1', '\0'},
		(char []){8, '1', '\0'},
		(char []){9, '1', '\0'},
		(char []){10, '1', '\0'},
		(char []){11, '1', '\0'},
		(char []){12, '1', '\0'},
		(char []){13, '1', '\0'},
		(char []){250, '1', '\0'},
		(char []){255, '1', '\0'},
		"0+100",
		"0-100",
		"00100",
		"00000000000100",
		"2147483647",
		"02147483647",
		"+2147483647",
		"2147483648",
		"+2147483648",
		"-2147483648",
		"-2147483649",
		"100000000",
		"-100000000",
		"100010000",
		"-100010001",
		"1 2",
		NULL,
	};
	size_t	i = 0;
	while (strs[i])
	{
		printf("[case %zu: \"%s\"]\n", i + 1, strs[i]);
		printf("%d\n", dd_atoi(strs[i]));
		i += 1;
	}
	printf("[special case 1: very long intmax]\n");
	printf("%d\n", dd_atoi(lstr));

	return (0);
}
