#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str)
{
    if (str == NULL)
        return;
    char *end = str;
    while(*end)
        end++;
    end--;
    while(str < end) {
        char temp = *str;
        printf("%c\n", temp);
        *str = *end;
        *end = temp;
        str++;end--;
    }
}

bool permutation(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2)
        return false;
    int char_set[256] = {0};
    for(int i =0; i < len1; i++) {
        char_set[*str1++]++;
    }
    for(int i=0; i < len2; i++) {
        if (--char_set[*str2++] < 0)
            return false;
    }
    return true;
}

void replaceSpaces(char *str)
{
    if (str == NULL)
        return;
    char *end = str;
    int spaceNum = 0;int length =0;
    while(*end) {
        if (*end++ == ' ')
            spaceNum++;
        length++;
    }
    int newLength = length + 2*spaceNum ;
    printf("%d\n", newLength);
    printf("%d\n", length);
    for (int i=0; i < length; i++) {
        if (str[--length] == ' ') {
            printf("%c\n", str[length]);
            str[--newLength] = '0';
            str[--newLength] = '2';
            str[--newLength] = '%';
        } else {
            printf("%c\n", str[length]);
            str[--newLength] = str[length];
        }
    }
}

int main()
{
    char str1[20] = "hello s";
    char str2[10];
    str2[2] = '\0';
    str2[1] = '1';
    str2[0] = '0';
    reverse(str1);
    printf("%s\n", str1);
}