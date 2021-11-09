#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            if(s[i] == symbols[j]) 
            {
                if(i < strlen(s) - 1 && ((s[i] == 'C' && s[i + 1] == 'M')
                  || (s[i] == 'C' && s[i + 1] == 'D')
                  || (s[i] == 'X' && s[i + 1] == 'C')
                  || (s[i] == 'X' && s[i + 1] == 'L')
                  || (s[i] == 'I' && s[i + 1] == 'X')
                  || (s[i] == 'I' && s[i + 1] == 'V')))
                {
                    sum-=values[j];
                    break;
                }
                sum+=values[j];
                break;
            }        
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int numeral = romanToInt("MMMMIV");

    printf("%d\n",numeral);
    return 0;
}