/*
    ʱ�䣺2016��2��2��21:10:01
	Ŀ�ģ��ݹ���׳ˡ� 
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
	
	printf("��������Ҫ�󼸵Ľ׳ˣ�");
	scanf("%d", &val);
	
	printf("%d�Ľ׳���%d��", val, JieCheng(val));
	
	
	
	return 0;
} 
/*
***************���***************
��������Ҫ�󼸵Ľ׳ˣ�5
5�Ľ׳���120�� 
*/
