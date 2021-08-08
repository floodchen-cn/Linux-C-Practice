#include <stdio.h>

void diamond (int n , char sign)
{
    //上半部分
    for (int i = 1 ; i <= n/2 + 1 ; i++ )
    {
        for (int j= 1 ; j <= i + n/2 ; j++)
        {
            if ( j <= n/2 + 1 - i )
                printf("\t");
            else
                printf("%c\t",sign);
        }
        printf("\n"); 
    }
    //下半部分
    for (int i = n/2 ; i >= 0 ; i--)
    {
        for (int j = 1 ; j <= i + n/2 ; j++)
        {
            if ( j <= n/2 + 1 - i )
                printf("\t");
            else
                printf("%c\t",sign);
        }
        printf("\n");
    }

}
int main(void)
{
    int n = 0 ;
    char sign = '+';
    printf( "请输入菱形的行数：" );
    scanf( "%d" , &n );
    if( n%2 == 0 )
        printf( "Fatal Error!\n" );
    else
    {
        printf( "请输入一个字符用以组成菱形：" );
        scanf( " %c" , &sign );//scanf输入单个字符的时候需要在双引号内加一个空格使得scanf忽略前面空行等待读取非空行的
        diamond(n , sign );
    }
    return 0;
}
