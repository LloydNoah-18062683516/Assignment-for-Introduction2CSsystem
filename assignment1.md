# <center><font face ="Assignment1" color=orange>Assignment1</font> 
## <center><font face="楷体" size=5> LI JIAJIN 2024211330
### 2.60
```
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = 0xFF << (i * 8);
    unsigned b_shifted = b << (i * 8);
    unsigned x_cleared = x & (~mask);
    unsigned x_replaced = x_cleared | b_shifted;
    return x_replaced;
}
```
- ==*~mask*== :  used to set target bytes as *0*
- ==*b_shifted*== : target replacement
- 1 Byte = 8 bits
- main as follows
```
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
```
***
### 2.66
```
int odd_ones(unsigned x)
{
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}
```
- excellent method!
- compress information of 32 into the last bit of x
- information of the first 31 bit is messy but reserved
- use of *^* (XOR) 
- main as follows
```
int main(void)
{
    unsigned x;
    scanf("0x%x", &x);
    printf("%d\n", odd_ones(x));
    return 0;
}
```
***
### 2.67
# A. 
- ~~1 << 32~~ is defined **UB** (undefined behavior) in 32-int
# B.
```
int bad_int_size_is_32_B()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
```
# C.
```
int bad_int_size_is_32_C()
{
    int set_msb = (1 << 15)<<15;
    set_msb <<= 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
```
- we just don't allow occurence of '32' in 32-int & '16' in 16-int,but they actually work the same
- main as follows
```
int main(void)
{
    printf("%d\n", bad_int_size_is_32_B());
    printf("%d\n", bad_int_size_is_32_C());
    return 0;
}
```
***
### 2.68
- header files you need
`#define w 32`
`#include<limits.h>`
```
int lower_one_mask(int n)
{
    if(n<w)
    {
        return ~(~0U << n);
    }
    return UINT_MAX;
}
```
- ==*0U*== : 0x00000000
- ==*UINT_MAX*== : 0xFFFFFFFF
- n==w needs special treated
- main as follows
```
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("0x%X\n", lower_one_mask(n));
    return 0;
}
```
***
