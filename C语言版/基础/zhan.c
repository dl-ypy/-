/*
     2015年11月29日10:55:11
	 目的：栈的使用。 
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
	pNODE pTop;//   顶部 
	pNODE pBottom;//  底部 
}STACK, * pSTACK;

void initStack(pSTACK);// pSTACK不能加*，因为它本身就有*
void pushStack(pSTACK, int); 
void traverseStack(pSTACK);
bool popStack(pSTACK, int *);
void clearStack(pSTACK);

int main(void)
{
	STACK s;
	int val,m,n,i;
	
	initStack(&s);
	
	printf("请输入您要压栈几个值：");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("请输入您要压栈的第%d个值：", i+1);
		scanf("%d", &m);
		pushStack(&s, m);
	}
	
	printf("您压入栈中的数据为：\n");
	traverseStack(&s);
	
	if (popStack(&s, &val))
	{
		printf("出栈成功，出栈的元素是%d\n", val);
	}
	else
	{
		printf("出栈失败！\n");
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
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		s->pBottom = s->pTop;
		s->pTop->pNext = NULL;
	}
}

void pushStack(pSTACK s, int val)//   压栈 
{
	pNODE pNew = (pNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = s->pTop;// s->pTop不能写成s->Bottom  
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

bool popStack(pSTACK s, int * val)//   出栈
//       把s所指向的栈出栈一次，并把出栈的元素返回 
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

void clearStack(pSTACK s)//       清空 
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
***************结果***************
请输入您要压栈几个值：5
请输入您要压栈的第1个值：9
请输入您要压栈的第2个值：8
请输入您要压栈的第3个值：5
请输入您要压栈的第4个值：6
请输入您要压栈的第5个值：111
您压入栈中的数据为：
111 6 5 8 9
出栈成功，出栈的元素是111


--------------------------------
Process exited after 10.79 seconds with return value 0
请按任意键继续. . .
*/
