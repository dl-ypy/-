#include <stdio.h>

int main(void)
{
	FILE *fp; //������FILE��ָ������ 
    char ch; 
    if((fp=fopen("G:\\д���ļ�2.txt","w+"))==NULL) // fopen����Ϊ���ļ��ĺ���  fopen("�ļ�·��","���ļ��Ĳ���") 
    { 
        printf("���ļ�ʧ��!"); 
        getch();
        //  exit(1); 
    } 
 
    printf("������׼���洢���ļ����ַ���\n");  
    ch = getchar();  
    while (ch != '#') {  
        fputc(ch, fp); //д���ļ�  
        
        //printf("��д����ַ�Ϊ��");
        putchar(ch); //�������Ļ  
        ch = getchar();  
    }  
    fclose(fp);//  �ر��ļ� 
}
