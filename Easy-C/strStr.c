// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strStr(char * haystack, char * needle)
{
	//if the needle is an empty string, return 0
    if(strlen(needle) == 0) return 0;
    
    //store the string length for both the needle and the haystack
    int haylen = strlen(haystack), needlen = strlen(needle);

    //go through the haystack
    for(int i = 0; i < haylen; i++)
    {
    	//if the character in the haystack is equal to the first letter of the needle
        if(haystack[i] == needle[0])
        {
            int j = 0;
            
            //loop as many times as there are characters in the needle
            for(j = 0; j < needlen; j++)
            {
            	//if the next character in the haystack isn't equal to the next character
            	//in the needle, break out of the loop
                if(haystack[i + j] != needle[j]) break;
            }
            
            //if we matched each character in that segment of the haystack
            //to every character in the needle. Return the index of when 
            //we started looping through the needle
            if(j == needlen) return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
	char * haystack = "ajackolanternlateehascomethroughthewindowlatee";
	char * needle = "late";

	int posit = strStr(haystack,needle);
	printf("First occurance of the word late in the string is in position %d\n",posit);
	return 0;
}