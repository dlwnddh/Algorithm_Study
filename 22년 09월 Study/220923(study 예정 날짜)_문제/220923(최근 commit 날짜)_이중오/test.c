#include <stdio.h>

int main(void)
{
    char str[100];
    
    puts("문자열을 입력하세요 : ");
    gets(str);
    
    printf("입력한 문자열은 %s 입니다. \n", str);
    
    return 0;
}