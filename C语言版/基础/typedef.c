/*
     2015��11��20��11:22:21
	 Ŀ�ģ�typedef�����á� 
*/
#include <stdio.h>

typedef struct Student
{
	int age;
	char name[200];
	char sex;
}ST,*pst;//�ȼ���ST������struct Student, pst������struct Student * 

int main(void)
{
	ST st;
	pst ps = &st;//    Ҫ��ȡ��ַ��&,�൱��int * p;  int i;  p = &i; 
	
	st.age = 20;
	printf("%d\n", st.age);
	
	ps->age = 21;
	printf("%d\n", ps->age);
	
	return 0;
}
/*
***************���***************
20
21

--------------------------------
Process exited after 0.0553 seconds with return value 0
�밴���������. . .
*/
