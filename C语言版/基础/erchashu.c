/*
    2015年12月11日08:36:14
	目的：特定二叉树的实现。 
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
	
	printf("先序遍历为：");
	PreTraverseBTree(pT);
	printf("\n");
	
	printf("中序遍历为：");
	InTraverseBTree(pT);
	printf("\n");
	
	printf("后序遍历为：");
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
	    先访问根结点
		再先序遍历左子树
		再先序遍历右子树 
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
		先先序遍历左子树
		再访问根结点
		再先序遍历右子树 
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
		先先序遍历左子树
		再先序遍历右子树
		再访问根结点 
	*/
}
/*
***************结果***************
先序遍历为：A B C D E
中序遍历为：B A D E C
后序遍历为：B E D C A

--------------------------------
Process exited after 0.0391 seconds with return value 0
请按任意键继续. . .
*/ 
