#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;
	int k;

	k = 922323;
	str = "123456789";
	printf("LEN IS %i\n", ft_printf("str is %s xD\n", "ASDFGH"));
    printf("LEN IS %i\n",    printf("str is %8s xD\n", "ASDFGH"));
	return (0);
}
