/*
    2015��11��16��19:23:41
	Ŀ�ģ��ṹ���ʹ�á� 
*/ 
#include <stdio.h>
#include <string.h>//  strcpy������ͷ�ļ� 

struct Student{
	int sid;
	char name[200];
	int age;
};

void f(struct Student *p)
{
	(*p).sid = 200;//    Ҳ��д��p->sid = 200; 
	strcpy(p->name, "qiaodan");//   ��ֵ�ַ����ķ��� 
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
	//st.sid = 99;           ��һ�ַ��� 
	//st.name = lisi;        ����
	strcpy(st.name, "lisi"); 
	
	printf("%d\n", st.sid);
	printf("%s\n", st.name);
	struct Student *p;
	p = &st;//   ����д�� 
	p->sid = 99;//           �ڶ��ַ���  ��ָ��ֻ�ô���һ�� 
	
	printf("%d\n", st.sid);  
	
	f(&p);//       Ҫ��ȡ��ַ�� 
	g(&p);
	
	return 0;
	
}
//    �ṹ��������ܼӼ��˳��������໥��ֵ 
//    Ҫ�ı�ṹ�庯����ֵ�����뷢�͵�ַ�����ı�ֵ���������ݺ͵�ַ���� 
/*
***************���***************
1000
lisi
99
200 qiaodan 22
--------------------------------
Process exited after 0.05728 seconds with return value 0
�밴���������. . .
*/
