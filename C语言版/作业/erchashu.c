#include <stdio.h>
#include <malloc.h>
//#include <string.h>//strlen函数的头文件 

#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode * lchild, * rchild;//左孩子，右孩子指针 
}BiTNode, * BiTree[MAX_TREE_SIZE];//**********************************************

Status InitBiTree(BiTree  T)//        构造空二叉树 
{
	int i;
	
	//*T = (BiTNode *)malloc(sizeof(BiTNode) * MAX_TREE_SIZE);
	
	for (i=0; i<MAX_TREE_SIZE; i++)
	{
		T[i] = NULL;
	}
	
	return OK;
}

Status CreatBiTree(BiTree T)
{
	int i,len;
	
	printf("请输入各结点的值（字符数小于100，0表示空结点,输入999表示结束）：\n");
	//gets(s);     //输入字符串
	
	//len = strlen(s);
	
	i = 0;
	
	while (1)
	{
		scanf("%d", &T[i]);
		
		if (T[i] == 999)
		    break;
		    
		if (i!=0 && T[i]!=NULL && T[(i+1)/2-1]==NULL) // 此结点不为空，不是根结点 ，但无双亲
		{
			printf("出现无双亲的非根非空结点！！！\n");//  序号为i的结点，其双亲结点的序号为 (i+1)/2-1
			exit(ERROR);
		}
		
		i++;	
    }  
	
	while (i < MAX_TREE_SIZE)
	{
		T[i] = NULL;    //   将空值赋给T后面的结点
		i++;
    } 
	
	return OK;
}

Status print(TElemType e)//   递归调用中需要访问输出的函数 
{
	printf("%d", e);
	
	return OK;
}

int BiTreeEmpty(BiTree T)
{
	if (T[0] == NULL)
	    return 1;
    else
        return 0;
}

void PreTraverse(BiTree T, int e)//  递归遍历 
{
	print(T[e]);
	
	if (T[2*e+1] != NULL)
	    PreTraverse(T, 2*e+1);//   左子树不为空 
	    
    if (T[2*e+2] != NULL)
	    PreTraverse(T, 2*e+2);//   右子树不为空 
}

Status PreOrderTraverse(BiTree T, TElemType e)//    先序遍历 
{
	if (!BiTreeEmpty(T))//  树不为空
	    PreTraverse(T, 0); 
	    
    printf("\n");
	
	return OK;
}

void InTraverse(BiTree T, int e)//  递归遍历 
{
	if (T[2*e+1] != NULL)
	    InTraverse(T, 2*e+1);//   左子树不为空 
	    
	    print(T[e]);
	    
    if (T[2*e+2] != NULL)
	    InTraverse(T, 2*e+2);//   右子树不为空 
}

Status InOrderTraverse(BiTree T, TElemType e)//   中序遍历 
{
	if (!BiTreeEmpty(T))//  树不为空
	    InTraverse(T, 0);
	    
	    printf("\n");
	
	return OK;
}

void PostTraverse(BiTree T, int e)//  递归遍历 
{
	if (T[2*e+1] != NULL)
	    PostTraverse(T, 2*e+1);//   左子树不为空 
	    
    if (T[2*e+2] != NULL)
	    PostTraverse(T, 2*e+2);//   右子树不为空 
	    
	    print(T[e]);
}

Status PostOrderTraverse(BiTree T, TElemType e)//    后序遍历 
{
	if (!BiTreeEmpty(T))//  树不为空
	    PostTraverse(T, 0);
	    
	    printf("\n");
	
	return OK;
}

int main(void)
{
	BiTree T;
	//Status visit;
	
	InitBiTree(&T);
	CreatBiTree(&T);
	
	printf("先序遍历二叉树：\n");
	PreOrderTraverse(&T, print);
	
	printf("中序遍历二叉树：\n");
	InOrderTraverse(&T, print);
	
	printf("后序遍历二叉树：\n");
	PostOrderTraverse(&T, print);
	
	getch();       //防闪退 
	
	return 0;
} 
