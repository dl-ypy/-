/*
    2015年12月13日20:07:47
	目的：快速排序的实现 
*/ 
#include <stdio.h>

int FindPos(int *, int, int);
void QuickSort(int *, int, int);

int main(void)
{
	int a[6] = {2, 1, 0, 5, 4, 3};
	int i;
	//printf("gvbufevni");
	
	QuickSort(a, 0, 5);//第二个参数表示第一个元素的下标， 第三个参数表示最后一个元素的下标
	 
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
		QuickSort(a, low, pos-1);//pos的前一半 
		QuickSort(a, pos+1, high);//pos的后一半 
	}
}

int FindPos(int * a, int low, int high)
{
	int val = a[low];
	
	while (low < high)
	{
		while (low < high && a[high]>=val)//？？？？？？？？？？？？？？？？？？？？？？ 
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
***************结果***************
0 1 2 3 4 5

--------------------------------
Process exited after 0.0413 seconds with return value 0
请按任意键继续. . . 
*/
