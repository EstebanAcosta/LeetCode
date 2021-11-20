
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".

char * defangIPaddr(char * address)
{
	//get the length of the address
    int addLen = strlen(address);

    //create a separate string with twice of the length of the address
   	//(It can be bigger than that but twice should be sufficient space for the defanged IP address)
    char * defanged = malloc(addLen * 2 * sizeof(char));
    
    //create a counter for the defanged string
    int j = 0;

    //loop through each character in the address
    for(int i = 0 ; i < addLen ; i++)
    {
        if(address[i] != '.') 
        {
        	//store the character in the address string in the defanged string
            defanged[j] = address[i];

            //add one more to the counter
            j++;
        }

        //if the next character in the defanged address isn't a period
        else
        {
        	//add the left and right paren and the period
            defanged[j++] = '[';
            defanged[j++] = '.';
            defanged[j++] = ']';
        }
    }
    
    //add null terminator
    defanged[j] = '\0';
    
    return defanged;
}

int main(int argc, char const *argv[])
{
	char * str = "123.456.787.890";
	printf("%s\n",defangIPaddr(str));
	return 0;
}