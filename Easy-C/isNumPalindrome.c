#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPalindrome(int x)
{     
    if(x < 0) return false;
    else if(x >= 0 && x < 10) return true;
    
    int digLen = floor(log10(x) + 1), posit = 0; 
    int split[digLen]; 
    
    while(x != 0)
    {
        split[posit] = x % 10;
        x/=10;
        posit++;
    }
    
    int j = digLen - 1;
    
    for(int i = 0 ; i < digLen/2; i++ )
    {
        if(split[i] != split[j]) return false;
        j--;
    }   
    return true;
}

int main(int argc, char const *argv[])
{
    bool confirm = isPalindrome(13431);

    printf("%d\n",confirm );

    return 0;
}