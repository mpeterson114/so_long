#include <stdio.h>
#include <stdlib.h>

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main()
{
    int trgb = 0;

    printf("%d\n", get_r(trgb));
    return 0;
}