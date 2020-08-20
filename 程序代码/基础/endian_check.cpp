#include <stdio.h>

union
{
    char ch;
    int i;
}un;

int main(void)
{
    un.i = 0x12345678;
    if(un.ch == 0x12)
    {
        printf("big endian\n");
    }
    else if(un.ch == 0x78)
    {
        printf("small endain\n");
    }
    return 0;
}