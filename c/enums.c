#include <stdio.h>
#include <stdlib.h>

enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };

int main(int argc, char* argv[])
{
    enum Company company1 = XEROX;
    enum Company company2 = GOOGLE;
    enum Company company3 = EBAY;
    printf("XEROX item: %d\n", company1);
    printf("GOOGLE item: %d\n", company2);
    printf("EBAY item: %d\n", company3);

    switch(company1)
    {
        case XEROX:
            printf("company1 is XEROX\n");
            break;
        case GOOGLE:
            printf("company1 is GOOGLE\n");
            break;
        case EBAY:
            printf("company1 is EBAY\n");
            break;
        default:
            printf("company1 is not XEROX or GOOGLE or EBAY\n");
            break;
    }
    return 0;
}
