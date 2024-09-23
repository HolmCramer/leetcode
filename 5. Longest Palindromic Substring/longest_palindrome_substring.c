// Old Try with Pointers goin inwards from outside, obviously wrong

#include <string.h>
#include <stdio.h>

char* longestPalindrome(char* s) {
    char* left_ptr = &s[0];
    char* left_inner_ptr;
    char* right_ptr = &s[strlen(s)-1];
    char* right_inner_ptr;
    int result_length = 1;
    char substring[strlen(s)+1];
    char result_str[strlen(s)];

    while (left_ptr != right_ptr && *left_ptr != *right_ptr)
    {
        printf("left_ptr: %c\t right_ptr: %c\n", *left_ptr, *right_ptr);
        right_ptr--; 
    }

    left_inner_ptr = left_ptr;
    right_inner_ptr = right_ptr;

    printf("left_inner_ptr: %c\t right_inner_ptr: %c\n", *left_inner_ptr, *right_inner_ptr);

    int i = 0;
    while (*left_inner_ptr == *right_inner_ptr && left_inner_ptr != right_inner_ptr)
    {
        substring[i] = *left_inner_ptr;
        substring[i+1] = '\0';
        i++;
        left_inner_ptr++;
        right_inner_ptr--;
    }

    int j = i-1;
    while (j >= 0)
    {
        substring[i] = substring[j];
        substring[i+1] = '\0';
        i++;
        j--; 
    }

    for (int count = 0; count < strlen(substring); count++)
    {
        printf("%c", substring[count]);
    }
    

    return s;
}

int main(int argc, char const *argv[])
{
    char test_str[] = "tesetom";
    longestPalindrome(test_str);
    return 0;
}
