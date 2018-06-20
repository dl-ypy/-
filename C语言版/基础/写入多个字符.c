#include <stdio.h>

int main(void)
{
	FILE *fp; //必须用FILE的指针类型 
    char ch; 
    if((fp=fopen("G:\\写入文件2.txt","w+"))==NULL) // fopen函数为打开文件的函数  fopen("文件路径","对文件的操作") 
    { 
        printf("打开文件失败!"); 
        getch();
        //  exit(1); 
    } 
 
    printf("请输入准备存储到文件的字符串\n");  
    ch = getchar();  
    while (ch != '#') {  
        fputc(ch, fp); //写入文件  
        
        //printf("您写入的字符为：");
        putchar(ch); //输出到屏幕  
        ch = getchar();  
    }  
    fclose(fp);//  关闭文件 
}
