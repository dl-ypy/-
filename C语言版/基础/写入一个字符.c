#include <stdio.h>

int main(void)
{
	FILE *fp; //������FILE��ָ������ 
    char ch; 
    if((fp=fopen("G:\\д���ļ�.txt","w+"))==NULL) // fopen����Ϊ���ļ��ĺ���  fopen("�ļ�·��","���ļ��Ĳ���") 
    { 
        printf("���ļ�ʧ��!"); 
        getch();
        //  exit(1); 
    } 
 
    fputc('a',fp);//���ַ�д���ļ�ָ��fp��ָ����ļ��ĵ�ǰдָ���λ�á� 
                      //��������������£���������д���ļ����ַ���ASCII��ֵ������ʱ������EOF��-1����
	                  //����ȷд��һ���ַ���һ���ֽڵ����ݺ��ļ��ڲ�дָ����Զ�����һ���ֽڵ�λ�á�EOF����ͷ�ļ� stdio.h�ж���ĺꡣ 
 
    fseek(fp,-1,SEEK_CUR);//���������ļ�ָ��fp��λ��
                          //int fseek(FILE *stream, long offset, int fromwhere)
                          //���ִ�гɹ���stream��ָ����fromwhereΪ��׼��ƫ��offset��ָ��ƫ���������ֽڵ�λ�ã���������0��
						  //���ִ��ʧ��(����offset�����ļ������С)���򲻸ı�streamָ���λ�ã���������һ����0ֵ��
						  //SEEK_CUR��ʾ��д�ļ����ļ�ָ��ĵ�ǰλ�ÿ�ʼ������д
    ch=fgetc(fp);//fgetc������Ϊ���ļ�ָ��fpָ����ļ��ж�ȡһ���ַ�����ȡһ���ֽں󣬹��λ�ú���һ���ֽڡ� 
 
    while(ch!=EOF) 
    {  
        putchar(ch); 
        ch=fgetc(fp); 
    } 
    fclose(fp);//  �ر��ļ� 
}
