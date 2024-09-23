// New Try with Pointers going form inside to outside after finding 

#include <string.h>
#include <stdio.h>


int test(char* s, char* resultStr)
{
    char* left_ptr = &s[0];
    char* left_inner_ptr;
    char* right_ptr = &s[1];
    char* right_inner_ptr;
    char substr[strlen(s)];
    int i = 0;
    int j = 0;
    int k = 0;
    int n = 0;
    int count = 0;

    for (int i=0; i < strlen(s)-1; i++)
    {
        for (int j=0; j < 2; j++)
        {
            if (*left_ptr == *right_ptr)
            {
                left_inner_ptr = left_ptr;
                right_inner_ptr = right_ptr;
                
                if (j == 0)
                {
                    substr[0] = s[i+1];
                    substr[1] = '\0';
                    k = 1;
                }
                else
                {
                    k = 0;
                }

                printf("test\0");
                printf("lip: %c rip: %c\n", *left_inner_ptr, *right_inner_ptr);
            
                while (*left_inner_ptr == *right_inner_ptr && left_inner_ptr >= s && *right_inner_ptr != '\0')
                {
                    substr[k] = *left_inner_ptr;
                    //printf("%c", substr[i]);
                    substr[k+1] = '\0';
                    k++;
                    left_inner_ptr--;
                    right_inner_ptr++;
                }
            }

            if (j == 0)
            {
                right_ptr++;
            }

            k = 0;
            
            count = strlen(substr);

            if (count*2-j > strlen(resultStr))
            {
                for (n = count-j; n > 0; n--)
                {
                    resultStr[k] = substr[n];
                    resultStr[k+1] = '\0';
                    k++;
                }
                
                for (n = 0; n < count; n++)
                {
                    resultStr[k] = substr[n];
                    resultStr[k+1] = '\0';
                    k++;
                }
            }
        }
        left_ptr++;
    }
}


char* longestPalindrome(char* s)
{
    char* resultStr;
    char* longestEvenResStr = lookForEvenPalindrome(s, longestEvenResStr);
    char* longestUnevenResStr = lookForUnevenPalindrome(s, longestUnevenResStr);

    s = strlen(longestEvenResStr) > strlen(longestUnevenResStr) ? longestEvenResStr : longestUnevenResStr;

    return 0;
}

int main(int argc, char const *argv[])
{
    char test_str[] = "lkliaskugdioasdfdadasauasgdiougsalkisdughfixdjyasudhiuhaohtesetholm";
    char result[strlen(test_str)];
    result[0] = '\0';
    char* result_ptr = result;
    //char* test_ptr = &test_ptr[0];
    //longestPalindrome(test_str);
    //lookForUnevenPalindrome(test_str, result_ptr);
    test(test_str, result_ptr);

    // int i = 0;
    // while (test_str[i] != '\0')
    // {
    //     printf("%c", test_str[i]);
    //     i++;
    // }

    int i = 0;
    while (result[i] != '\0')
    {
        printf("%c", result[i]);
        i++;
    }

    return 0;
}
