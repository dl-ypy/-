#include<stdio.h>
#include<stdlib.h>

typedef  struct LNode{
  int data; 
struct LNode *next;
}LNode,*LinkList;

LinkList creat_head();  //��������ͷ���
void creat_list(LinkList &L,int); //��������
void insert_list(LinkList &L,int,int ); //��������
void delete_list(LinkList &L,int); //ɾ������
void print_list(LinkList &L);   //��ʾ����Ԫ��

main()
{  
   LinkList L,p;  
   int n; 
   int x,i;  
      

   L=creat_head();      //��������ͷ���
   printf("��������Ľ����� n=");
   scanf("%d",&n);    
   creat_list(L,n);   //����n�����ĵ�����
  

   printf("\n*****************************************************\n");
   printf("����Ҫ�����Ԫ��ֵ x=");
   scanf("%d",&x);
   printf("\n����Ҫ�����λ�� i=");
   scanf("%d",&i);
   insert_list(L,x,i);   //������ĵ�i��Ԫ��ǰ��������x
   
   
   printf("\n*********************************************************\n");
   printf("����Ҫɾ����Ԫ�ص�λ��  i=");
   scanf("%d",&i);
   delete_list(L,i);      //��������ɾ����i��Ԫ��

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
     
     print_list(L);     //��ʾ�����õ�����Ԫ��
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
	  printf("�����λ�ô���\n");
	  //system("pause");   
	  exit(0);
	 }
     
     s=(LinkList)malloc(sizeof(LNode));
     s->data=x;
     s->next=p->next;
     p->next=s;
     print_list(L);     //��ʾ����Ԫ�غ������
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
       printf("ɾ��λ�ô���\n");	
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

