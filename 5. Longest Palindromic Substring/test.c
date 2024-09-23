#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char str[] = "test";
    int i = 0;
    
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    return 0;
}
