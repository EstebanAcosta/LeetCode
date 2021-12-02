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
	//create two variables: one that stores the length of the input string
	//another one that keeps track of where we are in the new string
    int strLen = strlen(command),count = 0 ;

    //Create a string that has one more than the length of the input string
    char * translated = malloc((strLen + 1)*sizeof(char));

    //go through each character of the string
    for(int i = 0 ; i < strLen; i++)
    {
        if(command[i] == 'G') translated[count++] = 'G';  	//if the character is a G, store the capital G in the new string
        //if we aren't at the end of the string and if the next two characters are ( and )
        else if(i + 1 <= strLen && command[i] == '(' && command[i+1] == ')' )
        {
        	//store an o in the new string and update counter by one to move on to the 
        	//next available space in the new string
            translated[count++] = 'o';

            //since we analyzed two characters in the input string in this step
            //add one more to the for loop counter to move on to the next unread character
            i++;
        }
        //if none of the characters match, then that must mean we are
        //currently at the part of the input string that has '(al)'
        else
        {
        	//store a and l right after the other and update counter twice
            translated[count++] = 'a';
            translated[count++] = 'l';
            //since we analyzed four characters in the input string in this step
            //add three more to the for loop counter to move on to the next unread character
            i+=3;
        }
    }
    
    //add a null terminator to the end of the string
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