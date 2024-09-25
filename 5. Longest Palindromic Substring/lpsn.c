// New Try by going with another approach

#include <string.h>
#include <stdio.h>
#include <malloc.h>


int checkForPalindrome(char* s, int start , int end)
{
    char sub_str[strlen(s)+1];
    sub_str[0] = '\0';
    int pal_len = end + 1;
    int sub_len;
    int k = 0;

    while (s[start] == s[end])
    {
        sub_str[k] = s[start];
        sub_str[k+1] = '\0';
        k++;
        if (start == end || end-start == 1)
        {
            sub_len = strlen(sub_str);
            k = 0;

            for (int i = 0; i < sub_len; i++)
            {
                s[i] = sub_str[i];
                s[i+1] = '\0';
                k++;
            }
            
            if (pal_len % 2 != 0 && sub_len > 1 || start == end)
            {
                sub_len = sub_len - 1;
            }

            for (int n = sub_len-1; n >= 0; n--)
            {
                s[k] = sub_str[n];
                s[k+1] = '\0';
                k++;
            }
            return 0;
        }
        start++;
        end--;
    }
    printf("\n");
    return 1; 
}


char* longestPalindrome(char* s)
{
    int counter, i;
    counter = i = 0;
    int j = strlen(s)-1;
    int flag = 1;

    if (!s || !*s)
    {
        return s;
    }
    else
    {
        while (counter <= (int)strlen(s) && (i == 1 && j == 1) != 1 && flag != 0)
        {
            printf("i: %i, j: %i, c: %i\n", i, j, counter);

            flag = checkForPalindrome(s, i, j);

            if (j > (int)strlen(s)-2)
            {
                counter++;
                j-=counter;
                i=0;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
    return s;
}

int main(int argc, char const *argv[])
{
    // char test_str[] = "abcbabcbldkashdolhjasoi";
    //char test_str[] = "abba";
    // char test_str[] = "abcdedcbax";
    //char test_str[] = "babad";
    //char test_str[] = "cbbd";
    //char test_str[] = "babad";
    char test_str[] = "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip";
    //char test_str[] = "SQQSYYSQQS";
    //char test_str[] = "xxssbssx";
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
