/*
    2015年11月18日10:35:52
	目的：实现一个数组的各种功能。 
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>   //exit需要 
#include <stdbool.h> // bool类型需要 

struct Arr
{
	int * pBase;  //数组第一个元素的地址
	int len;
	int cnt;    // 当前有效元素的个数 
};

void init_arr(struct Arr *pArr,int length)//    创建    形参必须是指针 
{
	//(*pArr).len = 99;          //*pArr代表main函数中的arr 
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败！");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
} 

bool is_empty(struct Arr * pArr)//   判断数组是否为空
{
	if (0 == pArr->cnt)
	    return true;
    else
        return false;
} 

bool is_full(struct Arr * pArr)//   判断是否满 
{
	if (pArr->cnt == pArr->len)
	    return true;
	else
	    return false;
} 

bool append_arr(struct Arr * pArr, int val) //   追加   在末尾加元素
{
     if (is_full(pArr))
         return false;//如果满的话返回false
     //不满时追加
	 pArr->pBase[pArr->cnt] = val;
	 (pArr->cnt)++;
	 return true; 
} 

bool insert_arr(struct Arr * pArr, int pos, int val)   //   插入     表示在第pos个位置前插入val元素 
                                                    //  pos表示位置  从1开始 
{
	int i;
	
	if (is_full(pArr))
	    return false;
	
	if (pos<1 || pos>pArr->cnt+1)
	    return false;
	
	for (i=pArr->cnt-1; i>= pos-1; i--)//从后往前找
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;      //不写这一步的话有效值的个数就不变 
	return true;
	
}

bool delete_arr(struct Arr * pArr, int pos, int * pVal)//      删除 
{
	int i;
	
	if (is_empty(pArr))
	    return false;
	    
    if (pos<1 || pos>pArr->cnt)
        return false;
    *pVal = pArr->pBase[pos-1];
	for (i=pos; i<pArr->cnt; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}     
}

void inversion_arr(struct Arr * pArr)//     倒置 
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return;
}

void sort_arr(struct Arr * pArr)//          排序
{
	int i,j,t;
	
	for (i=0; i<pArr->cnt; i++)
	{
		for (j=i+1; j<pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
} 

void show_arr(struct Arr * pArr)
{
	int i;
	
	if (is_empty(pArr))//  括号里不能加& ，因为main函数中的&pArr已经赋给show_arr函数中的pArr,所以再用&pArr时就用pArr表示 
	{
		printf("数组为空！\n");
    }
	else
	{
		for (i=0; i<pArr->cnt; i++)
		{
			printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	 } 
}

int main(void)
{
	struct Arr arr;
	int val,n,i,m;
	
	printf("您要创建的数组长度为多少：\n");
	scanf("%d", &n);
	init_arr(&arr,n);
	
	printf("请输入您要追加元素的个数：\n");
	scanf("%d", &n);
	
	for (i=0; i<n; i++)
	{
		printf("请输入您要输入的第%d个元素（一个）：\n", i+1);
		scanf("%d",&m);
		append_arr(&arr, m);
	}
	printf("追加后的元素为：\n");
	show_arr(&arr);
	
	printf("请输入您要插入的位置和元素：\n");
	scanf("%d%d", &m,&n);
	insert_arr(&arr,m,n);
	printf("插入元素后为：\n");
	show_arr(&arr);
	
	inversion_arr(&arr);
	printf("倒置后为：\n");
	show_arr(&arr);
	
	sort_arr(&arr);
	printf("升序排列后为：\n");
	show_arr(&arr);
	
	printf("请输入您要删除第几个元素：\n");
	scanf("%d", &n);
	if (delete_arr(&arr, n, &val))
    {
    	printf("删除成功！\n"); 
    	printf("您删除的元素是：%d\n", val); 
	}
	else
	{
		printf("删除失败！");
	}
	return 0;
} 
/*
***************结果***************
您要创建的数组长度为多少：
5
请输入您要追加元素的个数：
3
请输入您要输入的第1个元素（一个）：
9
请输入您要输入的第2个元素（一个）：
5
请输入您要输入的第3个元素（一个）：
1
追加后的元素为：
9 5 1
请输入您要插入的位置和元素：
1 0
插入元素后为：
0 9 5 1
倒置后为：
1 5 9 0
升序排列后为：
0 1 5 9
请输入您要删除第几个元素：
4
删除成功！
您删除的元素是：9

--------------------------------
Process exited after 32.04 seconds with return value 0
请按任意键继续. . .
*/
