#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
You own a Goal Parser that can interpret a string command. 
The command consists of an alphabet of "G", "()" and/or "(al)" in some order.
 The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al".
 The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.

*/

char * interpret(char * command);

char * interpret(char * command)
{
    int strLen = strlen(command),count = 0 ;
    char * translated = malloc((strLen + 1)*sizeof(char));
    printf("%s\n",command);

    for(int i = 0 ; i < strLen; i++)
    {
        if(command[i] == 'G') translated[count++] = 'G';
        else if(i + 1 <= strLen && command[i] == '(' && command[i+1] == ')' )
        {
            translated[count++] = 'o';
            i++;
        }
        else
        {
            translated[count++] = 'a';
            translated[count++] = 'l';
            i+=3;
        }
    }
    
    translated[count] = '\0';
    
    return translated;
}

int main(int argc, char const *argv[])
{
	char * command = "G()(al)()()()()(al)GG";

	char * interpreted = interpret(command);

	printf("Original String: %s\tTranslated String: %s\n",command,interpreted);

	return 0;
}