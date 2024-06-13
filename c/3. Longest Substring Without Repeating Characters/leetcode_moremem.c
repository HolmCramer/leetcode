#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool in_used_chars(char *used_chars, char comp_char)
{
    int i = 0;

    while (used_chars[i] != '\0')
    {
        if (used_chars[i] == comp_char)
        {
            return true;
        }
        i++;
    }
    return false;
}

void clear_char_array(char *used_chars, int size)
{
    for (int i = 0; i < size; i++)
    {
        used_chars[i] = '\0';
    }
}

int clear_char_array_until_char(char *used_chars, char comp_char)
{
    int i = 0;

    while (used_chars[i] != comp_char)
    {
        i++;
    }
    i++;

    char *temp_used_chars;
    temp_used_chars = malloc(strlen(used_chars) * (sizeof(char*) + 1));

    int counter = 0;

    while (used_chars[i] != '\0')
    {
        temp_used_chars[counter] = used_chars[i];
        counter++;
        i++;
    }
    
    temp_used_chars[counter] = '\0';
    
    counter = 0;

    while (temp_used_chars[counter] != '\0')
    {
        used_chars[counter] = temp_used_chars[counter];
        counter++;
    }
    used_chars[counter] = '\0';

    return (counter);
}

int lengthOfLongestSubstring(char *s)
{
    char *ptr_char = s;
    int result_len = 0;
    int temp_result_len = 0;
    char *used_chars;
    used_chars = malloc(strlen(s) * sizeof(char*) + 1);

    clear_char_array(used_chars,strlen(s));
    
    while (*ptr_char != '\0')
    {
        if (in_used_chars(used_chars, *ptr_char) == true)
        {
            temp_result_len = clear_char_array_until_char(used_chars, *ptr_char);     // has to delete up until the array
        }

        if (in_used_chars(used_chars, *ptr_char) == false)
        {
            printf("ptr_val: %c \n", *ptr_char);
            used_chars[temp_result_len] = *ptr_char;
            used_chars[temp_result_len + 1] = '\0';
        }

        temp_result_len++;
        ptr_char++;

        if (temp_result_len > result_len)
        {
            result_len = temp_result_len;
        }
    }
    return (result_len);
}

int main() 
{
    int result = 0;
    char *str;
    str = (char*)malloc(50000 * sizeof(char*) + 1);
    // str = "aa";
    // str = "yfsrsrpzuya";
    str = "abcabcbb";
    // str = "dvdf";
    char *s = str;
    
    result = lengthOfLongestSubstring(s);

    printf("result: %d \n", result);

    return 0;
}
