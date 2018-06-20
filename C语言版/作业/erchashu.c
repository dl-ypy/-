#include <stdio.h>
#include <malloc.h>
//#include <string.h>//strlen������ͷ�ļ� 

#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode * lchild, * rchild;//���ӣ��Һ���ָ�� 
}BiTNode, * BiTree[MAX_TREE_SIZE];//**********************************************

Status InitBiTree(BiTree  T)//        ����ն����� 
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
	
	printf("�����������ֵ���ַ���С��100��0��ʾ�ս��,����999��ʾ��������\n");
	//gets(s);     //�����ַ���
	
	//len = strlen(s);
	
	i = 0;
	
	while (1)
	{
		scanf("%d", &T[i]);
		
		if (T[i] == 999)
		    break;
		    
		if (i!=0 && T[i]!=NULL && T[(i+1)/2-1]==NULL) // �˽�㲻Ϊ�գ����Ǹ���� ������˫��
		{
			printf("������˫�׵ķǸ��ǿս�㣡����\n");//  ���Ϊi�Ľ�㣬��˫�׽������Ϊ (i+1)/2-1
			exit(ERROR);
		}
		
		i++;	
    }  
	
	while (i < MAX_TREE_SIZE)
	{
		T[i] = NULL;    //   ����ֵ����T����Ľ��
		i++;
    } 
	
	return OK;
}

Status print(TElemType e)//   �ݹ��������Ҫ��������ĺ��� 
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

void PreTraverse(BiTree T, int e)//  �ݹ���� 
{
	print(T[e]);
	
	if (T[2*e+1] != NULL)
	    PreTraverse(T, 2*e+1);//   ��������Ϊ�� 
	    
    if (T[2*e+2] != NULL)
	    PreTraverse(T, 2*e+2);//   ��������Ϊ�� 
}

Status PreOrderTraverse(BiTree T, TElemType e)//    ������� 
{
	if (!BiTreeEmpty(T))//  ����Ϊ��
	    PreTraverse(T, 0); 
	    
    printf("\n");
	
	return OK;
}

void InTraverse(BiTree T, int e)//  �ݹ���� 
{
	if (T[2*e+1] != NULL)
	    InTraverse(T, 2*e+1);//   ��������Ϊ�� 
	    
	    print(T[e]);
	    
    if (T[2*e+2] != NULL)
	    InTraverse(T, 2*e+2);//   ��������Ϊ�� 
}

Status InOrderTraverse(BiTree T, TElemType e)//   ������� 
{
	if (!BiTreeEmpty(T))//  ����Ϊ��
	    InTraverse(T, 0);
	    
	    printf("\n");
	
	return OK;
}

void PostTraverse(BiTree T, int e)//  �ݹ���� 
{
	if (T[2*e+1] != NULL)
	    PostTraverse(T, 2*e+1);//   ��������Ϊ�� 
	    
    if (T[2*e+2] != NULL)
	    PostTraverse(T, 2*e+2);//   ��������Ϊ�� 
	    
	    print(T[e]);
}

Status PostOrderTraverse(BiTree T, TElemType e)//    ������� 
{
	if (!BiTreeEmpty(T))//  ����Ϊ��
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
	
	printf("���������������\n");
	PreOrderTraverse(&T, print);
	
	printf("���������������\n");
	InOrderTraverse(&T, print);
	
	printf("���������������\n");
	PostOrderTraverse(&T, print);
	
	getch();       //������ 
	
	return 0;
} 
