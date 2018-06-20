/*
     2015��11��29��10:55:11
	 Ŀ�ģ�ջ��ʹ�á� 
*/ 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * pNODE;

typedef struct Stack
{
	pNODE pTop;//   ���� 
	pNODE pBottom;//  �ײ� 
}STACK, * pSTACK;

void initStack(pSTACK);// pSTACK���ܼ�*����Ϊ���������*
void pushStack(pSTACK, int); 
void traverseStack(pSTACK);
bool popStack(pSTACK, int *);
void clearStack(pSTACK);

int main(void)
{
	STACK s;
	int val,m,n,i;
	
	initStack(&s);
	
	printf("��������Ҫѹջ����ֵ��");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("��������Ҫѹջ�ĵ�%d��ֵ��", i+1);
		scanf("%d", &m);
		pushStack(&s, m);
	}
	
	printf("��ѹ��ջ�е�����Ϊ��\n");
	traverseStack(&s);
	
	if (popStack(&s, &val))
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%d\n", val);
	}
	else
	{
		printf("��ջʧ�ܣ�\n");
	}
	
	clearStack(&s);
	traverseStack(&s);
	
	return 0;
}

void initStack(pSTACK s)
{
	s->pTop = (pNODE)malloc(sizeof(NODE));
	if (NULL == s->pTop)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		s->pBottom = s->pTop;
		s->pTop->pNext = NULL;
	}
}

void pushStack(pSTACK s, int val)//   ѹջ 
{
	pNODE pNew = (pNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = s->pTop;// s->pTop����д��s->Bottom  
	s->pTop = pNew;
}

void traverseStack(pSTACK s)
{
	pNODE p = s->pTop;
	
	while (p != s->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool empty(pSTACK s)
{
	if (s->pBottom  == s->pTop)
	    return true;
    else
        return false;
}

bool popStack(pSTACK s, int * val)//   ��ջ
//       ��s��ָ���ջ��ջһ�Σ����ѳ�ջ��Ԫ�ط��� 
{
	if (empty(s))
	{
		return false;
	}
	else
	{
		pNODE r = s->pTop;
		*val = r->data;
		s->pTop = s->pTop->pNext;
		free(r);
		r = NULL;
		
		return true;
	}
}

void clearStack(pSTACK s)//       ��� 
{
	if (empty(s))
	{
		return;
	}
	else
	{
		pNODE p = s->pTop;
		pNODE q = NULL;
		
		while (p != s->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		s->pTop = s->pBottom;
	}
} 
/*
***************���***************
��������Ҫѹջ����ֵ��5
��������Ҫѹջ�ĵ�1��ֵ��9
��������Ҫѹջ�ĵ�2��ֵ��8
��������Ҫѹջ�ĵ�3��ֵ��5
��������Ҫѹջ�ĵ�4��ֵ��6
��������Ҫѹջ�ĵ�5��ֵ��111
��ѹ��ջ�е�����Ϊ��
111 6 5 8 9
��ջ�ɹ�����ջ��Ԫ����111


--------------------------------
Process exited after 10.79 seconds with return value 0
�밴���������. . .
*/
