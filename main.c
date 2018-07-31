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
	printf("LEN IS %i\n", ft_printf("%U AND %u\n", 4429496729, 4294967296));
    printf("LEN IS %i\n",    printf("%U AND %u\n", 4429496729, 4294967296));
	return (0);
}
