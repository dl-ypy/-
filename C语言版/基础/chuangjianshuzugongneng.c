/*
    2015��11��18��10:35:52
	Ŀ�ģ�ʵ��һ������ĸ��ֹ��ܡ� 
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>   //exit��Ҫ 
#include <stdbool.h> // bool������Ҫ 

struct Arr
{
	int * pBase;  //�����һ��Ԫ�صĵ�ַ
	int len;
	int cnt;    // ��ǰ��ЧԪ�صĸ��� 
};

void init_arr(struct Arr *pArr,int length)//    ����    �βα�����ָ�� 
{
	//(*pArr).len = 99;          //*pArr����main�����е�arr 
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
} 

bool is_empty(struct Arr * pArr)//   �ж������Ƿ�Ϊ��
{
	if (0 == pArr->cnt)
	    return true;
    else
        return false;
} 

bool is_full(struct Arr * pArr)//   �ж��Ƿ��� 
{
	if (pArr->cnt == pArr->len)
	    return true;
	else
	    return false;
} 

bool append_arr(struct Arr * pArr, int val) //   ׷��   ��ĩβ��Ԫ��
{
     if (is_full(pArr))
         return false;//������Ļ�����false
     //����ʱ׷��
	 pArr->pBase[pArr->cnt] = val;
	 (pArr->cnt)++;
	 return true; 
} 

bool insert_arr(struct Arr * pArr, int pos, int val)   //   ����     ��ʾ�ڵ�pos��λ��ǰ����valԪ�� 
                                                    //  pos��ʾλ��  ��1��ʼ 
{
	int i;
	
	if (is_full(pArr))
	    return false;
	
	if (pos<1 || pos>pArr->cnt+1)
	    return false;
	
	for (i=pArr->cnt-1; i>= pos-1; i--)//�Ӻ���ǰ��
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;      //��д��һ���Ļ���Чֵ�ĸ����Ͳ��� 
	return true;
	
}

bool delete_arr(struct Arr * pArr, int pos, int * pVal)//      ɾ�� 
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

void inversion_arr(struct Arr * pArr)//     ���� 
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

void sort_arr(struct Arr * pArr)//          ����
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
	
	if (is_empty(pArr))//  �����ﲻ�ܼ�& ����Ϊmain�����е�&pArr�Ѿ�����show_arr�����е�pArr,��������&pArrʱ����pArr��ʾ 
	{
		printf("����Ϊ�գ�\n");
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
	
	printf("��Ҫ���������鳤��Ϊ���٣�\n");
	scanf("%d", &n);
	init_arr(&arr,n);
	
	printf("��������Ҫ׷��Ԫ�صĸ�����\n");
	scanf("%d", &n);
	
	for (i=0; i<n; i++)
	{
		printf("��������Ҫ����ĵ�%d��Ԫ�أ�һ������\n", i+1);
		scanf("%d",&m);
		append_arr(&arr, m);
	}
	printf("׷�Ӻ��Ԫ��Ϊ��\n");
	show_arr(&arr);
	
	printf("��������Ҫ�����λ�ú�Ԫ�أ�\n");
	scanf("%d%d", &m,&n);
	insert_arr(&arr,m,n);
	printf("����Ԫ�غ�Ϊ��\n");
	show_arr(&arr);
	
	inversion_arr(&arr);
	printf("���ú�Ϊ��\n");
	show_arr(&arr);
	
	sort_arr(&arr);
	printf("�������к�Ϊ��\n");
	show_arr(&arr);
	
	printf("��������Ҫɾ���ڼ���Ԫ�أ�\n");
	scanf("%d", &n);
	if (delete_arr(&arr, n, &val))
    {
    	printf("ɾ���ɹ���\n"); 
    	printf("��ɾ����Ԫ���ǣ�%d\n", val); 
	}
	else
	{
		printf("ɾ��ʧ�ܣ�");
	}
	return 0;
} 
/*
***************���***************
��Ҫ���������鳤��Ϊ���٣�
5
��������Ҫ׷��Ԫ�صĸ�����
3
��������Ҫ����ĵ�1��Ԫ�أ�һ������
9
��������Ҫ����ĵ�2��Ԫ�أ�һ������
5
��������Ҫ����ĵ�3��Ԫ�أ�һ������
1
׷�Ӻ��Ԫ��Ϊ��
9 5 1
��������Ҫ�����λ�ú�Ԫ�أ�
1 0
����Ԫ�غ�Ϊ��
0 9 5 1
���ú�Ϊ��
1 5 9 0
�������к�Ϊ��
0 1 5 9
��������Ҫɾ���ڼ���Ԫ�أ�
4
ɾ���ɹ���
��ɾ����Ԫ���ǣ�9

--------------------------------
Process exited after 32.04 seconds with return value 0
�밴���������. . .
*/
