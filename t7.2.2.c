#include <stdio.h>
#include <math.h>
struct rational
{
    int x,y;
};
int Numerator_part(struct rational z)//分子
{
    return z.x;
}
int Denominator_part(struct rational z)//分母
{
    return z.y;
}
double magnitude(struct rational z)//数值大小
{
    return (double)z.x/z.y;
}
int gcd(int m , int n)//求最大公约数用于约分
{
    int temp, i;
    if ( n == 0 || m == 0)
    {
        return 1;
    }
    if(m < n)  
    { 
        temp = m;
        m = n;
        n = temp;
    }
    for(i = n ; i>0 ; i--)  
        if(m%i == 0 && n%i == 0)
        {
            return i;
        }
    
}
struct rational make_from_numer_denomin(int x, int y)
{//此处的函数类型为  struct rational
    struct rational z;
    int temp ;

    temp = gcd(x , y);

    z.x = x/temp;
    z.y = y/temp;
    return z;
}
struct rational add_raitonal(struct rational z1, struct rational z2)//有理数加法
{
    return make_from_numer_denomin(Numerator_part(z1)*Denominator_part(z2) + Numerator_part(z2)*Denominator_part(z1),
				              Denominator_part(z1) * Denominator_part(z2));
}
struct rational sub_raitonal(struct rational z1, struct rational z2)//有理数减法
{
	return make_from_numer_denomin(Numerator_part(z1)*Denominator_part(z2) - Numerator_part(z2)*Denominator_part(z1),
				              Denominator_part(z1) * Denominator_part(z2));
}
struct rational mul_raitonal(struct rational z1, struct rational z2)//有理数乘法
{
	return make_from_numer_denomin(Numerator_part(z1) * Numerator_part(z2),
				 Denominator_part(z1) * Denominator_part(z2));
}
struct rational div_raitonal(struct rational z1, struct rational z2)//有理数除法
{
	return make_from_numer_denomin(Numerator_part(z1) * Denominator_part(z2),
				 Denominator_part(z1) * Numerator_part(z2));
}
void Out_put_raitonal(struct rational f)//此函数用于输出复数
{
    if(f.x == 0)
        {
            printf("%d\n",f.x);
        }
        else if(f.y == 0)
        {
            printf("此数不是有理数\n");
        }
        else if(f.x == f.y && f.x != 0 && f.y != 0)
        printf("%d\n",f.x/f.y);
        else printf("%d/%d\n",f.x,f.y);
        
}
int main()
{
    int x1,x2,y1,y2;
    struct rational z1,z2;
    struct rational temp;

    printf("请输入有理数z1的分子\n");
    scanf("%d" , &x1);
    printf("请输入有理数z1的分母\n");
    scanf("%d" , &y1);

    z1=make_from_numer_denomin(x1 , y1);
    printf("z1=");
    Out_put_raitonal(z1);
    
    printf("z1的数值大小为%lf\n" , magnitude(z1));


    printf("请输入有理数z2的分子\n");
    scanf("%d" , &x2);
    printf("请输入有理数z2的分母\n");
    scanf("%d" , &y2);

    z2=make_from_numer_denomin(x2 , y2);
    printf("z2=");
    Out_put_raitonal(z2);
    
    printf("z2的数值大小为%lf\n" , magnitude(z2));


    printf("z1+z2=");
    temp = add_raitonal(z1 , z2);
    Out_put_raitonal(temp);
    printf("z1-z2=");
    temp = sub_raitonal(z1 , z2);
    Out_put_raitonal(temp);
    printf("z1*z2=");
    temp = mul_raitonal(z1 , z2);
    Out_put_raitonal(temp);
    printf("z1/z2=");
    temp = div_raitonal(z1 , z2);
    Out_put_raitonal(temp);

    
    
}