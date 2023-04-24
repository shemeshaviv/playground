#include <stdio.h>

void remove_redundant_spaces(char * str)
{
    // Instead of assigning specific pointers, and since we manipulate a string, it can be simpler to use iterators
    // pointing from within the start of the string
    int i = 0;            // Main (current) iteratior
    int j = 0;            // Auxilary iterator
    int seq = 0;          // Amount of continuous (sequence) spaces
    printf(" INPUT: \"%s\"\n", str);

    while(str[i]!='\0')   // While we didn't reach the end of string
    {
        (str[i] == ' ')?  // If the current character is space...
            seq++         // ... Increase the sequence count ...
        :
            seq = 0;      // ... Otherwise, we can reset the sequence count
        
        if(seq < 2)       // If the sequence of spaces is less than two consequent spaces...
        { 
            str[j]=str[i]; // ...We can place the character in the auxilary's position
            j++;           // And keep increasing the auxilary
        }
        i++;               // At any case, we increase the current/main iterator
    }
    str[j] = '\0';         // The current auxilary iterator's location on the string should be resolved with end-of-string
    printf("OUTPUT: \"%s\"\n\n", str);
}

int main()
{
    char str1[] = "This is  a test";
    char str2[] = " Single leading single    space";
    char str3[] = "Extra trailing   spaces     ";
    char str4[] = "    Too  many leading spaces";
    char str5[] = "";                             // Empty string
    char str6[] = "Hope this is ok. Thank you for the opportunity!";
    remove_redundant_spaces(str1);
    remove_redundant_spaces(str2);
    remove_redundant_spaces(str3);
    remove_redundant_spaces(str4);
    remove_redundant_spaces(str5);
    remove_redundant_spaces(str6);
    return 0;
}

/*
 INPUT: "This is  a test"
OUTPUT: "This is a test"

 INPUT: " Single leading single    space"
OUTPUT: " Single leading single space"

 INPUT: "Extra trailing   spaces     "
OUTPUT: "Extra trailing spaces "

 INPUT: "    Too  many leading spaces"
OUTPUT: " Too many leading spaces"

 INPUT: ""
OUTPUT: ""

 INPUT: "Hope this is ok. Thank you for the opportunity!"
OUTPUT: "Hope this is ok. Thank you for the opportunity!"
*/

