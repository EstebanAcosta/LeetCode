#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * restoreString(char * s, int* indices, int indicesSize);

/**
 Given a string s and an integer array indices of the same length.
The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.
 * 
 */

char * restoreString(char * s, int* indices, int indicesSize)
{
	//create a new string
    char * newS = malloc((strlen(s)+1)*sizeof(char));
    
    //go through the indices array
    for(int i = 0; i < indicesSize; i++)
    	/**access the number in the indices array
    	this number represents where we will put this character 
    	in the new string. We are placing the character in this position
    	of the old string into a different position in the new string**/
        newS[indices[i]] = s[i];
    
    //add a null terminator at the end
    newS[indicesSize] = '\0';
    
    return newS;
}

int main()
{
	int size = 7;
	int indices[] = {2,4,1,3,0,6,5};
	char * s = "ajouter";

	printf("Old String: %s\n",s );

	char * newS = restoreString(s,indices,size);

	printf("New String: %s\n",newS);

	return 0;
}
