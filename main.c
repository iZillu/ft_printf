#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = "123";
	ft_printf("oh %  +    i %C %S %s easy\n", 15 + 5, L'П', L"😎😎😎😎", str);
	printf("oh % +   i %C %S %s easy\n", 15 + 5, L'П', L"😎😎😎😎", str);
	return (0);
}
