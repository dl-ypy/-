#include <stdio.h>
#include <malloc.h>
#include<limits.h>//UINT_MAX��ͷ�ļ� 
#include<string.h>

#define OK 1

typedef struct
{
    unsigned int weight;//   �޷��ŵ����� 
    unsigned int parent,lchild,rchild;
}HuffmanTree,*pHuffmanTree;

typedef char ** HuffmanTreeCode;// ��̬��������

int min(pHuffmanTree T, int i)
{
    int j,flag;
    unsigned int k = UINT_MAX;// ȡkΪ��С�ڿ��ܵ�ֵ
    
    for (j=1; j<=i; j++)
    {
    	if (T[j].weight<k && T[i].parent==0)
    	{
    		k = T[i].weight,flag=j;
		}
	}
	T[flag].parent = 1;
    
    return flag;
}

void select(pHuffmanTree T, int i, int * s1, int * s2)// s1Ϊ��С������ֵ�����С���Ǹ�
{
     int j;
     s1 = min(T, i);
     s2 = min(T, i);
     
     if (s1 > s2)
     {
     	j = s1;
     	s1 = s2;
     	s2 = j;
	 }
     
     return OK;
}

void HuffmanTreeCoding(pHuffmanTree HT, HuffmanTreeCode HC, int * w, int n)//w���n���ַ���Ȩֵ(��>0),����շ�����HT,�����n���ַ��ĺշ�������HC
{
    int m, i, s1, s2, start;
    unsigned c,f;
    pHuffmanTree p;
    char * cd;
    
    if (n <= 1)
    {
    	printf("���������������1��");
    	return;
	}
    
    m = 2*n-1;
    
    HT = (pHuffmanTree)malloc((m+1)*sizeof(HuffmanTree));// 0�ŵ�Ԫδ��
    
    for (p=HT+1,i=1; i<=n; i++,p++,w++)
    {
    	p[i].weight = w;
    	p[i].parent = 0;
    	p[i].rchild = 0;
    	p[i].lchild = 0;
	}
	
	for (i=0; i<=m; i++,p++)
	    p[i].parent = 0;
	    
    for (i=n+1; i<=m; i++)//  �����շ����� 
    {
    	select(HT, i-1, &s1, &s2);
    	HT[s1].parent = HT[s2].parent = i;
    	HT[i].lchild = s1;
    	HT[i].rchild = s2;
    	HT[i].weight = HT[s1].weight+HT[s2].weight;
	}

	*HC = (HuffmanTreeCode*)malloc((n+1)*sizeof(char));// ����n���ַ������ͷָ������([0]����)   **************************************************************************************
	printf("123456789\n");
	cd = (char*)malloc(n*sizeof(char));// ���������Ĺ����ռ�
	printf("123456789\n");
	cd[n-1] = '\0';// ���������
	 
	for (i=1; i<=n; i++)// ����ַ���շ�������
	{
		start = n-1;// ���������λ��
		for (c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)// ��Ҷ�ӵ������������
		{
			if (HT[f].lchild == c)
			    cd[--start] = '0';
            else
                cd[--start] = '1';
            HC[i] = (char*)malloc((n-start)*sizeof(char));// Ϊ��i���ַ��������ռ�
            strcpy(HC[i], &cd[start]);// ��cd���Ʊ���(��)��HC
		}
		
		free(cd);
	}
	 
     return OK;
}

int main(void)
{
	pHuffmanTree HT;
	pHuffmanTree HC;
	int * w, n, i;
	
	printf("������Ȩֵ�ĸ���(>1)��");
	scanf("%d", &n);
	
	w = (int *)malloc(n*sizeof(int));
	
	for (i=0; i<=n-1; i++)
	{
		printf("�������%d��Ȩֵ(����)��", i+1);
		scanf("%d", &w+i);
	}
	printf("\n");
	
	HuffmanTreeCoding(HT, HC, w, n);
	
	for (i=1; i<=n; i++)
	    printf("%d ", HC[i]);
    printf("\n");
    
    getch();
    
    return 0; 
}
