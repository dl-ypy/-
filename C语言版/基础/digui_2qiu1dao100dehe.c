/*
    2015��12��6��10:56:53
	Ŀ�ģ���1+2+3+����+100�ĺ� 
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
***************���***************
5050
--------------------------------
Process exited after 0.04881 seconds with return value 0
�밴���������. . . 
*/
