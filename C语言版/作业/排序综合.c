#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>//  exitͷ�ļ� 
#include <stdbool.h>// boolͷ�ļ� 
#include <time.h>//  �������ʱ���clock������ͷ�ļ� 

typedef int Status;

typedef struct List
{
	int * pBase;// ��һ��Ԫ�ص�ַ ,������ָ�룬��Ϊֻ��ָ���ܿ纯������
	int length;
	int cnt;//  ��ЧԪ�ص����� 
}SqList;

void CreateList(SqList * L, int n)//LҲ������ָ�� 
{
	int i;
	int val;
	L->pBase = (int *)malloc(sizeof(int) * n);
	
	if (NULL == L->pBase)
	{
		printf("�����ڴ�ʧ�ܣ�������ֹ��");
		exit(-1);
	}
	
	L->length = n;
	L->cnt = 0;
	
	for (i=1; i<=L->length; i++)
	{
		printf("�������%d��������", i);
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

Status Find(SqList * L, int i)//     �����������ʱ��ֵ�������ļ�ʱ���õ� 
{
	return L->pBase[i];
}

double sort_1(SqList * L)//   ѡ������      4.2s
{
	int i, j, t;

	for (i=0; i<(L->cnt)-1; i++)   //  ֻ��Ҫ�Ƚϳ��ȼ�һ�� 
	{
		for (j=i+1; j<L->cnt; j++)//   ÿ�αȽ϶��ǵ�i���͵�i+1,i+2...�����бȽ� 
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

void sort_2(SqList * L)//   ��������       3.558s
{
	int i, j, t;
	
	for (i=0; i<(L->cnt)-1; i++)//    �Ƚϳ��ȼ�һ��
	{
		for (j=0; j<(L->cnt)-i-1; j++)   //������3�� 2�� 1�� 5�� 8   ��һ�αȽ�3��2��3>2, 3��2�������ٱȽ�3��1��������ƣ�һ�αȽ������������� 
		{                                //��һ�αȽ���󣬱Ƚ���һ�Σ������Ǹ����Ͳ��ٲ���Ƚϣ����ԱȽϵĴ���Ϊ  ���ȼ�һ�ټ�ȥ��һ�αȽ���� 
			if (L->pBase[j] > L->pBase[j+1])
			{
				t = L->pBase[j];
				L->pBase[j] = L->pBase[j+1];
				L->pBase[j+1] = t;
			}
	    } 
    } 
}

Status Findhigh(SqList * L)//   ���ڷ������е����һ��ֵ��λ�ã�����������Ҫ 
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

void sort_3(SqList * L, int low, int high)//    ��������      3.453s
{
	int pos;
	
	if (low < high)
	{
		pos = FindPos(L, low, high);
		sort_3(L, low, pos-1);//pos��ǰһ�� 
		sort_3(L, pos+1, high);//pos�ĺ�һ�� 
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
		printf("            ��ӭ���������ۺ�ϵͳ��\n");
		printf("**********************************************\n");
		printf("               1.����һ������\n");
		printf("               2.�鿴����\n");
		printf("               3.ѡ������\n");
		printf("               4.��������\n");
		printf("               5.��������\n");
		//printf("               6.�������򷽷�����ʱ��\n");
		printf("               6.�˳�����\n");
		printf("**********************************************\n");
		
		printf("�����������Ҫ����Ҫִ�в�������ţ�");
		scanf("%d", &m);
		printf("\n");
		
		switch (m)
		{
			case 1:printf("�������������г��ȣ�");
			       scanf("%d", &n);
			       CreateList(&L, n);
			       printf("�˲������������������������"); 
                   printf("\n\n");
			       break;
            case 2:printf("��������Ϊ��\n");
			       traverse(&L);
			       printf("�˲������������������������");
			       printf("\n\n");
			       break;
            case 3:sort_1(&L);
                   printf("���������н���ѡ������������£�");
                   traverse(&L);
                   if((fp=fopen("G:\\ѡ������.txt","w+"))==NULL) // fopen����Ϊ���ļ��ĺ���  fopen("�ļ�·��","���ļ��Ĳ���") 
                   { 
				       printf("���ļ�ʧ��!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);  //��a[i]���浽�ļ��� ,  Ҫ�пո�����һ���ݸ��� 
		           }  
			       fclose(fp);    //           �ر��ļ� 
                   printf("�˲������������������������");
                   printf("\n\n");
                   break;
            case 4:sort_2(&L);
                   printf("���������н�����������������£�");
                   traverse(&L);
                   if((fp=fopen("G:\\��������.txt","w+"))==NULL)
                   { 
				       printf("���ļ�ʧ��!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);
		           }  
			       fclose(fp); 
                   printf("�˲������������������������");
                   printf("\n\n");
                   break;
            case 5:sort_3(&L, 0, Findhigh(&L));
                   printf("���������н��п�������������£�");
                   traverse(&L);
                   if((fp=fopen("G:\\��������.txt","w+"))==NULL)
                   { 
				       printf("���ļ�ʧ��!"); 
				       getch();
				   }
				   for (i=0; i<n; i++)
				   {
				   	   a[i] = Find(&L, i);
				   	   fprintf(fp, "%d ", a[i]);
		           }  
			       fclose(fp); 
                   printf("�˲������������������������");
                   printf("\n\n");
                   break;
            /*case 6:start = clock();
			       //sort_1(&L);
				   //finish = clock();
				   //double time = (finish - start)/CLOCKS_PER_SEC;
				   //double time = sort_1(&L);
				   printf("ѡ�����������ʱ��Ϊ��%f\n", time); 
				   break;*/
            case 6:printf("ллʹ�ã��ټ���\n");
                   return false;
                   break;
            default:printf("���������������������룡\n");
	    } 
    }

}
