/*
    2015��12��13��20:07:47
	Ŀ�ģ����������ʵ�� 
*/ 
#include <stdio.h>

int FindPos(int *, int, int);
void QuickSort(int *, int, int);

int main(void)
{
	int a[6] = {2, 1, 0, 5, 4, 3};
	int i;
	//printf("gvbufevni");
	
	QuickSort(a, 0, 5);//�ڶ���������ʾ��һ��Ԫ�ص��±꣬ ������������ʾ���һ��Ԫ�ص��±�
	 
	for (i=0; i<6; i++)
	{
		printf("%d ", a[i]);
    } 
    printf("\n");
	
	return 0;
}

void QuickSort(int * a, int low, int high)
{
	int pos;
	
	if (low < high)
	{
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);//pos��ǰһ�� 
		QuickSort(a, pos+1, high);//pos�ĺ�һ�� 
	}
}

int FindPos(int * a, int low, int high)
{
	int val = a[low];
	
	while (low < high)
	{
		while (low < high && a[high]>=val)//�������������������������������������������� 
		    high--;
        a[low] = a[high];
        
        while (low < high && a[low]<=val)
            low++;
        a[high] = a[low];
	}
	a[low] = val;
	
	return low;
} 
/*
***************���***************
0 1 2 3 4 5

--------------------------------
Process exited after 0.0413 seconds with return value 0
�밴���������. . . 
*/
