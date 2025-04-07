#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// 2.60
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = 0xFF << (i * 8);
    unsigned b_shifted = b << (i * 8);
    unsigned x_cleared = x & (~mask);
    unsigned x_replaced = x_cleared | b_shifted;
    return x_replaced;
}


int main(void)
{
    unsigned x;
    int i;
    unsigned char b;
    scanf("0x%x %d 0x%hhx", &x, &i, &b);
    while (getchar() != '\n');
    unsigned result = replace_byte(x, i, b);
    printf("0x%X\n", result);
    return 0;
}


// 2.65
int odd_ones(unsigned x)
{
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}

int main(void)
{
    unsigned x;
    scanf("0x%x", &x);
    printf("%d\n", odd_ones(x));
    return 0;
}


// 2.67
// A. 1<<32 is defined as UB in 32-int 
// B.
int bad_int_size_is_32_B()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
// C.
int bad_int_size_is_32_C()
{
    int set_msb = (1 << 15)<<15;
    set_msb <<= 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
int main(void)
{
    printf("%d\n", bad_int_size_is_32_B());
    printf("%d\n", bad_int_size_is_32_C());
    return 0;
}


// 2.68
#define w 32
#include<limits.h>
int lower_one_mask(int n)
{
    if(n<w)
    {
        return ~(~0U << n);
    }
    return UINT_MAX;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("0x%X\n", lower_one_mask(n));
    return 0;
}