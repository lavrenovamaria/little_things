#include <stdio.h>

int ft_atoi(char *str)
{
	int res;
	res = 0;
	int i;
	i = 1;

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * i);
}

int ft_strlen(char *str)
{
	int i;
	i = 0;
	int j;

	while(str[i] != '\0')
		i++;
	return(i);
}

int digital_root(char *str)
{
	int n;
	int m;
	m = ft_strlen(str);
	n = ft_atoi(str);
	char str_1[] = 
	
	while(--m > 1)
	{
		printf("%d", n);
	}
	return 0;
}

int main(int argc, char **argv)
{
	char str[] = "942";
	int result = digital_root(str);
	//printf("The length of the string is %d.\n", result);
	return 0;
}
