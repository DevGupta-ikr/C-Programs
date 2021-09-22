
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 200

int Compare(char *s1, char *s2) // Compare Strings
{
   int flag=0;
    while(*s1!='\0' && *s2!='\0')
    {
        if(*s1!=*s2)
        {
            flag = 1;
        }
        s1++;
        s2++;
    }

    if(flag==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void Reverse(char* str) // Reverse Strings
{
    int l, i;
    char *start_ptr, *end_ptr, ch;

    l = strlen(str);

    start_ptr = str;
    end_ptr = str;

    for (i = 0; i < l - 1; i++)
    {
        end_ptr++;
    }

    for (i = 0; i < l / 2; i++)
    {

        ch = *end_ptr;
        *end_ptr = *start_ptr;
        *start_ptr = ch;

        start_ptr++;
        end_ptr--;
    }
}

void Conc(char *s1, char *s2)  // Concatenate Strings
{

    while(*(++s1));

    while(*(s1++) = *(s2++));

}

int main()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    char *s1 = str1;
    char *s2 = str2;

    printf(" Enter first string:  ");
    gets(str1);
    printf(" Enter second string: ");
    gets(str2);

    Reverse(s1);
    printf("\n Reverse = %s ", str1);

    Reverse(s1);
    Conc(s1, s2);

    printf("\n\n Concatenated string = %s", str1);

    int cmp = Compare(str1, str2);

    if(cmp==0)
    {
        printf("\n\n Strings are equal \n");
    }
    else
    {
        printf("\n\n Strings are not equal \n");
    }

    return 0;
}
