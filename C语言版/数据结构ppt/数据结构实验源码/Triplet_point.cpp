/*
    设计实现抽象数据类型“三元组 （Triplet）” 。每个三元组
由任意三个实数的序列构成，基本操作包括：创建一个三元组，
取三元组的任意一个分量，置三元组的任意一个分量，求三元组
的最大分量、最小分量，显示三元组，销毁三元组等。
    
    方法2：用指针描述“三元组”，要求：动态分配内存。
*/

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2 
typedef int Status;

//三元组的类型先定义为int,可以随时变换成别的类型 

typedef float ElemType;
typedef ElemType *Triplet;//声明Triplet为ElemType指针类型 

//三元组的初始化
Status initTriplet(Triplet &T,ElemType v0,ElemType v1,ElemType v2)
{
	T=(ElemType *)malloc(3*sizeof(ElemType));
	if(T==NULL) 
	{
		printf("分配内存失败！");
		exit(OVERFLOW);
	}
	T[0]=v0;
	T[1]=v1;
	T[2]=v2;
	return OK;
}
//销毁三元组,静态存储是在程序开始的时候就分配固定的内存单元，整个程序结束后自动释放存储单元，不需销毁 
//而动态存储单元在程序运行初不分配内存单元在用到时才分配，而当用过后需要用语句释放该内存空间
Status destroyTriplet(Triplet &T)
{
	free(T);
	T=NULL;
	printf("分配内存已释放！");
	return OK;
}
//用e获取T的第i(1~3)个元素的值， 
Status getElem(Triplet T,int i,ElemType &e)
{
	if(i<1||i>3)
		return ERROR;
	else e=T[i-1];
		return OK;
}
//置T的第i元的值为e 
Status putElem(Triplet &T,int i,ElemType e)
{
	if(i<1||i>3)
		return ERROR;
	else T[i-1]=e;
		return OK;
}
//如果T的三个元素按升序排列，则返回1，否则返回0
Status isAscending(Triplet T)
{
	return (T[0]<=T[1])&&(T[1]<=T[2]);
} 
//如果T的三个元素按降序排列，则返回1，否则返回0
Status isDescending(Triplet T)
{
	return (T[0]>=T[1])&&(T[1]>=T[2]);
} 
//用e返回指向T的最大元素的值
ElemType getMax(Triplet T,ElemType &e)
{
	if(T[0]>T[1])
	   e=T[0];
	   else
	   	 e=T[1];
    if(T[2]>e)
       e=T[2];
    return e;
} 
//用e返回指向T的最小元素的值
ElemType getMin(Triplet T,ElemType &e)
{
	if(T[0]<T[1])
	     e=T[0];
	   else
	   	 e=T[1];
    if(T[2]<e)
    	 e=T[2];
    return e;
} 


int main()
{
	Triplet T;
	Status flag;
	ElemType v0,v1,v2,e;
	printf("请进入三元组的三个值v0,v1,v2:\n"); 
	scanf("%f,%f,%f",&v0,&v1,&v2);
	flag=initTriplet(T,v0,v1,v2);
	printf("调用初始化函数后，flag=%d,T的三个值为：%4.2f,%4.2f,%4.2f\n",flag,T[0],T[1],T[2]);
	if(isAscending(T))
	printf("该三元组元素为升序\n");
	if(isDescending(T))
	printf("该三元组元素为降序\n");
	printf("该三元组中的最大值为：%4.2f,最小值为：%4.2f\n",getMax(T,e),getMin(T,e));
	destroyTriplet(T);
	return OK;
} 
 

