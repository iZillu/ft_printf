#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>
#include <limits.h>
#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;
	int 	k;

	k = 922323;
	str = "asdasd";
	printf("LEN IS %i\n", ft_printf("%S\n", L"øøøøø"));
    printf("LEN IS %i\n",    printf("%S\n", L"øøøøø"));
	return (0);
}
