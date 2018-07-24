#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;
	int k;

	k = -922323;
	str = "123456789";
	printf("LEN IS %i\n", ft_printf("str is %.7i xD\n", k));
    printf("LEN IS %i\n",    printf("str is %.7i xD\n", k));
	return (0);
}
