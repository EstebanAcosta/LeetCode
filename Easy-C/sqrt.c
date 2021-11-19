#include <stdio.h>
#include <math.h>

int mySqrt(int x)
{
    long start = 0, end = x,mid = 0;
    
    while(start <= end)
    {
        mid = (start + end)/2;
        if(mid * mid == x) return mid;
        else if(mid * mid < x) start = mid + 1;
        else end = mid - 1;
    }
    
    return end;
}

int main(int argc, char const *argv[])
{
    long num = 4000;

    long sqrt = mySqrt(num);

    printf("Square root of %ld is %ld",num,sqrt);
    return 0;
}