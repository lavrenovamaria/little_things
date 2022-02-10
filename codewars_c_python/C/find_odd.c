#include <stddef.h>
#include <limits.h>
#include <stdio.h>

int find_odd(size_t length, const int array[length])
{
	int j, i, count = 0;
    for (int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
			if(array[i] == array[j])
				count++;
	}	
    return count;
}

int main(int argc, char **argv)
{

	// int  odd[17] = {20, 1, -1, 2, 2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, 2, 5 };
	int  odd[] = {0, 1, 0, 1, 0};
	printf("%d\n", find_odd(5, odd));
	return 0;
}
