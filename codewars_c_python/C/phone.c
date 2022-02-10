#include <stdio.h>
#include <stdlib.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
	int i = 0;
	int y = 0;

	while (i < 10)
	{
		phnum[0] = '(';
		phnum[4] = ')';
		phnum[5] = ' ';
		phnum[9] = '-';
	if (y == 0 || y == 4 || y == 5 || y == 9)
		y++;
	else
		phnum[y++] = nums[i++] + 48;
	}
	return(phnum);
}

int main(int argc, char **argv)
{
	char *phnum;

	phnum = malloc(15);
	printf("%s", create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0}));
	return (0);
}
