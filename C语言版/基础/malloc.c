/*
    2015��11��16��20:11:55
	Ŀ�ģ���̬�����ڴ档 
*/ 
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int len;
	int a[5] = {1, 2, 3, 4, 5};
	
	printf("����������ĳ��ȣ�len = ");
	scanf("%d", &len);
	
	int *p = (int *)malloc(sizeof(int)*len);//ǰ�������е�int * ��ǿ��ת����int�ͣ���Ϊmalloc����ֻ�ܷ��ص�һ���ֽڵ�ַ���������������͵ĵ�һ���ֽڵ�ַ��һ����������Ҫ���߱����� 
	*p = 1;//      �ȼ���a[0] = 1;
	p[1] = 2;
	p[len] = 100;
	
	printf("*p = %d, a[0] = %d, p[%d] = %d\n", *p,a[0],len,p[len]);
	
	free(p);   //     �ͷſռ�   ����д��*p 
	 
	return 0;
}
/*
***************���***************
����������ĳ��ȣ�len = 5
*p = 1, a[0] = 1, p[5] = 100

--------------------------------
Process exited after 4.134 seconds with return value 0
�밴���������. . .
*/
