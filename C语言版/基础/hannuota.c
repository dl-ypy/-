/*
    2015年12月7日16:19:22
	目的：汉诺塔的实现 
*/ 
#include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
	/*
	    如果是一个盘子
		    直接将A柱子上的盘子从A移到C
		否则
		    先将A柱子上的n-1个盘子借助C移到B
			直接将A柱子上的盘子从A移到C
			最后将B柱子上的n-1个盘子 借助A移到C 
	*/
	if (1 == n)
	{
	    printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
    }
    else
    {
    	hannuota(n-1, A, C, B);
    	printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
    	hannuota(n-1, B, A, C);
	}
}

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	
	printf("请输入要移动的盘子的个数：");
	scanf("%d", &n);
	
	hannuota(n, 'A', 'B', 'C'); 
	
	return 0;
}
/*
***************结果***************
请输入要移动的盘子的个数：3
将编号为1的盘子直接从A柱子移到C柱子
将编号为2的盘子直接从A柱子移到B柱子
将编号为1的盘子直接从C柱子移到B柱子
将编号为3的盘子直接从A柱子移到C柱子
将编号为1的盘子直接从B柱子移到A柱子
将编号为2的盘子直接从B柱子移到C柱子
将编号为1的盘子直接从A柱子移到C柱子

--------------------------------
Process exited after 7.013 seconds with return value 0
请按任意键继续. . . 
*/
