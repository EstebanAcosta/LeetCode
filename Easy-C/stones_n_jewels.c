#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

// Example 1:

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:

// Input: jewels = "z", stones = "ZZ"
// Output: 0

int numJewelsInStones(char * jewels, char * stones)
{
    int count = 0, stoneLen = strlen(stones);

    while(*jewels != '\0')
    {
        for(int i = 0; i < stoneLen; i++)
            if(stones[i] == *jewels) count++;
        jewels++;
    }
    
    return count;
}

int main(int argc, char const *argv[])
{
    char * jewels = "aBcDeFgHiL";
    char * stones = "hBaCdLizGhImgLhit";
    printf("There are this many jewels in stones %d\n", numJewelsInStones(jewels,stones));
    return 0;
}