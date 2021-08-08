#include <stdio.h>
#include <math.h>
struct complex_struct
{
    double x,y;
};
double real_part(struct complex_struct z)//实部
{
    return z.x;
}
double img_part(struct complex_struct z)//虚部
{
    return z.y;
}
double magnitude(struct complex_struct z)//幅值
{
    return sqrt(z.x * z.x + z.y *z.y);
}
double angle(struct complex_struct z)//幅角
{
    return atan2(z.y , z.x);
}
struct complex_struct make_from_real_img(double x, double y)//用直角坐标构造复数变量
{//此处的函数类型为  struct complex_struct
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}
struct complex_struct make_from_mag_ang(double r, double A)//用极坐标构造复数变量
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)//复数加法
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)//复数减法
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}
struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)//复数乘法
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}
struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)//复数除法
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}
void Out_put_complex(struct complex_struct f)//此函数用于输出复数
{
    if(f.x == 0)
        {
            printf("%.1fi\n",f.y);
        }
        else if(f.y == 0)
        {
            printf("%.1f\n",f.x);
        }
        else if(f.y > 0)
        {
            printf("%.1f+%.1fi\n",f.x,f.y);
        }
        else printf("%.1f%.1fi\n",f.x,f.y);
        
}
int main()
{
    struct complex_struct z1,z2;

    struct complex_struct temp;

    printf("请输入复数z1的实部\n");
    scanf("%lf" , &z1.x);
    printf("请输入复数z1的虚部\n");
    scanf("%lf" , &z1.y);

    printf("z1=");
    Out_put_complex(z1);
    
    printf("z1的幅值为%lf\n" , magnitude(z1));

    printf("z1的幅角为%lf\n" , angle(z1));

    printf("请输入复数z2的实部\n");
    scanf("%lf" , &z2.x);
    printf("请输入复数z2的虚部\n");
    scanf("%lf" , &z2.y);

    printf("z2=");
    Out_put_complex(z2);
    
    printf("z2的幅值为%lf\n" , magnitude(z2));

    printf("z2的幅角为%lf\n" , angle(z2));

    printf("z1+z2=");
    temp = add_complex(z1 , z2);
    Out_put_complex(temp);
    printf("z1-z2=");
    temp = sub_complex(z1 , z2);
    Out_put_complex(temp);
    printf("z1*z2=");
    temp = mul_complex(z1 , z2);
    Out_put_complex(temp);
    printf("z1/z2=");
    temp = div_complex(z1 , z2);
    Out_put_complex(temp);
}