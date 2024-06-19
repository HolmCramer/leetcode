#include <stdio.h>
#include <stdbool.h>

bool in_used_chars(char used_chars[], int comp_char)
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

int size_of_char_array(char *s)
{
    int i = 0;

    while (*s != '\0')
    {
        s++;
        i++;
    }
    
    return i;
}

int lengthOfLongestSubstring(char *s) 
{
    char *ptr_char = s;
    int result_len = 0;
    int temp_result_len = 0;
    char used_chars[sizeof(s)];

    clear_char_array(used_chars,size_of_char_array(s));
    
    while (*ptr_char != '\0')
    {

        printf("ptrpos: %c \n", *ptr_char);
        
        if (in_used_chars(used_chars, *ptr_char) == true)
        {
            if (temp_result_len > result_len)
            {
                result_len = temp_result_len;
            }
            clear_char_array(used_chars,size_of_char_array(s));
            temp_result_len = 0;
        }
        if (in_used_chars(used_chars, *ptr_char) == false)
        {
            used_chars[temp_result_len] = *ptr_char;
            temp_result_len++;
        }
        ptr_char++;
    }

    return (result_len);
}

int main() 
{
    int result = 0;
    char str[] = "wadehasd";
    char *s = str;
    
    result = lengthOfLongestSubstring(s);

    printf("result: %d", result);

    return 0;
}
