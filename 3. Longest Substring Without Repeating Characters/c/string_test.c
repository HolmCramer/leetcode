#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
char *str_ptr;
str_ptr = (char*)malloc(256 * sizeof(char*) + 1);

//str_ptr = "Holm Cramer\0";
str_ptr = " H";

printf("Name: %c", str_ptr);

return 0;
}