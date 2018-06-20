/*
    2015年11月17日13:57:32
	目的：跨函数使用内存。 
*/ 
#include <stdio.h>
#include <malloc.h>

struct Student
{
	int sid;
	int age;
};

struct Student * CreateStudent(void)
{
	struct Student *p = (struct Student*)malloc(sizeof(struct Student));
	p->age = 99;
	p->sid = 88;
	
	return p;   //p的数据类型为struct Student *
}

int ShowStudent(struct Student *p)
{	
	printf("%d,%d\n",p->age,p->sid);
}

int main(void)
{
	struct Student * ps;
	
	ps = CreateStudent();
	ShowStudent(ps);
	
	return 0;
}
/*
***************结果***************
99,88

--------------------------------
Process exited after 0.04852 seconds with return value 0
请按任意键继续. . .
*/
