#include<stdio.h>
#include<stdint.h>
#include<limits.h>
//2.75

int signed_high_prod(int x,int y)
{
    int64_t mul=(int64_t)x*y;
    return mul>>(sizeof(int)*8);
}
unsigned unsigned_high_prod(unsigned x,unsigned y)
{
    int w=sizeof(unsigned)*8;
    // coercion to unsigned
    int x_signed=(int)x;
    int y_signed=(int)y;

    int signed_high=signed_high_prod(x_signed,y_signed);
    
    // extract symbol bit
    int sign_x=x>>w-1;
    int sign_y=y>>w-1;

    return (unsigned)signed_high+sign_x*y+sign_y*x;
}

int main(void)
{
    unsigned x;
    unsigned y;
    scanf("0x%x 0x%x",&x,&y);
    while (getchar() != '\n');
    unsigned result=unsigned_high_prod(x,y);
    printf("0x%X\n",result);
    return 0;
}

// 2.77

int mul_17(int x)
{
    return (x<<4)+x;
}
int mul_minus7(int x)
{
    return -(x<<3)+x;
}
int mul_60(int x)
{
    return -(x<<2)+(x<<6);
}
int mul_minus112(int x)
{
    return -(x<<6)+(x<<4);
}

int main(void)
{
    int x;
    scanf("%d",&x);
    while (getchar() != '\n');
    printf("%d\n",mul_17(x));
    printf("%d\n",mul_minus7(x));
    printf("%d\n",mul_60(x));
    printf("%d\n",mul_minus112(x));
    return 0;
}

// 2.79

int mul3div4(int x) 
{
    int is_neg = x & INT_MIN;
    int x_div4 = x >> 2;
    if (is_neg && (x & 3)) 
    {x_div4++;}
    return x - x_div4;
}

int main(void)
{
    int x;
    scanf("%d",&x);
    while (getchar() != '\n');
    printf("%d\n",mul3div4(x));
    return 0;
}

//2.82

// A. (x<y)==(-x>-y)  false   when x=INT_MIN -x=x
// B. ((x+y)<<4)+y-x==17*x+15*x true   complement arithmetic satisfy mod 2^32
// C. ~x+~y+1==~(x+y)  true   ~x=-x-1
// D. (ux-uy)==-(unsigned)(y-x)   true  the work pattern is the same
// E. ((x>>2)<<2)<=x   false   when x is negative
