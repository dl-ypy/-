#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;//typedef LNode *LinkList;
LinkList Create(void)//创建单链表 
{
	LinkList head,s,r;//LNode *head,*s,*r;
	ElemType ch;
	head=(LNode*)malloc(sizeof(LNode));
	if(head==NULL){
		printf("不能分配空间！！！");
		exit(ERROR);
	}
	r=head;
	printf("请输入链表各结点的数据：\n");
	while((ch=getchar())!='\n'){
		s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL){
			printf("不能分配空间！！！");
			exit(ERROR);
		}
		s->data=ch;//将值赋给头结点head的next域S 
		r->next=s;//将S赋给r的next区域 
		r=s;
	}
	r->next=NULL;
	return head;
}
Status GetElem(LinkList head,int i,ElemType e)//查找第i个数据，赋值给e 
{
	LinkList p=head->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i){
		printf("该数据不存在！！！\n");
		return ERROR;
	}
	e=p->data;
	printf("您要查找的数据为%c\n",e);
	return OK;
}
Status ListInsert(LinkList head,int i,ElemType e)//在第i个数据前插入数据e 
{
	LinkList s;
	LinkList p=head;//必须有前面的数据类型 
	int j=0;
	while(p&&j<i-1){ 
		p=p->next;
		++j;//先加一，后使用 
	}//寻找第i-1个结点 
	if(!p||j>i-1){
		printf("未找到第%d个结点！！！\n",i-1);
		exit(ERROR);
	}
	s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}
Status ListDelete(LinkList head,int i)//删除第i个数据 
{
	LinkList p=head,q;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		++j;
	}//寻找第i个结点，令p指向其前趋
	if(!(p->next)||j>i-1){
		printf("您要删除的位置不当！！！\n");
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}
int main()
{
	LinkList s,p;
	int i,i1,i2;
	ElemType e;
	p=Create();//p为头指针,无数据 
	printf("链表各结点的数据为：\n");
	for(s=p->next;s!=NULL;s=s->next){
		printf("%c",s->data);
	}
	printf("\n");
	printf("请输入要插入的数据和位置：\n");
	scanf("%c%d",&e,&i);//输入时必须先输入char型 
	ListInsert(p,i,e);
	printf("在第%d个位置插入数据%c后链表各结点的数据为：\n",i,e);
	for(s=p->next;s!=NULL;s=s->next){
		printf("%c",s->data);
	}
	printf("\n");
    printf("请输入要查找第几个数据：\n");
	scanf("%d",&i1);
	GetElem(p,i1,e);	
	printf("请输入您要删除第几个数据：\n");
	scanf("%d",&i2);
	ListDelete(p,i2);
	printf("删除后的链表各结点数据为：\n");
	for(s=p->next;s!=NULL;s=s->next){
		printf("%c",s->data);
	}
	printf("\n");
	getch();
	return 0;
}
