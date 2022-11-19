
#include "ft_printf.h"
int main()
{
	fclose(stdout);
	fprintf(stderr, "%d", ft_printf("hello world"));
}
