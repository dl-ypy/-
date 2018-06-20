/*
    2015年11月24日14:00:05
	目的：链表的实现。 
*/ 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>//   bool的头文件 

typedef struct Node
{
	int data;  //数据域
	struct Node * pNext;  //指针域    因为该指针指向下一个和它本身一模一样的结构体，所以数据类型为struct Node 
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
	    printf("链表为空！\n");
    else
        printf("链表不为空！\n");
        
	printf("链表的数据为：");
	traverse_list(pHead);
	
	int len = length_list(pHead);
	printf("链表长度为：%d\n", len);
	
	sort_list(pHead);
	printf("升序排列为：");
	traverse_list(pHead);
	
	printf("请输入您要在第几个元素前插入，以及插入的元素：");
	scanf("%d%d", &m, &n);
	insert_list(pHead, m, n);
	traverse_list(pHead);
	
	printf("请输入您要删除第几个元素：");
	scanf("%d", &n);
	if (delete_list(pHead, n, &val))
	{
		printf("删除成功，您删除的元素是：%d\n", val);
		traverse_list(pHead);
	}
	else
	{
		printf("删除失败！您删除的元素不存在！\n");
	}
	
	return 0;
}

pNODE create_list(void)//    创建 
{
	int len;//    存放结点个数
	int i;
	int val;//     临时存放用户输入的结点的值 
	
	pNODE pHead = (pNODE)malloc(sizeof(NODE));//分配了一个不存放有效数据的头结点 
	if (NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	pNODE pTail = pHead;//    尾结点，用来挂新结点 
	pTail->pNext = NULL;
	
	printf("请输入您要生成的链表结点的个数：len = ");
	scanf("%d", &len);
	
	for (i=0; i<len; i++)
	{
		printf("请输入第%d个结点的值：", i+1);
		scanf("%d", &val);
		
		pNODE pNew = (pNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
	    {
		    printf("分配失败，程序终止！\n");
		    exit(-1);
	    }
	    pNew->data = val;//   把用户输入的值赋给新结点 
	    pTail->pNext = pNew;//   新结点挂到尾结点后面 
	    pNew->pNext = NULL;//   最后的指针域为空 
	    pTail = pNew;//    新结点变成尾结点，逐渐往后推 
	}
	
	return pHead;
}

void traverse_list(pNODE pHead)//     遍历 
{
	pNODE p = pHead->pNext; 
	
	while (NULL != p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;//  函数完毕 
}

bool is_empty(pNODE pHead)//    判断是否为空 
{
	if (NULL == pHead->pNext)
        return true;
    else
        return false;
        
    return;    
}

int length_list(pNODE pHead)//   求链表长度
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

void sort_list(pNODE pHead)//   排序 
{
	int i, j, t;
	pNODE p, q;
	int len = length_list(pHead);
	
	for (i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext)//   只需要比较len-1次 
	{
		for (j=i+1,q=p->pNext; j<len; j++,q=q->pNext)//   第i个和第i+1,i+2个…………比较，然后互换 
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
	    与数组中的下列代码类似
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

bool insert_list(pNODE pHead, int pos, int val)//     插入
//               在第pos个位置前插入元素val 
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
	 	printf("动态分配内存失败！\n");
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
	 
	 //删除p结点后的结点
	 p->pNext = p->pNext->pNext;
	 free(q);
	 q = NULL; 
	 
	 return true; 
}
/*
***************结果***************
请输入您要生成的链表结点的个数：len = 5
请输入第1个结点的值：33
请输入第2个结点的值：99
请输入第3个结点的值：55
请输入第4个结点的值：42
请输入第5个结点的值：10
链表不为空！
链表的数据为：33  99  55  42  10
链表长度为：5
升序排列为：10  33  42  55  99
请输入您要在第几个元素前插入，以及插入的元素：2 100
10  100  33  42  55  99
请输入您要删除第几个元素：6
删除成功，您删除的元素是：99
10  100  33  42  55

--------------------------------
Process exited after 31.48 seconds with return value 0
请按任意键继续. . .
*/
