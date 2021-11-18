#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Given a string s, find the length of the longest substring without repeating characters.
 * @author: Esteban Acosta
 **/

int lengthOfLongestSubstring(char * s)
{
    //create three variables
    //the max will hold the longest substring length
    //count will count each substring length
    //start will be our pointer
    int max = 1,count = 1, start = 1;
    
    //if the string is empty, return 0
    if(strlen(s) == 0) return 0;
    
    //create a stack that has the same size as the parameter string
    char * stack = malloc((strlen(s))*sizeof(char));

    //store the first character of the parameter string in the "stack"
    stack[0] = s[0];

    //store the null terminator at the end (in order to prevent any future issues when looping thru the stack)
    stack[strlen(s) - 1] = '\0';

    //Loop through each character of the string
    for(int i = start; i < strlen(s) ; i++)
    {
        //if this character doesn't exist in the "stack"
        if(strchr(stack,s[i]) == NULL)
        {
            //add this character to the stack
            //add one to counter (this counter is keeping track of the current substring length)
            stack[count++] = s[i];
        }
        //if this character is in the "stack"
        else
        {
            //clear the "stack"
            memset(stack,0,strlen(s)*sizeof(char)); 

            //store the current character in the "stack"
            stack[0] = s[start];

            //reset the substring length to one (the minimum it can ever be is one)
            count = 1;       

            //set i to the start pointer (we're esentially moving the pointer one position to the right), 
            //add one more the start pointer (this will keep track of the leftmost side of the next substring)
            i = start++;     
        } 

        if(count > max) max = count;
    }
    
    return max;
}

int main(int argc, char const *argv[])
{
    char * str = "giannisantetonkoumpo" ;
    printf("Longest substring in the string %s is: %d characters long", str, lengthOfLongestSubstring(str));
    return 0;
}