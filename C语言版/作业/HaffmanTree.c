#include <stdio.h>
#include <malloc.h>
#include<limits.h>//UINT_MAX的头文件 
#include<string.h>

#define OK 1

typedef struct
{
    unsigned int weight;//   无符号的整型 
    unsigned int parent,lchild,rchild;
}HuffmanTree,*pHuffmanTree;

typedef char ** HuffmanTreeCode;// 动态分配编码表

int min(pHuffmanTree T, int i)
{
    int j,flag;
    unsigned int k = UINT_MAX;// 取k为不小于可能的值
    
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

void select(pHuffmanTree T, int i, int * s1, int * s2)// s1为最小的两个值中序号小的那个
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

void HuffmanTreeCoding(pHuffmanTree HT, HuffmanTreeCode HC, int * w, int n)//w存放n个字符的权值(均>0),构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC
{
    int m, i, s1, s2, start;
    unsigned c,f;
    pHuffmanTree p;
    char * cd;
    
    if (n <= 1)
    {
    	printf("您输入的数不大于1！");
    	return;
	}
    
    m = 2*n-1;
    
    HT = (pHuffmanTree)malloc((m+1)*sizeof(HuffmanTree));// 0号单元未用
    
    for (p=HT+1,i=1; i<=n; i++,p++,w++)
    {
    	p[i].weight = w;
    	p[i].parent = 0;
    	p[i].rchild = 0;
    	p[i].lchild = 0;
	}
	
	for (i=0; i<=m; i++,p++)
	    p[i].parent = 0;
	    
    for (i=n+1; i<=m; i++)//  建立赫夫曼树 
    {
    	select(HT, i-1, &s1, &s2);
    	HT[s1].parent = HT[s2].parent = i;
    	HT[i].lchild = s1;
    	HT[i].rchild = s2;
    	HT[i].weight = HT[s1].weight+HT[s2].weight;
	}

	*HC = (HuffmanTreeCode*)malloc((n+1)*sizeof(char));// 分配n个字符编码的头指针向量([0]不用)   **************************************************************************************
	printf("123456789\n");
	cd = (char*)malloc(n*sizeof(char));// 分配求编码的工作空间
	printf("123456789\n");
	cd[n-1] = '\0';// 编码结束符
	 
	for (i=1; i<=n; i++)// 逐个字符求赫夫曼编码
	{
		start = n-1;// 编码结束符位置
		for (c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)// 从叶子到根逆向求编码
		{
			if (HT[f].lchild == c)
			    cd[--start] = '0';
            else
                cd[--start] = '1';
            HC[i] = (char*)malloc((n-start)*sizeof(char));// 为第i个字符编码分配空间
            strcpy(HC[i], &cd[start]);// 从cd复制编码(串)到HC
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
	
	printf("请输入权值的个数(>1)：");
	scanf("%d", &n);
	
	w = (int *)malloc(n*sizeof(int));
	
	for (i=0; i<=n-1; i++)
	{
		printf("请输入第%d个权值(整型)：", i+1);
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
