#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;
#define OVERFLOW -1;

typedef int Status;

/*�������Ķ�������洢��ʾ*/
typedef char TElemType;
typedef struct BiTNode{
   TElemType data;
   struct BiTNode  *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct stack
    {
     BiTree data[100];
     int tag[100];   /*Ϊջ��ÿ��Ԫ�����õı�ǣ����ں������*/
     int top;        /*ջ��*/
}SeqStack;


Status PrintElement(TElemType e) 
{
	printf("%c",e);
	return OK;
}

/*�㷨��������������*/
 Status CreateBiTree(BiTree &T)
 {
  char ch;  
  ch=getchar();
  
  if(ch==' ') T=NULL;
  /*�������Ķ�����Ϊһ�ÿն�����*/    
  else { /*���ɶ������ĸ����*/
	if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) exit(-1);
	T->data=ch;
        CreateBiTree(T->lchild);/*�ݹ�ʵ���������Ľ���*/
	    CreateBiTree(T->rchild);/*�ݹ�ʵ���������Ľ���*/
   }
  return OK;
 }/*�㷨����*/
 
 
/*�㷨��ǰ������������ĵݹ��㷨*/
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e))
{    if (T) {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild, Visit))
               if (PreOrderTraverse(T->rchild, Visit)) return OK;
          return ERROR;
     }
     else return OK;
}/*ǰ������������ĵݹ��㷨����*/
 
/*�㷨����������������ĵݹ��㷨*/
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{    if (T) {
        if (InOrderTraverse(T->lchild, Visit))
		     if (Visit(T->data))           
               if (InOrderTraverse(T->rchild, Visit)) return OK;
          return ERROR;
     }
     else return OK;
}/*��������������ĵݹ��㷨����*/

/*�㷨����������������ĵݹ��㷨*/ 
Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{    if (T) {
        if (PostOrderTraverse(T->lchild, Visit))        
               if (PostOrderTraverse(T->rchild, Visit)) 
			           if (Visit(T->data)) return OK;
          return ERROR;
     }
     else return OK;
}/*��������������ĵݹ��㷨����*/

void preorderl(BiTree t)/*�㷨���ǵݹ�ʵ�ֶ�������ǰ�����*/
 {  
    SeqStack s;
    s.top=-1;
    while((t)||(s.top!=-1))/*��ǰ�����������Ϊ�ջ�ջ��Ϊ����ѭ��*/
    {
        while(t)
       {
	   printf("%c",t->data);
           s.top++;
           s.data[s.top]=t;
           t=t->lchild;
       }
      if(s.top>-1)
       {
           t=s.data[s.top];
           s.top--;
           t=t->rchild;
       }
     }
}/*�㷨����*/


void inorderl(BiTree t) /*�㷨���ǵݹ�ʵ�ֶ��������������*/
{
       SeqStack s;
       s.top=-1;
       while((t)||(s.top!=-1))
      {
          while(t)
         {
            s.top++;
            s.data[s.top]=t;
            t=t->lchild;
         }
          if(s.top>-1)
          {
             t=s.data[s.top];
              s.top--;
	     printf("%c",t->data);
             t=t->rchild;
           }
        }
}/*�㷨����*/

void postorderl(BiTree t)/*�㷨���ǵݹ�ʵ�ֶ������ĺ������*/
{
    SeqStack s;
    s.top=-1;
    while((t)||(s.top>-1))
    {
       while(t)
       {
         s.top++;
         s.data[s.top]=t;
	     s.tag[s.top]=0;
         t=t->lchild;
       }
       while((s.top>-1)&&(s.tag[s.top]==1))
      {
          t=s.data[s.top];
	      printf("%c",t->data);
          s.top--;
      }
       if(s.top>-1)
       {
         t=s.data[s.top];
         s.tag[s.top]=1;
         t=t->rchild;
       }
       else t=NULL;
    }
}/*�㷨����*/

int main()/*������*/
{
   BiTree T=NULL;
   char x;
  

   printf("\n�밴ǰ�������˳���������������ֵ���������ÿո���棺");
   CreateBiTree(T);
   
   printf("\n\n�ݹ�ǰ���������Ϊ:");
   PreOrderTraverse(T,PrintElement);  


   printf("\n\n�ݹ������������Ϊ:");
   InOrderTraverse(T,PrintElement); 
   
   printf("\n\n�ݹ�����������Ϊ:");
   PostOrderTraverse(T,PrintElement); 
   
   printf("\n\n�ǵݹ�ǰ���������Ϊ:");
   preorderl(T);  


   printf("\n\n�ǵݹ������������Ϊ:");
   inorderl(T); 
   
   printf("\n\n�ǵݹ�����������Ϊ:");
   postorderl(T); 
   
   system("pause");  
   return 1;
}

