#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = "123456789";
	ft_printf("LEN IS %i\n", ft_printf("str is %u\n", 148956));
       printf("LEN IS %i\n", printf("str is %u\n", 148956));
	return (0);
}
