#include "h.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	for(int i = -1000; i <= +1000; i += 1)
	{
		printf("%d", dd_isascii(i));
	}
	printf("\n");
	return (0);
}