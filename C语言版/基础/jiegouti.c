/*
    2015年11月16日19:23:41
	目的；结构体的使用。 
*/ 
#include <stdio.h>
#include <string.h>//  strcpy函数的头文件 

struct Student{
	int sid;
	char name[200];
	int age;
};

void f(struct Student *p)
{
	(*p).sid = 200;//    也可写成p->sid = 200; 
	strcpy(p->name, "qiaodan");//   赋值字符串的方法 
	//p->name = "jkj";
	p->age = 22;
}

void g(struct Student *p)
{
	printf("%d %s %d", p->sid, p->name, p->age);
}

int main(void)
{
	struct Student st = {1000, "zhangsan", 20};
	//st.sid = 99;           第一种方法 
	//st.name = lisi;        错误
	strcpy(st.name, "lisi"); 
	
	printf("%d\n", st.sid);
	printf("%s\n", st.name);
	struct Student *p;
	p = &st;//   完整写法 
	p->sid = 99;//           第二种方法  用指针只用传递一次 
	
	printf("%d\n", st.sid);  
	
	f(&p);//       要用取地址符 
	g(&p);
	
	return 0;
	
}
//    结构体变量不能加减乘除，但能相互赋值 
//    要改变结构体函数的值，必须发送地址，不改变值，发送内容和地址都行 
/*
***************结果***************
1000
lisi
99
200 qiaodan 22
--------------------------------
Process exited after 0.05728 seconds with return value 0
请按任意键继续. . .
*/
