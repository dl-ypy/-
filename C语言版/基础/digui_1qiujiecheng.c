/*
   2015��12��6��10:41:01
   Ŀ�ģ���׳� 
*/ 
#include <stdio.h>

long f(long n)
{
	if (1 == n)
	    return 1;
    else
        return f(n-1) * n;//n-1�Ľ׳��ٳ���n������n�Ľ׳� 
}

int main(void)
{
	int val, i, mult;
	
	//�ǵݹ��㷨 
	printf("������һ�����֣�");
	printf("val = ");
	scanf("%d", &val);
	
	for (i=1; i<=val; i++)
	{
		mult = mult * i;
	}
	
	printf("%d�Ľ׳���%d\n", val, mult);
	
	//�ݹ��㷨 
	printf("������һ�����֣�");
	scanf("%ld", &val);
	printf("%ld", f(val)); 
	
	return 0;
}
/*
***************���**************
������һ�����֣�val = 5
5�Ľ׳���120
������һ�����֣�5
120
--------------------------------
Process exited after 6.41 seconds with return value 0
�밴���������. . .
*/ 
