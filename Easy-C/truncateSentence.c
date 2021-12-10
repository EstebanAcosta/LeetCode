#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
Each of the words consists of only uppercase and lowercase English letters (no punctuation).

For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s and an integer k. You want to truncate s
such that it contains only the first k words. Return s after truncating it.
*/

char * truncateSentence(char * s, int k)
{
  //create a new string
  char * result = malloc((strlen(s) + 1)*sizeof(char));

  //store the length of the original sentence, store the current position in the new string, 
  //keep track of where we are in the original string
  int sLen = strlen(s), count = 0, i = 0;
    
    //go through each character in the original string
    for(; i < sLen; i++)
    {
        //if the character is an empty space and we have stored k words in the new string
        //break out of the loop; we already have the truncated string
        if(s[i] == ' ' && count == k - 1) break;

        //if the character is an empty space and we still haven't copied k number of words into the new string
        else if(s[i] == ' ' && count < k) count++;

        //store the next character of the og string into the new string
        result[i] = s[i];
    }

    result[i] = '\0';
    
    return result;
}

int main(int argc, char const *argv[])
{
  
  char * str = "Abs are not a joke, so if you destroy my personality with this";

  printf("Original String: %s\n", str);

  char * result = truncateSentence(str,5);

  printf("Truncated String: %s\n",result);

  return 0;
}