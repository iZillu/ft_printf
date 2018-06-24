#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = "123";
	ft_printf("Hello world! %C %S %s %D %o %u %X easy\n", L'П', L"😎😎😎😎", str, 2147483647, 164, 12, 57);
	printf("Hello world! %C %S %s %D %o %u %X easy\n", L'П', L"😎😎😎😎", str, 2147483647, 164, 12, 57);
	return (0);
}
