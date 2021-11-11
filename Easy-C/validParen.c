#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

bool isValid(char * s)
{   
    if(strlen(s) % 2 != 0) return false;
    
    char * stack = malloc((strlen(s) + 1 ) * sizeof(char));
    
    int stackPosit = 0, strPosit = 0;
    
    while(strPosit < strlen(s))
    {
        if(s[strPosit] == '(' || s[strPosit] == '[' || s[strPosit] == '{' ) 
        {
            stack[stackPosit] = s[strPosit];  
            stackPosit++;
        }
        else if(stackPosit == 0) return false;
        else 
        {
           while(stackPosit > 0)
           {
                 if((stack[stackPosit - 1] == '(' && s[strPosit] == ')')
                    || (stack[stackPosit - 1] == '{' && s[strPosit] == '}') 
                    || (stack[stackPosit - 1] == '[' && s[strPosit] == ']'))
                 {
                    if(stackPosit > 1) strPosit++;
                    stack[stackPosit-1] = ' ';
                    stackPosit--; 
                 }
                 else if(s[strPosit] == '{' || s[strPosit] == '[' || s[strPosit] == '(')
                 {
                     strPosit--;
                     break;
                 }
                 else return false;
            }
        }
        strPosit++;
    }
    
    free(stack);

    return stackPosit == 0;
}

int main(int argc, char const *argv[])
{
    char * s = "{[}]";
    if(isValid(s) == 0) printf("false");
    else printf("true");


    return 0;
}