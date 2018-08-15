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
	printf("LEN IS %i\n", ft_printf("%C vs %C  xD\n", str, "ha-ha-ha"));
	printf("LEN IS %i\n",    printf("%C vs %C  xD\n", str, "ha-ha-ha"));
	return (0);
}
