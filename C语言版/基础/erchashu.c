/*
    2015��12��11��08:36:14
	Ŀ�ģ��ض���������ʵ�֡� 
*/ 
#include <stdio.h>
#include <malloc.h>

typedef struct BTNode
{
	int data;
	struct BTNode * plchild, * prchild;
}tree, * ptree;

ptree CreateBTree(void);
void PreTraverseBTree(ptree);
void InTraverseBTree(ptree);
void PostTraverseBTree(ptree);

int main(void)
{
	ptree pT = CreateBTree(); 
	
	printf("�������Ϊ��");
	PreTraverseBTree(pT);
	printf("\n");
	
	printf("�������Ϊ��");
	InTraverseBTree(pT);
	printf("\n");
	
	printf("�������Ϊ��");
	PostTraverseBTree(pT);
	printf("\n");
	
	return 0;
}

ptree CreateBTree(void)
{
	ptree pA = (ptree)malloc(sizeof(tree));
	ptree pB = (ptree)malloc(sizeof(tree));
	ptree pC = (ptree)malloc(sizeof(tree));
	ptree pD = (ptree)malloc(sizeof(tree));
	ptree pE = (ptree)malloc(sizeof(tree));
	
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	
	pA->plchild = pB;
	pA->prchild = pC;
	pB->plchild = pB->prchild = NULL;
	pC->plchild = pD;
	pC->prchild = NULL;
	pD->plchild = NULL;
	pD->prchild = pE;
	pE->plchild = pE->prchild = NULL;
	
	return pA;
	
}

void PreTraverseBTree(ptree pA)
{
	if (pA != NULL)
	{
		printf("%c ", pA->data);
		
		if (NULL != pA->plchild)
		{
		    PreTraverseBTree(pA->plchild);
        }
        
        if (NULL != pA->prchild)
        {
		    PreTraverseBTree(pA->prchild);
		}
    }
	
	/*
	    �ȷ��ʸ����
		���������������
		��������������� 
	*/
}

void InTraverseBTree(ptree pA)
{
	if (pA != NULL)
	{
		
		if (NULL != pA->plchild)
		{
		    InTraverseBTree(pA->plchild);
        }
        
        printf("%c ", pA->data);
        
        if (NULL != pA->prchild)
        {
		    InTraverseBTree(pA->prchild);
		}
    }
	
	/*
		���������������
		�ٷ��ʸ����
		��������������� 
	*/
}

void PostTraverseBTree(ptree pA)
{
	if (pA != NULL)
	{
		
		if (NULL != pA->plchild)
		{
		    PostTraverseBTree(pA->plchild);
        }
        
        if (NULL != pA->prchild)
        {
		   PostTraverseBTree(pA->prchild);
		}
		
		printf("%c ", pA->data);
    }
	
	/*
		���������������
		���������������
		�ٷ��ʸ���� 
	*/
}
/*
***************���***************
�������Ϊ��A B C D E
�������Ϊ��B A D E C
�������Ϊ��B E D C A

--------------------------------
Process exited after 0.0391 seconds with return value 0
�밴���������. . .
*/ 
