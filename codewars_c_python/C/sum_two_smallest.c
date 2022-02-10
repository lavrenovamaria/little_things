#include <stdio.h>

long sum_two_smallest_numbers(size_t n, const int numbers[n]) 
{
	size_t i = 0;
	int y = 0;
	long min = numbers[i];
	long min2 = numbers[i + 1];

	i = -1;
	while (++i < n)
	if (min > numbers[i])
	{
		min2 = min;
		y = i;
		min = numbers[i];
	}
	i = -1;
	while (++i < n)
	if (min2 > numbers[i] && i != y)
	min2 = numbers[i];
	return(min + min2); 
}

int main(int argc, char **argv)
{

	int  balance[5] = {19, 5, 42, 2, 77};
	printf("%ld", sum_two_smallest_numbers(5, balance));
	return 0;
}
