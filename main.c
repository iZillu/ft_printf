#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>
#include <limits.h>
#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	wchar_t	*str;
	int k;

	k = 922323;
	str = L"фывфывфыв ";
	printf("LEN IS %i\n", ft_printf("% 4.2i\n", 1234));
    printf("LEN IS %i\n",    printf("% 4.2i\n", 1234));
	return (0);
}
