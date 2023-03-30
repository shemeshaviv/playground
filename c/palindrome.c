#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBinaryPalindrome(unsigned int num)
{
    unsigned int lsb = 0x00000001;
    unsigned int msb = 0x80000000;
    while (lsb!=msb)
    {
        if( ((num & msb) == 0 && (num & lsb)==0) || 
            ((num & msb) > 0 && (num & lsb)>0))
        {
            lsb = lsb << 1;
            msb = msb >> 1;
        }
        else
            return false;
    }
    return true;
}

int main() {
    unsigned int nums[] = {0xF000000F, 0x12345678, 0x000A5000};
    int i;
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
        if(isBinaryPalindrome(nums[i]))
            printf("0x%8X is Binary-Palindrome\n", nums[i]);
        else 
            printf("0x%8X is NOT Binary-Palindrome\n",nums[i]);
    return 0;
}

