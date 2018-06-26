#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = NULL;
	ft_printf("oh it's %s easy\n", NULL);
       printf("oh it's %s easy\n", NULL);
	return (0);
}
