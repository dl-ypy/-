/*
    ʱ�䣺2016��1��30��20:03:22
	Ŀ�ģ����ŵ���ϰ��
*/
#include <stdio.h>

int FindPos(int * Arr, int low, int high)
{
	int val = Arr[low];
	
	while (low < high)
	{
		while (low <high && Arr[high]>=val)
		{
			high--;
			Arr[low] = Arr[high];
		}
		while (low<high && Arr[low]<=val)
		{
			low++;
			Arr[high] = Arr[low];
		}
	}

	Arr[low] = val;

	return low;
}

void QuickSort(int * Arr, int low, int high)
{
	int pos = FindPos(Arr, low, high);

	if (low < high)
	{ 
        QuickSort(Arr, low, pos-1);
	    QuickSort(Arr, pos+1, high);
	}
}

int main(void)
{
	int a[5] = {5, 9, 20, 3, 1};
	int i;

	QuickSort(a, 0, 5);

	printf("��������������£�");

	for (i=0; i<5; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}
/*
***************���***************
��������������£�1 3 5 9 20
*/
