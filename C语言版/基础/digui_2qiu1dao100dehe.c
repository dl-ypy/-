/*
    2015年12月6日10:56:53
	目的：求1+2+3+……+100的和 
*/ 
#include <stdio.h>

long sum(int n)
{
	if (1 == n)
	    return 1;
    else
        return sum(n-1) + n;
}

int main(void)
{
	printf("%ld", sum(100));
	
	return 0;
}
/*
***************结果***************
5050
--------------------------------
Process exited after 0.04881 seconds with return value 0
请按任意键继续. . . 
*/
