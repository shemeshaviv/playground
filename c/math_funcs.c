#include <stdio.h>

int absolute(int x)
{
    int result = x;
    if(x<0) x = x * (-1);
    return x;
}

int greatest_common_divisor(int u, int v)
{
    int tmp = 0;
    while(v != 0)
    {
        tmp = u % v;
        u = v;
        v = tmp;
    }
    return u;
}
int main()
{
    int gcd = greatest_common_divisor(150, 35);
    printf("Greatest common divisor of 150 and 35 is: %d\n", gcd);
    int abs = absolute(-7);
    printf("The absolute value of -7 is: %d\n", abs);
    return 0;
}
