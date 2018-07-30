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
	printf("LEN IS %i\n", ft_printf("@moulitest:%#0x %#xD\n", 12, 12));
    printf("LEN IS %i\n",    printf("@moulitest:%#0x %#xD\n", 12, 12));
	return (0);
}
