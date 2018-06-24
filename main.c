#include <stdio.h>

int	ft_printf(const char * restrict format, ...);

int	main()
{
	ft_printf("Hello world! %i%s%% easy\n", 15, "");
	   printf("Hello world! %i%s%% easy\n", 15, "");
	return (0);
}