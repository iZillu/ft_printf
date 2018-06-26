#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	char	*str;

	str = NULL;
	ft_printf("oh it's %s %s %s easy\n", NULL, str, "alk;hsdk lhuli1u2je kl;jasdlkj al;j");
       printf("oh it's %s %s %s easy\n", NULL, str, "alk;hsdk lhuli1u2je kl;jasdlkj al;j");
	return (0);
}
