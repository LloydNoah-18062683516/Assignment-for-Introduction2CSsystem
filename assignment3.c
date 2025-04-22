// 3.58

// assembly code
// decode2:
//     subq    %rdx,%rsi
//     imulq   %rsi,%rdi
//     movq    %rsi,%rax
//     salq    $63,%rax 
//     sarq    $63,%rax 
//     xorq    %rdi,%rax
//     ret

long decode2(long x,long y,long z) 
{
    y-=z;
    x*=y;
    long res=y;
    res=(res<<63)>>63; // extract sign bit
    res^=x;
    return res;
}

// 3.60

// long loop(long x,int n)
// x in %rdi,n in %esi
// loop:
//     movl    %esi,%ecx
//     movl    $1,%edx
//     movl    $0,%eax
//     jmp     .L2
// .L3:
//     movq    %rdi,%r8
//     andq    %rdx,%r8
//     orq     %r8,%rax
//     salq    %cl,%rdx
// .L2:
//     testq   %rdx,%rdx
//     jne     .L3
//     rep;ret

long loop(long x,int n)
{
    long result=0; // eax: return register   mov1 $0,%eax
    long mask;     // edx: general register   mov1 $1,%edx
    for(mask=1;mask!=0;mask=(mask<<n)) // salq    %cl,%rdx    move n mod 64 bit
    {
        result|=(x&mask);
    }
    return result;
}

// A. x -> %rdi ; n -> %esi ; result -> %eax ; mask -> %edx
// B. result=0
// C. mask!=0
// D. mask<<n
// E. result|=(x&mask)