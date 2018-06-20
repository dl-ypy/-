#include <stdio.h>

int main(void)
{
	FILE *fp; //必须用FILE的指针类型 
    char ch; 
    if((fp=fopen("G:\\写入文件.txt","w+"))==NULL) // fopen函数为打开文件的函数  fopen("文件路径","对文件的操作") 
    { 
        printf("打开文件失败!"); 
        getch();
        //  exit(1); 
    } 
 
    fputc('a',fp);//将字符写到文件指针fp所指向的文件的当前写指针的位置。 
                      //在正常调用情况下，函数返回写入文件的字符的ASCII码值，出错时，返回EOF（-1）。
	                  //当正确写入一个字符或一个字节的数据后，文件内部写指针会自动后移一个字节的位置。EOF是在头文件 stdio.h中定义的宏。 
 
    fseek(fp,-1,SEEK_CUR);//函数设置文件指针fp的位置
                          //int fseek(FILE *stream, long offset, int fromwhere)
                          //如果执行成功，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0。
						  //如果执行失败(比如offset超过文件自身大小)，则不改变stream指向的位置，函数返回一个非0值。
						  //SEEK_CUR表示读写文件从文件指针的当前位置开始读或者写
    ch=fgetc(fp);//fgetc函数意为从文件指针fp指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节。 
 
    while(ch!=EOF) 
    {  
        putchar(ch); 
        ch=fgetc(fp); 
    } 
    fclose(fp);//  关闭文件 
}
