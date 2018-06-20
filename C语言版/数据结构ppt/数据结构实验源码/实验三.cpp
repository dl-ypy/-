#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;
#define OVERFLOW -1;

typedef int Status;

/*二叉树的二叉链表存储表示*/
typedef char TElemType;
typedef struct BiTNode{
   TElemType data;
   struct BiTNode  *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct stack
    {
     BiTree data[100];
     int tag[100];   /*为栈中每个元素设置的标记，用于后序遍历*/
     int top;        /*栈顶*/
}SeqStack;


Status PrintElement(TElemType e) 
{
	printf("%c",e);
	return OK;
}

/*算法：先序建立二叉树*/
 Status CreateBiTree(BiTree &T)
 {
  char ch;  
  ch=getchar();
  
  if(ch==' ') T=NULL;
  /*所建立的二叉树为一棵空二叉树*/    
  else { /*生成二叉树的根结点*/
	if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) exit(-1);
	T->data=ch;
        CreateBiTree(T->lchild);/*递归实现左子树的建立*/
	    CreateBiTree(T->rchild);/*递归实现右子树的建立*/
   }
  return OK;
 }/*算法结束*/
 
 
/*算法：前序遍历二叉树的递归算法*/
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e))
{    if (T) {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild, Visit))
               if (PreOrderTraverse(T->rchild, Visit)) return OK;
          return ERROR;
     }
     else return OK;
}/*前序遍历二叉树的递归算法结束*/
 
/*算法：中序遍历二叉树的递归算法*/
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{    if (T) {
        if (InOrderTraverse(T->lchild, Visit))
		     if (Visit(T->data))           
               if (InOrderTraverse(T->rchild, Visit)) return OK;
          return ERROR;
     }
     else return OK;
}/*中序遍历二叉树的递归算法结束*/

/*算法：后序遍历二叉树的递归算法*/ 
Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{    if (T) {
        if (PostOrderTraverse(T->lchild, Visit))        
               if (PostOrderTraverse(T->rchild, Visit)) 
			           if (Visit(T->data)) return OK;
          return ERROR;
     }
     else return OK;
}/*后序遍历二叉树的递归算法结束*/

void preorderl(BiTree t)/*算法：非递归实现二叉树的前序遍历*/
 {  
    SeqStack s;
    s.top=-1;
    while((t)||(s.top!=-1))/*当前处理的子树不为空或栈不为空则循环*/
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
}/*算法结束*/


void inorderl(BiTree t) /*算法：非递归实现二叉树的中序遍历*/
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
}/*算法结束*/

void postorderl(BiTree t)/*算法：非递归实现二叉树的后序遍历*/
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
}/*算法结束*/

int main()/*主函数*/
{
   BiTree T=NULL;
   char x;
  

   printf("\n请按前序遍历的顺序输入二叉树结点的值，空子树用空格代替：");
   CreateBiTree(T);
   
   printf("\n\n递归前序遍历序列为:");
   PreOrderTraverse(T,PrintElement);  


   printf("\n\n递归中序遍历序列为:");
   InOrderTraverse(T,PrintElement); 
   
   printf("\n\n递归后序遍历序列为:");
   PostOrderTraverse(T,PrintElement); 
   
   printf("\n\n非递归前序遍历序列为:");
   preorderl(T);  


   printf("\n\n非递归中序遍历序列为:");
   inorderl(T); 
   
   printf("\n\n非递归后序遍历序列为:");
   postorderl(T); 
   
   system("pause");  
   return 1;
}

