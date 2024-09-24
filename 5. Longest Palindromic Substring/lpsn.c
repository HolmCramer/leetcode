// New Try by going with another approach

#include <string.h>
#include <stdio.h>
#include <malloc.h>


char* longestPalindromeOld(char* s)
{
    char result_str[strlen(s)+1];
    result_str[0] = '\0';
    char sub_str[strlen(s)+1];
    sub_str[0] = '\0';
    int k = 0;
    int sub_len = 0;
    int res_len = 0;

    if (strlen(s) == 0)
    {
        result_str[0] = '\0';
    }
    else if (strlen(s) == 1)
    {
        result_str[0] = s[0];
        result_str[1] = '\0';
    }
    else 
    {
        char* left_ptr = &s[0];
        char* left_inner_ptr;
        char* right_ptr = &s[1];
        char* right_inner_ptr;

        for (int i=0; i < strlen(s)-1; i++)
        {
            for (int j=0; j < 2; j++)
            {
                if (*left_ptr == *right_ptr)
                {
                    left_inner_ptr = left_ptr;
                    right_inner_ptr = right_ptr;
                    
                    if (j == 1)
                    {
                        sub_str[0] = s[i+1];
                        sub_str[1] = '\0';
                        k = 1;
                    }
                    else
                    {
                        sub_str[0] = '\0';
                        k = 0;
                    }
                
                    while (*left_inner_ptr == *right_inner_ptr && *right_inner_ptr != '\0')
                    {
                        sub_str[k] = *left_inner_ptr;
                        sub_str[k+1] = '\0';
                        k++;
                        right_inner_ptr++;
                        if (left_inner_ptr == s)
                        {
                            break;
                        }
                        else 
                        {
                            left_inner_ptr--;
                        }
                    }
                }
                else if (strlen(result_str) == 0)
                {
                    result_str[i] = s[i];
                    result_str[i+1] = '\0';
                }

                if (j == 0 && i < strlen(s)-1)
                {
                    right_ptr++;
                }

                k = 0;
                
                sub_len = strlen(sub_str);
                res_len = strlen(result_str);

                if (sub_len*2-j > res_len)
                {
                    for (int n = sub_len-1; n >= 0; n--)
                    {
                        result_str[k] = sub_str[n];
                        result_str[k+1] = '\0';
                        k++;
                    }
                    
                    for (int n = 0+j; n < sub_len; n++)
                    {
                        result_str[k] = sub_str[n];
                        result_str[k+1] = '\0';
                        k++;
                    }
                }
                sub_str[0] = '\0';
            }
            left_ptr++;
        }
    }

    for (int i = 0; i < strlen(result_str); i++)
    {
        s[i] = result_str[i];
        s[i+1] = '\0';
    }
    
    return s;
}

char* longestPalindrome(char* s)
{
    char result_str[strlen(s)+1];
    result_str[0] = '\0';
    char sub_str[strlen(s)+1];
    sub_str[0] = '\0';
    int k = 0;
    int sub_len = 0;
    int res_len = 0;

    if (!s || !*s)
    {
        return s;
    }
    else
    {
        for (int i = 0; i < strlen(s)-1; i++)
        {
            for (int j = strlen(s); j >= i; j--)
            {
                if (s[i] == s[j])
                {
                    sub_str[k] = s[i];
                    sub_str[k+1] = '\0';
                    k++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // char test_str[] = "abcbabcbldkashdolhjasoi";
    //char test_str[] = "aba";
    //char test_str[] = "abcdedcbaxxx";
    //char test_str[] = "babad";
    //char test_str[] = "cbbd";
    //char test_str[] = "babad";
    char test_str[] = "ac";
    // char result[strlen(test_str)];
    // result[0] = '\0';
    //char* result_ptr = result;
    //char* test_ptr = &test_ptr[0];
    //longestPalindrome(test_str);
    //lookForUnevenPalindrome(test_str, result_ptr);

    char* result;
    result = (char*) malloc(strlen(test_str)*sizeof(char)+1);

    result = longestPalindrome(test_str);
    
    // int i = 0;
    // while (test_str[i] != '\0')
    // {
    //     printf("%c", test_str[i]);
    //     i++;
    // }

    int i = 0;
    printf("result: ");
    while (result[i] != '\0')
    {
        printf("%c", result[i]);
        i++;
    }
    printf("\n");

    return 0;
}