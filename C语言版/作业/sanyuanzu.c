//#include<string.h>
 //#include<ctype.h>
 #include<malloc.h> /* malloc()等 */
 //#include<limits.h> /* INT_MAX等 */
 #include<stdio.h> /* EOF(=^Z或F6),NULL */
 #include<stdlib.h> /* atoi() */
 //#include<io.h> /* eof() */
 #include<math.h> /* floor(),ceil(),abs() */
 //#include<process.h> /* exit() */
 /* 函数结果状态代码 */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 /* #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 */
 typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
 //typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */


 typedef int ElemType; /* 定义抽象数据类型ElemType在本程序中为整型 */

/* c1-1.h 采用动态分配的顺序存储结构 */
 typedef ElemType *Triplet; /* 由InitTriplet分配三个元素存储空间 */
 /* Triplet类型是ElemType类型的指针，存放ElemType类型的地址 */


 /* bo1-1.c 抽象数据类型Triplet和ElemType(由c1-1.h定义)的基本操作(8个) */
 Status InitTriplet(Triplet *T,ElemType v1,ElemType v2,ElemType v3)
 { /* 操作结果:构造三元组T,依次置T的三个元素的初值为v1,v2和v3 */
   *T=(ElemType *)malloc(3*sizeof(ElemType));
   if(!*T)
     exit(0);
   (*T)[0]=v1,(*T)[1]=v2,(*T)[2]=v3;
   return OK;
 }
 Status DestroyTriplet(Triplet *T)
 { /* 操作结果：三元组T被销毁 */
   free(*T);
   *T=NULL;
   return OK;
 }

 Status Get(Triplet T,int i, ElemType *e)
 { /* 初始条件：三元组T已存在，1≤i≤3。操作结果：用e返回T的第i元的值 */
   if(i<1||i>3)
     return ERROR;
   *e=T[i-1];
   return OK;
 }

 Status Put(Triplet T,int i,ElemType e)
 { /* 初始条件：三元组T已存在，1≤i≤3。操作结果：改变T的第i元的值为e */
   if(i<1||i>3)
     return ERROR;
   T[i-1]=e;
   return OK;
 }

 Status IsAscending(Triplet T)
 { /* 初始条件：三元组T已存在。操作结果：如果T的三个元素按升序排列，返回1，否则返回0 */
   return(T[0]<=T[1]&&T[1]<=T[2]);
 }

 Status IsDescending(Triplet T)
 { /* 初始条件：三元组T已存在。操作结果：如果T的三个元素按降序排列，返回1，否则返回0 */
   return(T[0]>=T[1]&&T[1]>=T[2]);
 }

 Status Max(Triplet T,ElemType *e)
 { /* 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最大值 */
   *e=T[0]>=T[1]?T[0]>=T[2]?T[0]:T[2]:T[1]>=T[2]?T[1]:T[2];
   return OK;
}
Status Min(Triplet T,ElemType *e)
 { /* 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最小值 */
   *e=T[0]<=T[1]?T[0]<=T[2]?T[0]:T[2]:T[1]<=T[2]?T[1]:T[2];
   return OK;
 }
 void main()
 {
   Triplet T;
   ElemType m,v1,v2,v3;
   Status i,n,a;
   printf("请输入三个数：\n");
   scanf("%d%d%d", &v1,&v2,&v3);
   i=InitTriplet(&T,v1,v2,v3);
 /*i=InitTriplet(&T,5.0,7.1,9.3); /* 当ElemType为双精度型时,可取代上句 */
   printf("调用初始化函数后，i=%d(1:成功) T的三个值为：%d %d %d\n",i,T[0],T[1],T[2]); /* 当ElemType的类型变化时，要相应改变printf()的格式符。 */
   printf("请输入您要查找第几个数：\n");
   scanf("%d", &n);
   i=Get(T,n,&m);
   if(i==OK)
     printf("T的第%d个值为：%d\n",n,m);
   printf("请输入您要将第几个数改成几：\n");
   scanf("%d%d", &n,&a);
   i=Put(T,n,a);
   if(i==OK)
     printf("将T的第%d个值改为%d后，T的三个值为：%d %d %d\n",n,a,T[0],T[1],T[2]);
   i=IsAscending(T); /* 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变 */
   printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
   i=IsDescending(T);
   printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
   if((i=Max(T,&m))==OK) /* 先赋值再比较 */
     printf("T中的最大值为：%d\n",m);
   if((i=Min(T,&m))==OK)
     printf("T中的最小值为：%d\n",m);
   DestroyTriplet(&T); /* 函数也可以不带回返回值 */
   printf("销毁T后，T=%u(NULL)\n",T);
}
