/*
    2015年11月16日20:11:55
	目的：动态分配内存。 
*/ 
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int len;
	int a[5] = {1, 2, 3, 4, 5};
	
	printf("请输入数组的长度：len = ");
	scanf("%d", &len);
	
	int *p = (int *)malloc(sizeof(int)*len);//前面括号中的int * 是强制转换成int型，因为malloc函数只能返回第一个字节地址，而所有数据类型的第一个字节地址都一样，这里是要告诉编译器 
	*p = 1;//      等价于a[0] = 1;
	p[1] = 2;
	p[len] = 100;
	
	printf("*p = %d, a[0] = %d, p[%d] = %d\n", *p,a[0],len,p[len]);
	
	free(p);   //     释放空间   不能写成*p 
	 
	return 0;
}
/*
***************结果***************
请输入数组的长度：len = 5
*p = 1, a[0] = 1, p[5] = 100

--------------------------------
Process exited after 4.134 seconds with return value 0
请按任意键继续. . .
*/
