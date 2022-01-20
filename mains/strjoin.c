#include "h.h"

int	work(
	const char *name,
	char *s1, char *s2,
	const char *expected
)
{
	printf("[case: %s]\n", name);
	char	*joined = dd_strjoin(s1, s2);

	if (!joined && !expected)
	{
		printf("ok - null is expected\n");
		return (0);
	}
	else if (!joined && expected)
	{
		printf("KO - unexpected null has been returned\n");
		return (1);
	}
	else if (joined && !expected)
	{
		printf("KO - unexpected non-null has been returned: \"%s\"\n", joined);
		return (1);
	}
	else
	{
		if (strcmp(joined, expected) == 0)
		{
			printf("ok - \"%s\"\n", joined);
			return (0);
		}
		else
		{
			printf("KO - detected diff:\njoined:   \"%s\"\nexpected: \"%s\"\n", joined, expected);
			return (1);
		}
	}
}

#define S1 "musashi-"
#define S2 "kosugi"
#define S3 "koyama"
#define S4 "koganei"
#define S5 "maru"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	char	*str1 = strdup(S1);
	char	*str2 = strdup(S2);
	char	*str3 = strdup(S3);
	char	*str4 = strdup(S4);
	char	*str5 = strdup(S5);
	int		es = 0;

	es = es | work("\"\" and \"\" (non-destructive check)",
		"", "",
		"");
	es = es | work(
		"\"\" and str1",
		"", str1,
		S1);
	es = es | work(
		"str1 and \"\"",
		str1, "",
		S1);
	es = es | work(
		"str1 and str1",
		str1, str1,
		S1 S1);
	es = es | work(
		"str1 and str2",
		str1, str2,
		S1 S2);
	es = es | work(
		"str1 and str3",
		str1, str3,
		S1 S3);
	es = es | work(
		"str5 and str5",
		str5, str5,
		S5 S5);
	es = es | work(
		"NULL and NULL",
		NULL, NULL,
		NULL);
	es = es | work(
		"str1 and NULL",
		NULL, str1,
		NULL);
	es = es | work(
		"NULL and str1",
		str1, NULL,
		NULL);

	return (es);
}
