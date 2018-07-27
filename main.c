#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	wchar_t	*str;
	int k;

	k = 922323;
	str = L"фывфывфыв ";
	printf("LEN IS %i\n", ft_printf("str is %x xD\n", 4294967296));
    printf("LEN IS %i\n",    printf("str is %x xD\n", 4294967296));
	return (0);
}
