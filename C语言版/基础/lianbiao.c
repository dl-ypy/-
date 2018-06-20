/*
    2015��11��24��14:00:05
	Ŀ�ģ������ʵ�֡� 
*/ 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>//   bool��ͷ�ļ� 

typedef struct Node
{
	int data;  //������
	struct Node * pNext;  //ָ����    ��Ϊ��ָ��ָ����һ����������һģһ���Ľṹ�壬������������Ϊstruct Node 
}NODE, *pNODE;

pNODE create_list(void);

void traverse_list(pNODE);

bool is_empty(pNODE);

int length_list(pNODE);

bool insert_list(pNODE, int, int);

bool delete_list(pNODE, int, int *);

void sort_list(pNODE);

int main(void)
{
	pNODE pHead = NULL;
	int val, m, n;
	
	pHead = create_list();
	
	if (is_empty(pHead))
	    printf("����Ϊ�գ�\n");
    else
        printf("����Ϊ�գ�\n");
        
	printf("���������Ϊ��");
	traverse_list(pHead);
	
	int len = length_list(pHead);
	printf("������Ϊ��%d\n", len);
	
	sort_list(pHead);
	printf("��������Ϊ��");
	traverse_list(pHead);
	
	printf("��������Ҫ�ڵڼ���Ԫ��ǰ���룬�Լ������Ԫ�أ�");
	scanf("%d%d", &m, &n);
	insert_list(pHead, m, n);
	traverse_list(pHead);
	
	printf("��������Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &n);
	if (delete_list(pHead, n, &val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ���ǣ�%d\n", val);
		traverse_list(pHead);
	}
	else
	{
		printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز����ڣ�\n");
	}
	
	return 0;
}

pNODE create_list(void)//    ���� 
{
	int len;//    ��Ž�����
	int i;
	int val;//     ��ʱ����û�����Ľ���ֵ 
	
	pNODE pHead = (pNODE)malloc(sizeof(NODE));//������һ���������Ч���ݵ�ͷ��� 
	if (NULL == pHead)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	pNODE pTail = pHead;//    β��㣬�������½�� 
	pTail->pNext = NULL;
	
	printf("��������Ҫ���ɵ�������ĸ�����len = ");
	scanf("%d", &len);
	
	for (i=0; i<len; i++)
	{
		printf("�������%d������ֵ��", i+1);
		scanf("%d", &val);
		
		pNODE pNew = (pNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
	    {
		    printf("����ʧ�ܣ�������ֹ��\n");
		    exit(-1);
	    }
	    pNew->data = val;//   ���û������ֵ�����½�� 
	    pTail->pNext = pNew;//   �½��ҵ�β������ 
	    pNew->pNext = NULL;//   ����ָ����Ϊ�� 
	    pTail = pNew;//    �½����β��㣬�������� 
	}
	
	return pHead;
}

void traverse_list(pNODE pHead)//     ���� 
{
	pNODE p = pHead->pNext; 
	
	while (NULL != p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;//  ������� 
}

bool is_empty(pNODE pHead)//    �ж��Ƿ�Ϊ�� 
{
	if (NULL == pHead->pNext)
        return true;
    else
        return false;
        
    return;    
}

int length_list(pNODE pHead)//   ��������
{
	pNODE p = pHead->pNext;
	int len = 0;
	
	while (NULL != p)
	{
		len++;
		p = p->pNext;
	}
	
	return len;
} 

void sort_list(pNODE pHead)//   ���� 
{
	int i, j, t;
	pNODE p, q;
	int len = length_list(pHead);
	
	for (i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext)//   ֻ��Ҫ�Ƚ�len-1�� 
	{
		for (j=i+1,q=p->pNext; j<len; j++,q=q->pNext)//   ��i���͵�i+1,i+2�����������Ƚϣ�Ȼ�󻥻� 
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			
		}
	}
	/*
	    �������е����д�������
	for (i=0; i<len-1 ; i++)
	{
		for (j=i+1; j<len; j++)
		{
			if (i > j)
			{
				t = i
				i = j;
				j= t;
			}
			
		}
	} 
	*/
	return;
} 

bool insert_list(pNODE pHead, int pos, int val)//     ����
//               �ڵ�pos��λ��ǰ����Ԫ��val 
{
	int i = 0;
	pNODE p = pHead;
	
	while (NULL!=p && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	
	if (i>pos-1 || NULL==p)
	    return false;
	    
	 pNODE pNew = (pNODE)malloc(sizeof(NODE));
	 if (NULL == pNew)
	 {
	 	printf("��̬�����ڴ�ʧ�ܣ�\n");
	 	exit(-1);
	 }
	 pNew->data = val;
	 pNODE q = p->pNext;
	 p->pNext = pNew;
	 pNew->pNext = q; 
	 
	 return true;  
} 

bool delete_list(pNODE pHead, int pos, int * pVal)
{
	int i = 0;
	pNODE p = pHead;
	
	while (NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	
	if (i>pos-1 || NULL==p->pNext)
	    return false;
	    
	 pNODE q = p->pNext;
	 *pVal = q->data;
	 
	 //ɾ��p����Ľ��
	 p->pNext = p->pNext->pNext;
	 free(q);
	 q = NULL; 
	 
	 return true; 
}
/*
***************���***************
��������Ҫ���ɵ�������ĸ�����len = 5
�������1������ֵ��33
�������2������ֵ��99
�������3������ֵ��55
�������4������ֵ��42
�������5������ֵ��10
����Ϊ�գ�
���������Ϊ��33  99  55  42  10
������Ϊ��5
��������Ϊ��10  33  42  55  99
��������Ҫ�ڵڼ���Ԫ��ǰ���룬�Լ������Ԫ�أ�2 100
10  100  33  42  55  99
��������Ҫɾ���ڼ���Ԫ�أ�6
ɾ���ɹ�����ɾ����Ԫ���ǣ�99
10  100  33  42  55

--------------------------------
Process exited after 31.48 seconds with return value 0
�밴���������. . .
*/
