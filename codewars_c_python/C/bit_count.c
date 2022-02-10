#include <stddef.h>
#include <stdio.h>

size_t countBits(unsigned value)
{
	size_t counter = 0;
	while(value)
	{
		if ((value >> counter) & 1)
			counter++;
		else
			value=value>>1;
	}
	return counter;
}

int main(int argc, char **argv)
{

	// int  odd[17] = {20, 1, -1, 2, 2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, 2, 5 };
	int  odd = 10;
	printf("%ld\n", countBits(odd));
	return 0;
}