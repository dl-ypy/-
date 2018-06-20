#include<stdio.h>
#include<stdlib.h>

typedef  struct LNode{
  int data; 
struct LNode *next;
}LNode,*LinkList;

LinkList creat_head();  //创建链表头结点
void creat_list(LinkList &L,int); //创建链表
void insert_list(LinkList &L,int,int ); //插入数据
void delete_list(LinkList &L,int); //删除数据
void print_list(LinkList &L);   //显示链表元素

main()
{  
   LinkList L,p;  
   int n; 
   int x,i;  
      

   L=creat_head();      //创建链表头结点
   printf("输入链表的结点个数 n=");
   scanf("%d",&n);    
   creat_list(L,n);   //创建n个结点的单链表
  

   printf("\n*****************************************************\n");
   printf("输入要插入的元素值 x=");
   scanf("%d",&x);
   printf("\n输入要插入的位置 i=");
   scanf("%d",&i);
   insert_list(L,x,i);   //向链表的第i个元素前插入数据x
   
   
   printf("\n*********************************************************\n");
   printf("输入要删除的元素的位置  i=");
   scanf("%d",&i);
   delete_list(L,i);      //从链表中删除第i个元素

    // getch();
    system("pause");    
   // cin.get();
}
 LinkList creat_head()
 { 
     LinkList p;
     p=(LinkList)malloc(sizeof(LNode));
     p->next=NULL;
     return(p);
  }
 void creat_list(LinkList &L,int n)
  { 
    LinkList p,q; 
     int i;  
     p=L; 
     
     for(i=1;i<=n;i++) 
    {  
       q=(LinkList)malloc(sizeof(LNode)); 
       printf("data:"); 
       scanf("%d",&q->data);
      
       q->next=NULL;
       p->next=q;
       p =q;
     }
     
     print_list(L);     //显示创建好的链表元素
   }
  void insert_list(LinkList &L,int x,int i )
  { 
     int j=0; 
     LinkList p,s;
     p=L;
   
     while((p!=NULL)&&(j<i-1))
    { 
         p=p->next;
         j++;
     }

     if(p==NULL|| j >i-1)  
	 {
	  printf("插入点位置错误！\n");
	  //system("pause");   
	  exit(0);
	 }
     
     s=(LinkList)malloc(sizeof(LNode));
     s->data=x;
     s->next=p->next;
     p->next=s;
     print_list(L);     //显示插入元素后的链表
   }
     void delete_list(LinkList &L,int  i)
   {
      LinkList p,q; 
      int j=0; 
      int x;
      int e;  
     
	  p=L;
      while((p)&&(j<i-1))
     { 
         p=p->next;
         j++;
      }

      if(p==NULL||j >i-1) 
	  {
       printf("删除位置错误！\n");	
	   //system("pause");  
	   exit(0);
	   } 
	   
      q=p->next;
      p->next=q->next;
      e=q->data;
      free(q);     
      print_list(L);
      printf("\ndelete %d",e); 
    }        
    void print_list(LinkList &L)
    {
       LinkList p;
       for(p=L->next;p!=NULL;)
       {  
          printf("%d   ",p->data);
          p=p->next;
       }

    }

