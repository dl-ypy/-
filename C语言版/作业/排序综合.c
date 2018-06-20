#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>//  exit头文件 
#include <stdbool.h>// bool头文件 
#include <time.h>//  检测运行时间的clock函数的头文件 

typedef int Status;

typedef struct List
{
	int * pBase;// 第一个元素地址 ,必须用指针，因为只有指针能跨函数调用
	int length;
	int cnt;//  有效元素的数量 
}SqList;

void CreateList(SqList * L, int n)//L也必须是指针 
{
	int i;
	int val;
	L->pBase = (int *)malloc(sizeof(int) * n);
	
	if (NULL == L->pBase)
	{
		printf("分配内存失败，程序终止！");
		exit(-1);
	}
	
	L->length = n;
	L->cnt = 0;
	
	for (i=1; i<=L->length; i++)
	{
		printf("请输入第%d个整数：", i);
		scanf("%d", &val);
		L->pBase[L->cnt] = val;
		(L->cnt)++;
	}

}

Status traverse(SqList * L)
{
	int i;
	
	for (i=0; i<L->cnt; i++)
	{
		printf("%d ", L->pBase[i]);
	}
	printf("\n");
}

Status Find(SqList * L, int i)//     用来返回输出时的值，保存文件时会用到 
{
	return L->pBase[i];
}

double sort_1(SqList * L)//   选择排序      4.2s
{
	int i, j, t;

	for (i=0; i<(L->cnt)-1; i++)   //  只需要比较长度减一次 
	{
		for (j=i+1; j<L->cnt; j++)//   每次比较都是第i个和第i+1,i+2...个进行比较 
		{
			if (L->pBase[i] > L->pBase[j])
			{
				t = L->pBase[i];
				L->pBase[i] = L->pBase[j];
				L->pBase[j] = t;
			}
		}
	}
	
}

void sort_2(SqList * L)//   起泡排序       3.558s
{
	int i, j, t;
	
	for (i=0; i<(L->cnt)-1; i++)//    比较长度减一次
	{
		for (j=0; j<(L->cnt)-i-1; j++)   //如序列3， 2， 1， 5， 8   第一次比较3和2，3>2, 3和2互换，再比较3和1，如此类推，一次比较完后，最大的在最后 
		{                                //第一次比较完后，比较下一次，最大的那个数就不再参与比较，所以比较的次数为  长度减一再减去第一次比较完的 
			if (L->pBase[j] > L->pBase[j+1])
			{
				t = L->pBase[j];
				L->pBase[j] = L->pBase[j+1];
				L->pBase[j+1] = t;
			}
	    } 
    } 
}

Status Findhigh(SqList * L)//   用于返回序列的最后一个值的位置，快速排序需要 
{
	return L->cnt-1;
}

Status FindPos(SqList * L, int low, int high)
{
	int val = L->pBase[low];
	
	while (low < high)
	{
		while (low < high && L->pBase[high]>=val)
		    high--;
        L->pBase[low] = L->pBase[high];
        
        while (low < high && L->pBase[low]<=val)
            low++;
        L->pBase[high] = L->pBase[low];
	}
	
	L->pBase[low] = val;
	
	return low;
}

void sort_3(SqList * L, int low, int high)//    快速排序      3.453s
{
	int pos;
	
	if (low < high)
	{
		pos = FindPos(L, low, high);
		sort_3(L, low, pos-1);//pos的前一半 
		sort_3(L, pos+1, high);//pos的后一半 
	}
}

int main(void)
{
	SqList L;
	int n, m;
	int i;
	int start, finish;
	bool flag = true;
	
	FILE * fp;
	char a[200]; 
	
	while (flag = true)
	{
		printf("\n\n");
		printf("            欢迎进入排序综合系统！\n");
		printf("**********************************************\n");
		printf("               1.创建一个序列\n");
		printf("               2.查看序列\n");
		printf("               3.选择排序\n");
		printf("               4.起泡排序\n");
		printf("               5.快速排序\n");
		//printf("               6.检测各排序方法运行时间\n");
		printf("               6.退出程序\n");
		printf("**********************************************\n");
		
		printf("请根据您的需要输入要执行操作的序号：");
		scanf("%d", &m);
		printf("\n");
		
		switch (m)
		{
			case 1:printf("请输入您的序列长度：");
			       scanf("%d", &n);
			       CreateList(&L, n);
			       printf("此操作结束，请进行其他操作！"); 
                   printf("\n\n");
			       break;
            case 2:printf("您的序列为：\n");
			       traverse(&L);
			       printf("此操作结束，请进行其他操作！");
			       printf("\n\n");
			       break;
            case 3:sort_1(&L);
                   printf("对您的序列进行选择排序后结果如下：");
                   traverse(&L);
                   if((fp=fopen("G:\\选择排序.txt","w+"))==NULL) // fopen函数为打开文件的函数  fopen("文件路径","对文件的操作") 
                   { 
				       printf("打开文件失败!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);  //将a[i]保存到文件中 ,  要有空格，与下一数据隔开 
		           }  
			       fclose(fp);    //           关闭文件 
                   printf("此操作结束，请进行其他操作！");
                   printf("\n\n");
                   break;
            case 4:sort_2(&L);
                   printf("对您的序列进行起泡排序后结果如下：");
                   traverse(&L);
                   if((fp=fopen("G:\\起泡排序.txt","w+"))==NULL)
                   { 
				       printf("打开文件失败!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);
		           }  
			       fclose(fp); 
                   printf("此操作结束，请进行其他操作！");
                   printf("\n\n");
                   break;
            case 5:sort_3(&L, 0, Findhigh(&L));
                   printf("对您的序列进行快速排序后结果如下：");
                   traverse(&L);
                   if((fp=fopen("G:\\快速排序.txt","w+"))==NULL)
                   { 
				       printf("打开文件失败!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);
		           }  
			       fclose(fp); 
                   printf("此操作结束，请进行其他操作！");
                   printf("\n\n");
                   break;
            /*case 6:start = clock();
			       //sort_1(&L);
				   //finish = clock();
				   //double time = (finish - start)/CLOCKS_PER_SEC;
				   //double time = sort_1(&L);
				   printf("选择排序的运行时间为：%f\n", time); 
				   break;*/
            case 6:printf("谢谢使用，再见！\n");
                   return false;
                   break;
            default:printf("您的输入有误，请重新输入！\n");
	    } 
    }

}
