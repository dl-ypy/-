/*
     2015年11月20日11:22:21
	 目的：typedef的运用。 
*/
#include <stdio.h>

typedef struct Student
{
	int age;
	char name[200];
	char sex;
}ST,*pst;//等价于ST代表了struct Student, pst代表了struct Student * 

int main(void)
{
	ST st;
	pst ps = &st;//    要有取地址符&,相当于int * p;  int i;  p = &i; 
	
	st.age = 20;
	printf("%d\n", st.age);
	
	ps->age = 21;
	printf("%d\n", ps->age);
	
	return 0;
}
/*
***************结果***************
20
21

--------------------------------
Process exited after 0.0553 seconds with return value 0
请按任意键继续. . .
*/
