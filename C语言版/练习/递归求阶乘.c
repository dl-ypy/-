/*
    时间：2016年2月2日21:10:01
	目的：递归求阶乘。 
*/
#include <stdio.h>

int JieCheng(int val)
{
	if (1 == val)
	    return 1;
    else
        return JieCheng(val-1) * val;
}

int main(void)
{
	int val;
	
	printf("请输入您要求几的阶乘：");
	scanf("%d", &val);
	
	printf("%d的阶乘是%d。", val, JieCheng(val));
	
	
	
	return 0;
} 
/*
***************结果***************
请输入您要求几的阶乘：5
5的阶乘是120。 
*/
