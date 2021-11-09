#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char * s)
{
    char symbols[] = {'I','V','X','L','C','D','M'};
    int values[] = {1,5,10,50,100,500,1000};
    int sum = 0;
    
    for(int i = 0 ; i < strlen(s); i++)
    {
        for(int j = 6; j >= 0; j--)
        {
            if(symbols[j] == s[i]) 
            {
                sum+=values[j];
                break;
            }
        }
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int numeral = romanToInt("III");
    return 0;
}