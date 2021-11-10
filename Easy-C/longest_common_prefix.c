#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int min_id = 0;
    
    for(int i = 0 ; i < strsSize; i++)
    {
        if(strlen(strs[i]) < strlen(strs[min_id])) min_id = i;
    }
    
    char * common = strs[min_id];
    int commonLen = strlen(common),endLen = 0;
    
    for(int i = 0; i < strsSize; i++)
    {
        if(i != min_id)
        {
          for(int j = 0; j < commonLen; j++)
          {
             if(j == 0 && strs[i][j] != common[j]) return "";
             else if(strs[i][j] == common[j]) endLen++;
             else break;
           }  
            commonLen = endLen;
            endLen = 0;
        }    
    }
    
    char * longest = malloc((commonLen + 1) * sizeof(char));
    
    for(int i = 0 ; i < commonLen; i++)
    {
        longest[i] = common[i];
    }
    
    longest[commonLen] = '\0';
    
    return longest;
}

int main(int argc, char const *argv[])
{
    char * words [] = {"florest","florers","floreda","flore"};

    printf("%s",longestCommonPrefix(words,4));
    return 0;
}