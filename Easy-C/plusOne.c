#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    returnSize = malloc((digitsSize+1)*sizeof(int));
     
    for(int i = digitsSize - 1; i >= 0; i--)
    {
        if(i == digitsSize - 1)
        {
            if(digits[i] + 1 >= 10 )
            {
                
            }
            else returnSize[i] = digits[i] + 1;
        }
        else returnSize[i] = digits[i];
    }
    
    return returnSize;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}