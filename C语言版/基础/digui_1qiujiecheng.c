/*
   2015年12月6日10:41:01
   目的：求阶乘 
*/ 
#include <stdio.h>

long f(long n)
{
	if (1 == n)
	    return 1;
    else
        return f(n-1) * n;//n-1的阶乘再乘以n，就是n的阶乘 
}

int main(void)
{
	int val, i, mult;
	
	//非递归算法 
	printf("请输入一个数字：");
	printf("val = ");
	scanf("%d", &val);
	
	for (i=1; i<=val; i++)
	{
		mult = mult * i;
	}
	
	printf("%d的阶乘是%d\n", val, mult);
	
	//递归算法 
	printf("请输入一个数字：");
	scanf("%ld", &val);
	printf("%ld", f(val)); 
	
	return 0;
}
/*
***************结果**************
请输入一个数字：val = 5
5的阶乘是120
请输入一个数字：5
120
--------------------------------
Process exited after 6.41 seconds with return value 0
请按任意键继续. . .
*/ 
