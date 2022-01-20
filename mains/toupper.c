#include "h.h"

void	work(int c)
{
	printf("[case %d]\n", c);
	int rc = dd_toupper(c);
	printf("(%s) %d('%c') -> %d('%c')\n",
		c == rc ? "same" : "CHANGED",
		c, c, rc, rc);
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int i = -1000;
	while (i <= 1000)
	{
		work(i);
		i += 1;
	}
	work(INT_MAX);
	work(INT_MAX - 1);
	work(INT_MAX - 2);
	work(INT_MIN);
	work(INT_MIN + 1);
	work(INT_MIN + 2);
	return (0);
}
