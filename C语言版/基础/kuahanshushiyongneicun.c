/*
    2015��11��17��13:57:32
	Ŀ�ģ��纯��ʹ���ڴ档 
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
	
	return p;   //p����������Ϊstruct Student *
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
***************���***************
99,88

--------------------------------
Process exited after 0.04852 seconds with return value 0
�밴���������. . .
*/
