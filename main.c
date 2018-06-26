#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = NULL;
	ft_printf("oh it's %o easy\n", -11);
       printf("oh it's %o easy\n", -11);
	return (0);
}
